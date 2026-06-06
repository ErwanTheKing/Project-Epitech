/*
** EPITECH PROJECT, 2026
** wolf3d
** File description:
** Monster pathfinding (BFS) and AI movement
*/

#include "../../include/wolf3d.h"
#include <math.h>
#include <string.h>

static void bfs_init(bfs_t *b, sfVector2i *src)
{
    memset(b->visited, 0, sizeof(b->visited));
    memset(b->from_x, -1, sizeof(b->from_x));
    memset(b->from_y, -1, sizeof(b->from_y));
    b->head = 0;
    b->tail = 0;
    b->visited[src->y][src->x] = 1;
    b->qx[b->tail] = src->x;
    b->qy[b->tail] = src->y;
    b->tail++;
}

static void bfs_visit(bfs_t *b, wall_t *wall, sfVector2i *cur)
{
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int nx;
    int ny;

    for (int i = 0; i < 4; i++) {
        nx = cur->x + dx[i];
        ny = cur->y + dy[i];
        if (nx < 0 || nx >= MAP_WIDTH || ny < 0 || ny >= MAP_HEIGHT)
            continue;
        if (b->visited[ny][nx] || wall->map[ny][nx] != 0)
            continue;
        b->visited[ny][nx] = 1;
        b->from_x[ny][nx] = cur->x;
        b->from_y[ny][nx] = cur->y;
        b->qx[b->tail] = nx;
        b->qy[b->tail] = ny;
        b->tail++;
    }
}

static sfVector2i bfs_run(bfs_t *b, wall_t *wall,
    sfVector2i *src, sfVector2i *dst)
{
    sfVector2i cur = {-1, -1};

    if (src->x == dst->x && src->y == dst->y)
        return (sfVector2i){-1, -1};
    bfs_init(b, src);
    while (b->head < b->tail && cur.x < 0) {
        cur.x = b->qx[b->head];
        cur.y = b->qy[b->head];
        b->head++;
        if (cur.x != dst->x || cur.y != dst->y) {
            bfs_visit(b, wall, &cur);
            cur.x = -1;
        }
    }
    if (cur.x < 0)
        return (sfVector2i){-1, -1};
    while (b->from_x[cur.y][cur.x] != src->x
        || b->from_y[cur.y][cur.x] != src->y)
        cur = (sfVector2i){b->from_x[cur.y][cur.x], b->from_y[cur.y][cur.x]};
    return cur;
}

static sfVector2i get_intercept_tile(wall_t *wall, player_t *player)
{
    float tx;
    float ty;
    int ix;
    int iy;
    float dist;

    for (dist = MONSTER_INTERCEPT; dist >= 1.0f; dist -= 1.0f) {
        tx = player->x + cosf(player->angle) * dist;
        ty = player->y + sinf(player->angle) * dist;
        ix = (int)tx;
        iy = (int)ty;
        if (ix >= 0 && ix < MAP_WIDTH && iy >= 0 && iy < MAP_HEIGHT
            && wall->map[iy][ix] == 0)
            return (sfVector2i){ix, iy};
    }
    return (sfVector2i){(int)player->x, (int)player->y};
}

static void update_waypoint(wolf_t *wolf, player_t *monster, player_t *player)
{
    bfs_t b;
    sfVector2i src;
    sfVector2i dst;
    sfVector2i next;

    src.x = (int)monster->x;
    src.y = (int)monster->y;
    dst = get_intercept_tile(wolf->game->wall, player);
    next = bfs_run(&b, wolf->game->wall, &src, &dst);
    if (next.x < 0)
        return;
    monster->path_target_x = next.x + 0.5f;
    monster->path_target_y = next.y + 0.5f;
}

static void maybe_update_waypoint(wolf_t *wolf, player_t *m, player_t *player)
{
    sfVector2i intercept;
    float tdx;
    float tdy;
    float drift_x;
    float drift_y;

    tdx = m->path_target_x - m->x;
    tdy = m->path_target_y - m->y;
    intercept = get_intercept_tile(wolf->game->wall, player);
    drift_x = m->path_target_x - (intercept.x + 0.5f);
    drift_y = m->path_target_y - (intercept.y + 0.5f);
    if (sqrtf(tdx * tdx + tdy * tdy) < MONSTER_WAYPOINT_REACH
        || sqrtf(drift_x * drift_x + drift_y * drift_y)
        > MONSTER_INTERCEPT_DRIFT)
        update_waypoint(wolf, m, player);
}

static sfVector2f get_move_dir(player_t *monster, float dt)
{
    float tdx;
    float tdy;
    float tdist;
    sfVector2f move;

    tdx = monster->path_target_x - monster->x;
    tdy = monster->path_target_y - monster->y;
    tdist = sqrtf(tdx * tdx + tdy * tdy);
    move.x = 0;
    move.y = 0;
    if (tdist < 0.001f)
        return move;
    move.x = (tdx / tdist) * MONSTER_SPEED * dt;
    move.y = (tdy / tdist) * MONSTER_SPEED * dt;
    return move;
}

static void apply_move(wolf_t *wolf, player_t *m, sfVector2f *move)
{
    if (!check_collision(wolf->game->wall, m->x + move->x, m->y))
        m->x += move->x;
    if (!check_collision(wolf->game->wall, m->x, m->y + move->y))
        m->y += move->y;
}

static void move_monster(wolf_t *wolf, player_t *monster, player_t *player)
{
    float dt;
    float ddx;
    float ddy;
    float dist;
    sfVector2f move;

    dt = sfClock_getElapsedTime(monster->ai_clock).microseconds / 1000000.0f;
    sfClock_restart(monster->ai_clock);
    if (dt > MONSTER_DT_MAX)
        dt = MONSTER_DT_MAX;
    ddx = player->x - monster->x;
    ddy = player->y - monster->y;
    dist = sqrtf(ddx * ddx + ddy * ddy);
    if (dist > MONSTER_AGGRO_RANGE)
        return;
    if (dist <= MONSTER_ATTACK_RANGE)
        return;
    maybe_update_waypoint(wolf, monster, player);
    move = get_move_dir(monster, dt);
    apply_move(wolf, monster, &move);
}

void update_monsters(wolf_t *wolf, player_t *player)
{
    player_t *monster;
    player_t *target;

    if (wolf->connected && !network_is_host(wolf))
        return;
    for (list_t *curr = wolf->list[GAME][MONSTER]; curr; curr = curr->next) {
        monster = (player_t *)curr->data;
        target = get_nearest_enemy(wolf, monster, player);
        if (monster->alive && target)
            move_monster(wolf, monster, target);
    }
}

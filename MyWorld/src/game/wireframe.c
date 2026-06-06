/*
** EPITECH PROJECT, 2026
** wireframe.c
** File description:
** wireframe for the base of the My_World.
*/
#include "../../lib/my/headers/myworld.h"
#include <math.h>

sfVector2f project_iso_point(int x, int y, float z, map_t *map)
{
    sfVector2f point_2d;

    point_2d.x = (cos(map->angle_x) * x - cos(map->angle_x) * y) * map->zoom;
    point_2d.y = (sin(map->angle_y) * y +
        sin(map->angle_y) * x - z) * map->zoom;
    point_2d.x += map->offset.x;
    point_2d.y += map->offset.y;
    return (point_2d);
}

static sfVertex get_vertex(sfVector2f *p, float tex_x, float tex_y)
{
    sfVertex v;

    v.position = *p;
    v.color = sfWhite;
    v.texCoords = (sfVector2f){tex_x, tex_y};
    return v;
}

sfVertexArray *create_quad(sfVector2f *p1, sfVector2f *p2,
    sfVector2f *p3, sfVector2f *p4)
{
    sfVertexArray *corner_board = sfVertexArray_create();

    sfVertexArray_append(corner_board, get_vertex(p1, 0, 0));
    sfVertexArray_append(corner_board, get_vertex(p2, 100, 0));
    sfVertexArray_append(corner_board, get_vertex(p3, 100, 100));
    sfVertexArray_append(corner_board, get_vertex(p4, 0, 100));
    sfVertexArray_setPrimitiveType(corner_board, sfQuads);
    return corner_board;
}

static const sfTexture *get_biome_texture(float avg_z, map_t *map)
{
    if (avg_z <= -0.001)
        return map->underground.texture;
    if (avg_z >= 1.0)
        return map->mountain.texture;
    return map->ground.texture;
}

static float get_avg_z(map_t *map, int x, int y)
{
    return (map->points[y][x].z + map->points[y + 1][x].z +
        map->points[y + 1][x + 1].z + map->points[y][x + 1].z) / 4.0;
}

static void draw_quad(sfRenderWindow *window, map_t *map, int y)
{
    sfVertexArray *quad;
    sfVector2f p[4];
    sfRenderStates states;

    states.blendMode = sfBlendAlpha;
    states.transform = sfTransform_Identity;
    states.texture = map->ground.texture;
    states.shader = NULL;
    for (int x = 0; x < map->width - 1; x++) {
        p[0] = project_iso_point(x, y, map->points[y][x].z, map);
        p[1] = project_iso_point(x + 1, y, map->points[y][x + 1].z, map);
        p[2] = project_iso_point(x + 1, y + 1, map->points[y + 1][x + 1].z,
            map);
        p[3] = project_iso_point(x, y + 1, map->points[y + 1][x].z, map);
        quad = create_quad(&p[0], &p[1], &p[2], &p[3]);
        states.texture = get_biome_texture(get_avg_z(map, x, y), map);
        sfRenderWindow_drawVertexArray(window, quad, &states);
        sfVertexArray_destroy(quad);
    }
}

void draw_map(sfRenderWindow *window, map_t *map)
{
    for (int y = 0; y < map->height - 1; y++)
        draw_quad(window, map, y);
}

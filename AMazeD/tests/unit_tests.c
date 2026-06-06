/*
** EPITECH PROJECT, 2026
** unit_tests.c
** File description:
** unit_tests for the amazed
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/maze.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(new_robot, basic_initialization)
{
    nodes_t *node = new_robot(42);
    robot_t *robot;

    cr_assert_not_null(node, "Le noeud ne doit pas être NULL");
    cr_assert_not_null(node->data, "Les données du robot ne doivent "
        "pas être NULL");

    robot = (robot_t *)node->data;
    cr_assert_eq(robot->id, 42, "L'ID du robot devrait être 42");
    cr_assert_eq(robot->x, 0, "X devrait être initialisé à 0");
    cr_assert_eq(robot->y, 0, "Y devrait être initialisé à 0");
    cr_assert_null(robot->position, "La position de base doit être NULL");
}

Test(create_robot, multiple_robots)
{
    mazed_t maze;
    int result;
    robot_t *r1;

    maze.robot = NULL;
    result = create_robot(&maze, 3);

    cr_assert_eq(result, 0, "create_robot doit retourner 0 en cas de succès");
    cr_assert_not_null(maze.robot, "La liste de robots ne doit pas être vide");

    r1 = (robot_t *)maze.robot->data;
    cr_assert_eq(r1->id, 1, "Le premier robot de la liste devrait "
        "avoir l'ID 1");
}

Test(create_robot, zero_robots)
{
    mazed_t maze;
    int result;

    maze.robot = NULL;
    result = create_robot(&maze, 0);

    cr_assert_eq(result, 84, "create_robot doit retourner 84 si le "
        "nombre est 0");
}

Test(free_all, empty_maze)
{
    mazed_t *maze = malloc(sizeof(mazed_t));
    int exit_code;

    maze->argv = NULL;
    maze->robot = NULL;
    maze->all_links = NULL;
    maze->start = NULL;
    maze->end = NULL;

    exit_code = free_all(maze, 0);

    cr_assert_eq(exit_code, 0, "free_all doit propager le code de "
        "retour (0 ici)");
}

Test(free_all, maze_with_return_84)
{
    mazed_t *maze = malloc(sizeof(mazed_t));
    int exit_code;

    maze->argv = NULL;
    maze->robot = NULL;
    maze->all_links = NULL;
    maze->start = NULL;
    maze->end = NULL;

    exit_code = free_all(maze, 84);

    cr_assert_eq(exit_code, 84, "free_all doit propager le code de "
        "retour (84 ici)");
}

Test(start_end, null_link)
{
    mazed_t maze;
    int result;

    result = start_end(&maze, NULL);
    cr_assert_eq(result, 1, "start_end doit retourner 1 si le lien est NULL");
}

Test(start_end, already_viewed_link)
{
    mazed_t maze;
    link_t link;
    int result;

    link.viewed = 1;
    result = start_end(&maze, &link);

    cr_assert_eq(result, 1, "start_end doit retourner 1 si le lien "
        "est déjà visité (viewed == 1)");
}

Test(right_link, valid_link_format)
{
    char *argv[] = {"RoomA", "RoomB", NULL};
    int result = right_link(argv);

    cr_assert_eq(result, 0, "right_link doit retourner 0 pour un tableau "
        "de taille 2");
}

Test(right_link, invalid_link_format)
{
    char *argv[] = {"RoomA", "RoomB", "RoomC", NULL};
    int result = right_link(argv);

    cr_assert_eq(result, 84, "right_link doit retourner 84 pour un tableau "
        "de taille différente de 2");
}

Test(display_robot, simple_display, .init = redirect_all_stdout)
{
    robot_t robot;
    link_t room;
    mazed_t maze;
    nodes_t dummy_node;

    room.data = "Salle2";
    robot.id = 1;
    robot.position = &room;

    maze.robot = &dummy_node;

    display_robot(&robot, &maze, &dummy_node);

    cr_assert_stdout_eq_str("P1-Salle2", "L'affichage du mouvement du robot "
        "est incorrect");
}

Test(free_all_void, empty_maze_void_return)
{
    mazed_t *maze = malloc(sizeof(mazed_t));
    char *expected_return = "EXIT_PTR";
    void *res;

    maze->argv = NULL;
    maze->robot = NULL;
    maze->all_links = NULL;
    maze->start = NULL;
    maze->end = NULL;

    res = free_all_void(maze, expected_return);

    cr_assert_eq(res, expected_return, "free_all_void doit retourner le "
        "pointeur passé en paramètre");
}

Test(search_node, find_existing_node)
{
    link_t link_a = {.data = "RoomA", .next = NULL};
    link_t link_b = {.data = "RoomB", .next = NULL};
    nodes_t node_b = {.data = &link_b, .next = NULL};
    nodes_t node_a = {.data = &link_a, .next = &node_b};
    link_t *res;

    res = search_node(&node_a, "RoomB");
    cr_assert_not_null(res, "search_node devrait trouver RoomB");
    cr_assert_str_eq((char *)res->data, "RoomB", "Les données du noeud "
        "trouvé sont incorrectes");
}

Test(search_node, node_not_found)
{
    link_t link_a = {.data = "RoomA", .next = NULL};
    nodes_t node_a = {.data = &link_a, .next = NULL};
    link_t *res;

    res = search_node(&node_a, "RoomZ");
    cr_assert_null(res, "search_node devrait retourner NULL si la "
        "salle n'existe pas");
}

Test(search_node, empty_list)
{
    link_t *res = search_node(NULL, "RoomA");
    cr_assert_null(res, "search_node devrait retourner NULL sur une "
        "liste vide");
}

Test(link_node, missing_nodes)
{
    mazed_t maze = {0};
    link_t link_a = {.data = "RoomA", .next = NULL};
    nodes_t node_a = {.data = &link_a, .next = NULL};
    char *argv[] = {"RoomA", "RoomB", NULL};
    int result;

    maze.all_links = &node_a;
    result = link_node(&maze, argv);
    cr_assert_eq(result, 84, "link_node doit retourner 84 si un des "
        "noeuds n'est pas trouvé");
}

Test(good_path, missing_start_or_end)
{
    mazed_t maze = {0};
    int result;

    maze.start = NULL;
    maze.end = malloc(sizeof(link_t));

    result = good_path(&maze);
    cr_assert_eq(result, 84, "good_path doit retourner 84 si start ou "
        "end est NULL");
    free(maze.end);
}

Test(push_queue, node_already_has_height)
{
    nodes_t *q_head = NULL;
    nodes_t *q_tail = NULL;
    link_t cur = {.height = 1};
    link_t nb = {.height = 2};

    push_queue(&q_head, &q_tail, &nb, &cur);

    cr_assert_null(q_head, "push_queue ne doit rien ajouter si la hauteur "
        "est déjà définie (!= -1)");
}

Test(delete_end_robot, robot_arrived_at_end)
{
    mazed_t maze = {0};
    link_t end_room = {.data = "End"};
    robot_t *robot;
    nodes_t *robot_node;

    maze.end = &end_room;

    robot = malloc(sizeof(robot_t));
    robot->id = 1;
    robot->position = maze.end;

    robot_node = malloc(sizeof(nodes_t));
    robot_node->data = robot;
    robot_node->next = NULL;

    maze.robot = robot_node;

    delete_end_robot(&maze);

    cr_assert_null(maze.robot, "Le robot aurait dû être supprimé car il "
        "est sur la case end");
}

Test(delete_end_robot, robot_not_at_end)
{
    mazed_t maze = {0};
    link_t end_room = {.data = "End"};
    link_t current_room = {.data = "RoomA"};
    robot_t robot = {.id = 1, .position = &current_room};
    nodes_t robot_node = {.data = &robot, .next = NULL};

    maze.end = &end_room;
    maze.robot = &robot_node;

    delete_end_robot(&maze);

    cr_assert_not_null(maze.robot, "Le robot ne doit pas être supprimé "
        "s'il n'est pas sur end");
    cr_assert_eq(((robot_t *)maze.robot->data)->id, 1, "Les données du "
        "robot doivent être intactes");
}

Test(robot, invalid_robot_parsing)
{
    mazed_t maze = {0};
    int scene = 0;
    char *data[] = {"not_a_number", NULL};
    nodes_t node = {.data = data, .next = NULL};
    int result;

    result = robot(&maze, &node, &scene);
    cr_assert_eq(result, 84, "La fonction robot doit renvoyer 84 si "
        "l'argument n'est pas un nombre");
}

Test(robot, invalid_robot_parsing_null_node)
{
    mazed_t maze = {0};
    int scene = 0;
    int result;

    result = robot(&maze, NULL, &scene);
    cr_assert_eq(result, 84, "La fonction robot doit renvoyer 84 si "
        "le noeud est NULL");
}

Test(parsing, basic_84_return)
{
    mazed_t maze = {0};
    char *bad_data[] = {"not_a_number", NULL};
    nodes_t bad_node = {.data = bad_data, .next = NULL};
    int result;

    result = parsing(&maze, &bad_node);

    cr_assert_eq(result, 84, "parsing doit retourner 84 si une fonction "
        "d'état renvoie 84");
}

Test(linked, null_node_or_data)
{
    mazed_t maze = {0};
    int scene = 2;
    nodes_t bad_node = {.data = NULL, .next = NULL};

    linked(&maze, &bad_node, &scene);
}

Test(linked, invalid_link_format_return_6)
{
    mazed_t maze = {0};
    int scene = 2;
    char *raw_data[] = {"RoomA-RoomB-RoomC", NULL};
    nodes_t node = {.data = raw_data, .next = NULL};
    int result;

    result = linked(&maze, &node, &scene);

    cr_assert_eq(result, 6, "linked doit retourner 6 si le format du "
        "lien est invalide (fin des liens valides)");
}

Test(linked, my_strtwa_fail)
{
    mazed_t maze = {0};
    int scene = 2;
    char *raw_data[] = {"", NULL};
    nodes_t node = {.data = raw_data, .next = NULL};
    int result;

    result = linked(&maze, &node, &scene);

    cr_assert(result == 84 || result == 6, "linked doit gérer "
        "correctement une chaîne vide");
}

Test(room, transition_to_link_missing_start_end)
{
    mazed_t maze = {0};
    int scene = 1;
    char *link_data[] = {"RoomA-RoomB", NULL};
    nodes_t node = {.data = link_data, .next = NULL};
    int result;

    maze.start = NULL;
    maze.end = NULL;

    result = room(&maze, &node, &scene);

    cr_assert_eq(result, 84, "La transition vers LINK doit échouer "
        "(84) s'il manque le start ou le end");
}

Test(room, double_start_declaration)
{
    mazed_t maze = {0};
    int scene = 1;
    link_t existing_start = {.data = "OldStart"};
    char *cmd_data[] = {"##start", NULL};
    char *room_data[] = {"NewStart", "0", "0", NULL};
    nodes_t node_room = {.data = room_data, .next = NULL};
    nodes_t node_cmd = {.data = cmd_data, .next = &node_room};
    int result;

    maze.start = &existing_start;

    result = room(&maze, &node_cmd, &scene);

    cr_assert_eq(result, 84, "Déclarer un ##start quand un existe "
        "déjà doit retourner 84");
}

Test(room, double_end_declaration)
{
    mazed_t maze = {0};
    int scene = 1;
    link_t existing_end = {.data = "OldEnd"};
    char *cmd_data[] = {"##end", NULL};
    char *room_data[] = {"NewEnd", "1", "1", NULL};
    nodes_t node_room = {.data = room_data, .next = NULL};
    nodes_t node_cmd = {.data = cmd_data, .next = &node_room};
    int result;

    maze.end = &existing_end;

    result = room(&maze, &node_cmd, &scene);

    cr_assert_eq(result, 84, "Déclarer un ##end quand un existe "
        "déjà doit retourner 84");
}

Test(room, room_already_exists)
{
    mazed_t maze = {0};
    int scene = 1;
    link_t existing_room = {.data = "RoomA"};
    nodes_t node_existing = {.data = &existing_room, .next = NULL};
    char *room_data[] = {"RoomA", "10", "10", NULL};
    nodes_t node_new = {.data = room_data, .next = NULL};
    int result;

    maze.all_links = &node_existing;

    result = room(&maze, &node_new, &scene);

    cr_assert_eq(result, 84, "Ajouter une salle avec un nom existant "
        "doit retourner 84");
}

Test(do_height, null_parameters)
{
    mazed_t maze = {0};
    link_t link = {0};

    do_height(&maze, NULL);
    cr_assert(true);

    do_height(NULL, &link);
    cr_assert(true);
}

Test(start_end, valid_path_found)
{
    mazed_t maze = {0};
    link_t end_room = {.data = "End", .viewed = 0, .next = NULL};
    link_t room_a = {.data = "RoomA", .viewed = 0, .next = NULL};
    link_t start_room = {.data = "Start", .viewed = 0, .next = NULL};
    nodes_t edge_to_end = {.data = &end_room, .next = NULL};
    nodes_t edge_to_a = {.data = &room_a, .next = NULL};
    int result;

    maze.end = &end_room;
    room_a.next = &edge_to_end;
    start_room.next = &edge_to_a;

    result = start_end(&maze, &start_room);

    cr_assert_eq(result, 0, "start_end doit retourner 0 si un chemin "
        "vers la fin est trouvé");
    cr_assert_eq(start_room.viewed, 0, "L'état viewed du start doit "
        "être réinitialisé à 0");
}

Test(start_end, no_path_found)
{
    mazed_t maze = {0};
    link_t end_room = {.data = "End", .viewed = 0, .next = NULL};
    link_t start_room = {.data = "Start", .viewed = 0, .next = NULL};
    int result;

    maze.end = &end_room;

    result = start_end(&maze, &start_room);

    cr_assert_eq(result, 84, "start_end doit retourner 84 si aucun chemin "
        "n'est trouvé");
}

Test(good_choice, robot_blocked)
{
    mazed_t maze = {0};
    link_t start_room = {
        .data = "Start", .height = 10, .occuped = false, .next = NULL
    };
    link_t neighbor = {
        .data = "Neighbor", .height = 9, .occuped = true, .next = NULL
    };
    nodes_t edge = {.data = &neighbor, .next = NULL};
    robot_t robot = {.id = 1, .position = &start_room};
    link_t *choice;

    start_room.next = &edge;
    maze.start = &start_room;

    choice = good_choice(&maze, &robot);

    cr_assert_eq(choice, &start_room, "Le robot doit rester sur sa case "
        "s'il n'y a pas de choix valide");
}

Test(parsing, break_on_return_6)
{
    mazed_t maze = {0};
    int scene = 2;
    char *link_data[] = {"Bad-Link-Format", NULL};
    nodes_t node2 = {.data = link_data, .next = NULL};
    char *robot_data[] = {"1", NULL};
    nodes_t node1 = {.data = robot_data, .next = &node2};
    int result;

    result = parsing(&maze, &node1);
    cr_assert(result == 0 || result == 84, "Le parsing devrait gérer la "
        "transition ou s'arrêter");
}

Test(room, valid_room_addition)
{
    mazed_t maze = {0};
    int scene = 1;
    char *room_data[] = {"ValidRoom", "15", "25", NULL};
    nodes_t node = {.data = room_data, .next = NULL};
    int result;
    link_t *added;

    result = room(&maze, &node, &scene);

    cr_assert_eq(result, 0, "L'ajout d'une salle valide doit renvoyer 0");
    cr_assert_not_null(maze.all_links, "La salle devrait être dans all_links");

    added = (link_t *)maze.all_links->data;
    cr_assert_str_eq(added->data, "ValidRoom", "Le nom de la salle "
        "ajoutée est incorrect");
    cr_assert_eq(added->x, 15, "La coordonnée X est incorrecte");
    cr_assert_eq(added->y, 25, "La coordonnée Y est incorrecte");
}

Test(room, transition_to_link_success)
{
    mazed_t maze = {0};
    int scene = 1;
    char *link_data[] = {"RoomA-RoomB", NULL};
    nodes_t node = {.data = link_data, .next = NULL};
    int result;

    maze.start = malloc(sizeof(link_t));
    maze.end = malloc(sizeof(link_t));

    result = room(&maze, &node, &scene);

    cr_assert_eq(result, 2, "La transition doit renvoyer 2 si start "
        "et end existent");
    cr_assert_eq(scene, 2, "La scène doit être mise à jour sur LINK (2)");

    free(maze.start);
    free(maze.end);
}

Test(right_link, empty_array)
{
    char *argv[] = {NULL};
    int result = right_link(argv);

    cr_assert_eq(result, 84, "right_link doit retourner 84 pour un "
        "tableau vide");
}

Test(link_node, success_linking)
{
    mazed_t maze = {0};
    link_t link_a = {.data = "RoomA", .next = NULL};
    link_t link_b = {.data = "RoomB", .next = NULL};
    nodes_t node_b = {.data = &link_b, .next = NULL};
    nodes_t node_a = {.data = &link_a, .next = &node_b};
    char *argv[] = {"RoomA", "RoomB", NULL};
    int result;
    link_t *conn_from_a;

    maze.all_links = &node_a;

    result = link_node(&maze, argv);

    cr_assert_eq(result, 0, "link_node doit renvoyer 0 en cas de succès");

    cr_assert_not_null(link_a.next, "RoomA devrait avoir une connexion");
    cr_assert_not_null(link_b.next, "RoomB devrait avoir une connexion");

    conn_from_a = (link_t *)link_a.next->data;
    cr_assert_str_eq(conn_from_a->data, "RoomB", "RoomA devrait être "
        "connectée à RoomB");
}

Test(good_choice, valid_move_to_neighbor)
{
    mazed_t maze = {0};
    link_t current_room = {
        .data = "Current", .height = 5, .occuped = false, .next = NULL
    };
    link_t neighbor_room = {
        .data = "Neighbor", .height = 4, .occuped = false, .next = NULL
    };
    nodes_t edge = {.data = &neighbor_room, .next = NULL};
    robot_t robot = {.id = 1, .position = &current_room};
    link_t *choice;

    current_room.next = &edge;

    choice = good_choice(&maze, &robot);

    cr_assert_eq(choice, &neighbor_room, "Le robot devrait choisir "
        "le voisin avec une hauteur inférieure");
    cr_assert_eq(neighbor_room.occuped, true, "La nouvelle salle devrait "
        "être marquée comme occupée");
}

Test(good_choice, choice_from_start_dispatch)
{
    mazed_t maze = {0};
    link_t start_room = {
        .data = "Start", .height = 10, .occuped = true, .next = NULL
    };
    link_t path1 = {
        .data = "Path1", .height = 9, .occuped = false, .next = NULL
    };
    link_t path2 = {
        .data = "Path2", .height = 9, .occuped = false, .next = NULL
    };
    nodes_t edge2 = {.data = &path2, .next = NULL};
    nodes_t edge1 = {.data = &path1, .next = &edge2};
    robot_t robot1 = {.id = 1, .position = &start_room};
    link_t *choice1;
    robot_t robot2 = {.id = 2, .position = &start_room};
    link_t *choice2;

    start_room.next = &edge1;
    maze.start = &start_room;

    choice1 = good_choice(&maze, &robot1);
    cr_assert(choice1 == &path1 || choice1 == &path2, "Le robot 1 "
        "doit prendre un des chemins libres");

    choice1->occuped = true;

    choice2 = good_choice(&maze, &robot2);
    cr_assert(choice2 != choice1 && (choice2 == &path1 || choice2 == &path2),
        "Le robot 2 doit prendre le deuxième chemin disponible");
}

Test(robot_choice, full_execution, .init = redirect_all_stdout)
{
    mazed_t maze = {0};
    link_t start_room = {
        .data = "Start", .height = 2, .occuped = true, .next = NULL
    };
    link_t next_room = {
        .data = "Next", .height = 1, .occuped = false, .next = NULL
    };
    link_t end_room = {
        .data = "End", .height = 0, .occuped = false, .next = NULL
    };
    nodes_t edge_next = {.data = &next_room, .next = NULL};
    robot_t robot = {.id = 1, .position = &start_room};
    nodes_t robot_node = {.data = &robot, .next = NULL};
    int result;

    maze.start = &start_room;
    maze.end = &end_room;

    start_room.next = &edge_next;
    maze.robot = &robot_node;

    result = robot_choice(&maze);

    cr_assert_eq(result, 0, "robot_choice doit renvoyer 0");
    cr_assert_eq(robot.position, &next_room, "Le robot aurait dû "
        "avancer à Next");
}

Test(do_height, basic_queue_logic)
{
    mazed_t maze = {0};
    link_t room_end = {.data = "End", .height = -1, .next = NULL};
    link_t room_prev = {.data = "Prev", .height = -1, .next = NULL};
    nodes_t edge = {.data = &room_prev, .next = NULL};

    room_end.next = &edge;

    do_height(&maze, &room_end);

    cr_assert_eq(room_end.height, 0, "La case d'arrivée doit avoir "
        "une hauteur de 0");
    cr_assert_eq(room_prev.height, 1, "La case adjacente à l'arrivée "
        "doit avoir une hauteur de 1");
}

Test(robot, valid_parsing_and_scene_change, .init = redirect_all_stdout)
{
    mazed_t maze = {0};
    int scene = 0;
    char *data[] = {"5", NULL};
    nodes_t node = {.data = data, .next = NULL};
    int result;
    robot_t *first_robot;

    result = robot(&maze, &node, &scene);

    cr_assert_eq(result, 0, "robot doit retourner 0 pour un nombre valide");
    cr_assert_eq(scene, 1, "La scène doit passer à ROOM (1)");
    cr_assert_not_null(maze.robot, "La liste des robots doit avoir été "
        "créée");

    first_robot = (robot_t *)maze.robot->data;
    cr_assert_eq(first_robot->id, 1, "Le premier robot de la liste "
        "devrait avoir l'ID 1");
}

Test(room, format_too_many_args)
{
    mazed_t maze = {0};
    int scene = 1;
    char *data[] = {"RoomName", "10", "20", "30", NULL};
    nodes_t node = {.data = data, .next = NULL};
    int result;

    result = room(&maze, &node, &scene);

    cr_assert_eq(result, 84, "Une salle avec trop d'arguments doit "
        "renvoyer 84");
}

Test(linked, valid_linking_execution, .init = redirect_all_stdout)
{
    mazed_t maze = {0};
    int scene = 2;
    link_t room_a = {.data = "RoomA", .next = NULL};
    link_t room_b = {.data = "RoomB", .next = NULL};
    nodes_t node_b = {.data = &room_b, .next = NULL};
    nodes_t node_a = {.data = &room_a, .next = &node_b};
    char *data[] = {"RoomA-RoomB", NULL};
    nodes_t node = {.data = data, .next = NULL};
    int result;

    maze.all_links = &node_a;

    result = linked(&maze, &node, &scene);

    cr_assert_eq(result, 0, "linked doit retourner 0 si la liaison réussit");
    cr_assert_not_null(room_a.next, "RoomA doit avoir une nouvelle connexion");
    cr_assert_not_null(room_b.next, "RoomB doit avoir une nouvelle connexion");
}

Test(good_path, successful_path_initialization, .init = redirect_all_stdout)
{
    mazed_t maze = {0};
    link_t end_room = {
        .data = "End", .height = -1, .viewed = 0, .next = NULL
    };
    link_t start_room = {
        .data = "Start", .height = -1, .viewed = 0, .next = NULL
    };
    nodes_t edge_to_end = {.data = &end_room, .next = NULL};
    nodes_t edge_to_start = {.data = &start_room, .next = NULL};
    robot_t r1 = {.id = 1, .position = NULL};
    nodes_t nr = {.data = &r1, .next = NULL};
    int result;

    maze.end = &end_room;
    maze.start = &start_room;

    start_room.next = &edge_to_end;
    end_room.next = &edge_to_start;

    maze.robot = &nr;

    result = good_path(&maze);

    cr_assert_eq(result, 0, "good_path doit retourner 0 pour un labyrinthe "
        "valide");
    cr_assert_eq(r1.position, &start_room, "Le robot doit être placé "
        "sur la case Start");
    cr_assert_eq(end_room.height, 0, "La case d'arrivée doit avoir sa "
        "hauteur fixée à 0");
}

Test(good_choice, ignores_occupied_optimal_path)
{
    mazed_t maze = {0};
    link_t start = {
        .data = "Start", .height = 10, .occuped = false, .next = NULL
    };
    link_t optimal_but_full = {
        .data = "PathA", .height = 5, .occuped = true, .next = NULL
    };
    link_t sub_optimal_free = {
        .data = "PathB", .height = 8, .occuped = false, .next = NULL
    };
    nodes_t edge1 = {.data = &optimal_but_full, .next = NULL};
    nodes_t edge2 = {.data = &sub_optimal_free, .next = &edge1};
    robot_t robot = {.id = 1, .position = &start};
    link_t *choice;

    start.next = &edge2;

    choice = good_choice(&maze, &robot);

    cr_assert_eq(choice, &sub_optimal_free, "Le robot doit choisir le "
        "chemin libre même s'il est sous-optimal");
}

Test(delete_end_robot, middle_robot_removal)
{
    mazed_t maze = {0};
    link_t start = {.data = "Start"};
    link_t end = {.data = "End"};
    robot_t *r1;
    robot_t *r2;
    robot_t *r3;
    nodes_t *n3;
    nodes_t *n2;
    nodes_t *n1;

    maze.end = &end;

    r1 = malloc(sizeof(robot_t));
    r1->id = 1;
    r1->position = &start;

    r2 = malloc(sizeof(robot_t));
    r2->id = 2;
    r2->position = &end;

    r3 = malloc(sizeof(robot_t));
    r3->id = 3;
    r3->position = &start;

    n3 = malloc(sizeof(nodes_t));
    n3->data = r3;
    n3->next = NULL;

    n2 = malloc(sizeof(nodes_t));
    n2->data = r2;
    n2->next = n3;

    n1 = malloc(sizeof(nodes_t));
    n1->data = r1;
    n1->next = n2;

    maze.robot = n1;

    delete_end_robot(&maze);

    cr_assert_not_null(maze.robot, "La liste ne doit pas être vide");
    cr_assert_eq(((robot_t *)maze.robot->data)->id, 1, "Le premier robot "
        "doit toujours être r1");
    cr_assert_not_null(maze.robot->next, "Le noeud suivant ne doit pas "
        "être NULL");
    cr_assert_eq(((robot_t *)maze.robot->next->data)->id, 3, "Le deuxième "
        "noeud doit maintenant être r3 (r2 supprimé)");
}

Test(take_argument, simulate_stdin, .init = cr_redirect_stdin)
{
    FILE *f_in = cr_get_redirected_stdin();
    nodes_t *res;

    fprintf(f_in, "5\n##start\n0 0\n##end\n1 1\n");
    fclose(f_in);

    res = take_argument();

    cr_assert_not_null(res, "take_argument devrait renvoyer une liste "
        "chaînée non vide après avoir lu stdin");

    free_nodes(res, free_array_void);
}

Test(take_argument, skip_comments, .init = cr_redirect_stdin)
{
    FILE *f_in = cr_get_redirected_stdin();
    nodes_t *res;
    char **first_data;

    fprintf(f_in, "# ceci est un simple commentaire\n##start\n0 0\n");
    fclose(f_in);

    res = take_argument();

    cr_assert_not_null(res, "La liste ne doit pas être NULL");

    first_data = (char **)res->data;
    cr_assert_str_eq(first_data[0], "##start", "Les commentaires simples "
        "doivent être ignorés");

    free_nodes(res, free_array_void);
}

Test(amaze, full_invalid_execution, .init = cr_redirect_stdin)
{
    FILE *f_in = cr_get_redirected_stdin();
    int res;

    fprintf(f_in, "GARBAGE_DATA_NOT_A_ROBOT\n");
    fclose(f_in);

    res = amaze();

    cr_assert_eq(res, 84, "amaze() doit renvoyer 84 si le parsing "
        "global échoue");
}

Test(good_choice, no_valid_path_from_start)
{
    mazed_t maze = {0};
    link_t start = {
        .data = "Start", .height = 10, .occuped = false, .next = NULL
    };
    link_t dead_end = {
        .data = "Dead", .height = -1, .occuped = false, .next = NULL
    };
    nodes_t edge = {.data = &dead_end, .next = NULL};
    robot_t robot = {.id = 1, .position = &start};
    link_t *choice;

    start.next = &edge;
    maze.start = &start;

    choice = good_choice(&maze, &robot);

    cr_assert_eq(choice, &start, "Le robot ne doit pas bouger s'il n'y a "
        "que des chemins inaccessibles (-1)");
}

Test(room, start_without_next_node, .init = redirect_all_stdout)
{
    mazed_t maze = {0};
    int scene = 1;
    char *data[] = {"##start", NULL};
    nodes_t node = {.data = data, .next = NULL};
    int res;

    res = room(&maze, &node, &scene);

    cr_assert_eq(res, 84, "Une déclaration ##start sans coordonnées "
        "derrière doit renvoyer 84");
}

Test(room, end_without_next_node, .init = redirect_all_stdout)
{
    mazed_t maze = {0};
    int scene = 1;
    char *data[] = {"##end", NULL};
    nodes_t node = {.data = data, .next = NULL};
    int res;

    res = room(&maze, &node, &scene);

    cr_assert_eq(res, 84, "Une déclaration ##end sans coordonnées "
        "derrière doit renvoyer 84");
}

Test(link_node, link_same_room)
{
    mazed_t maze = {0};
    link_t room = {.data = "A", .next = NULL};
    nodes_t node = {.data = &room, .next = NULL};
    char *argv[] = {"A", "A", NULL};
    int res;

    maze.all_links = &node;
    res = link_node(&maze, argv);

    cr_assert_null(room.next, "Une salle ne doit pas pouvoir se"
        " lier à elle-même");
}

Test(free_links, basic_execution)
{
    link_t *link = malloc(sizeof(link_t));

    link->data = NULL;
    link->next = NULL;

    free_links(link);
    cr_assert(true, "free_links ne doit pas crash sur un lien basique");
}

Test(robot, multiple_args_in_data)
{
    mazed_t maze = {0};
    int scene = 0;
    char *data[] = {"5", "extra_arg", NULL};
    nodes_t node = {.data = data, .next = NULL};
    int result;

    result = robot(&maze, &node, &scene);

    cr_assert_eq(result, 84, "robot() doit renvoyer 84 s'il y a plus "
        "d'un argument sur la ligne");
}

Test(room, start_followed_by_invalid_room, .init = redirect_all_stdout)
{
    mazed_t maze = {0};
    int scene = 1;
    char *bad_room[] = {"RoomName", "A", "B", NULL};
    nodes_t node_room = {.data = bad_room, .next = NULL};
    char *start_cmd[] = {"##start", NULL};
    nodes_t node_cmd = {.data = start_cmd, .next = &node_room};
    int result;

    result = room(&maze, &node_cmd, &scene);

    cr_assert_eq(result, 84, "Une commande ##start suivie d'une salle "
        "invalide doit renvoyer 84");
}

Test(room, end_followed_by_invalid_room, .init = redirect_all_stdout)
{
    mazed_t maze = {0};
    int scene = 1;
    char *bad_room[] = {"RoomName", "X", "Y", NULL};
    nodes_t node_room = {.data = bad_room, .next = NULL};
    char *end_cmd[] = {"##end", NULL};
    nodes_t node_cmd = {.data = end_cmd, .next = &node_room};
    int result;

    result = room(&maze, &node_cmd, &scene);

    cr_assert_eq(result, 84, "Une commande ##end suivie d'une salle "
        "invalide doit renvoyer 84");
}

Test(right_link, array_length_one)
{
    char *argv[] = {"RoomA", NULL};
    int result = right_link(argv);

    cr_assert_eq(result, 84, "right_link doit retourner 84 si le "
        "tableau contient 1 seul élément");
}

Test(good_path, start_and_end_disconnected)
{
    mazed_t maze = {0};
    link_t end_room = {.data = "End", .viewed = 0, .next = NULL};
    link_t start_room = {.data = "Start", .viewed = 0, .next = NULL};
    int result;

    maze.start = &start_room;
    maze.end = &end_room;

    result = good_path(&maze);

    cr_assert_eq(result, 84, "good_path doit renvoyer 84 si aucun chemin "
        "n'est possible entre start et end");
}

Test(push_queue, append_to_existing_queue)
{
    nodes_t *q_head = malloc(sizeof(nodes_t));
    nodes_t *q_tail = q_head;
    link_t dummy_in_queue = {.height = 0};
    link_t cur = {.height = 1};
    link_t nb = {.height = -1};

    q_head->data = &dummy_in_queue;
    q_head->next = NULL;

    push_queue(&q_head, &q_tail, &nb, &cur);

    cr_assert_neq(q_head, q_tail, "La tête et la queue ne doivent plus "
        "pointer sur le même élément");
    cr_assert_not_null(q_head->next, "Le premier élément de la file "
        "doit pointer vers le nouveau");
    cr_assert_eq(q_head->next, q_tail, "Le 'next' de l'ancienne queue "
        "doit être la nouvelle queue");
    cr_assert_eq(nb.height, 2, "La hauteur doit être bien assignée");

    free(q_head->next);
    free(q_head);
}

Test(display_robot, display_second_robot, .init = redirect_all_stdout)
{
    mazed_t maze = {0};
    link_t room = {.data = "RoomA"};
    robot_t r1 = {.id = 1, .position = &room};
    robot_t r2 = {.id = 2, .position = &room};
    nodes_t n2 = {.data = &r2, .next = NULL};
    nodes_t n1 = {.data = &r1, .next = &n2};

    maze.robot = &n1;

    display_robot(&r2, &maze, &n2);

    cr_assert_stdout_eq_str(" P2-RoomA", "Un robot qui n'est pas le premier "
        "doit être précédé d'un espace");
}

Test(take_argument, empty_stdin, .init = cr_redirect_stdin)
{
    FILE *f_in = cr_get_redirected_stdin();
    nodes_t *res;

    fclose(f_in);

    res = take_argument();

    cr_assert_null(res, "take_argument doit renvoyer NULL si l'entrée "
        "standard est vide");
}

Test(free_links, multiple_adjacent_links)
{
    link_t *main_link = malloc(sizeof(link_t));
    nodes_t *adj1 = malloc(sizeof(nodes_t));
    nodes_t *adj2 = malloc(sizeof(nodes_t));

    adj1->data = malloc(1);
    adj2->data = malloc(1);

    adj1->next = adj2;
    adj2->next = NULL;
    main_link->next = adj1;

    free_links(main_link);
    cr_assert(true, "free_links doit réussir à libérer une liste "
        "d'adjacence complexe sans crash");
}

Test(free_nodes, null_head)
{
    free_nodes(NULL, free);
    cr_assert(true, "free_nodes ne doit pas crash si head est NULL");
}

Test(parsing, null_argv)
{
    mazed_t maze = {0};
    int result;

    result = parsing(&maze, NULL);

    cr_assert_eq(result, 0, "parsing doit renvoyer 0 immédiatement "
        "si argv est NULL");
}

Test(start_end, cycle_no_infinite_loop)
{
    mazed_t maze = {0};
    link_t end_room = {.data = "End", .viewed = 0, .next = NULL};
    link_t room_a = {.data = "RoomA", .viewed = 0, .next = NULL};
    link_t room_b = {.data = "RoomB", .viewed = 0, .next = NULL};
    nodes_t edge_to_b = {.data = &room_b, .next = NULL};
    nodes_t edge_to_a = {.data = &room_a, .next = NULL};
    int result;

    maze.end = &end_room;

    room_a.next = &edge_to_b;
    room_b.next = &edge_to_a;

    result = start_end(&maze, &room_a);

    cr_assert_eq(result, 84, "start_end doit détecter l'impasse sans "
        "tomber dans une boucle infinie");
}

Test(good_choice, start_all_paths_occupied)
{
    mazed_t maze = {0};
    link_t start = {
        .data = "Start", .height = 10, .occuped = true, .next = NULL
    };
    link_t path1 = {
        .data = "Path1", .height = 9, .occuped = true, .next = NULL
    };
    nodes_t edge = {.data = &path1, .next = NULL};
    robot_t robot = {.id = 1, .position = &start};
    link_t *choice;

    start.next = &edge;
    maze.start = &start;

    choice = good_choice(&maze, &robot);

    cr_assert_eq(choice, &start, "Si tous les chemins depuis Start "
        "sont occupés, le robot doit patienter (renvoyer cur)");
}

Test(room, transition_missing_only_end)
{
    mazed_t maze = {0};
    int scene = 1;
    char *link_data[] = {"RoomA-RoomB", NULL};
    nodes_t node = {.data = link_data, .next = NULL};
    int result;

    maze.start = malloc(sizeof(link_t));
    maze.end = NULL;

    result = room(&maze, &node, &scene);

    cr_assert_eq(result, 84, "La transition vers les liens doit échouer "
        "si maze->start existe mais maze->end est NULL");

    free(maze.start);
}

Test(take_argument, only_comments, .init = cr_redirect_stdin)
{
    FILE *f_in = cr_get_redirected_stdin();
    nodes_t *res;

    fprintf(f_in, "# Labyrinthe vide\n# C'est un test\n# "
        "number_of_robots est manquant\n");
    fclose(f_in);

    res = take_argument();

    cr_assert_null(res, "take_argument doit renvoyer NULL si le fichier "
        "ne contient que des commentaires inutiles");
}

Test(init, fail_on_parsing, .init = cr_redirect_stdin)
{
    FILE *f_in = cr_get_redirected_stdin();
    mazed_t *maze_ptr;

    fprintf(f_in, "donnée_invalide\n");
    fclose(f_in);

    maze_ptr = init();

    cr_assert_null(maze_ptr, "init() doit renvoyer NULL si le parsing "
        "échoue après la lecture des arguments");
}

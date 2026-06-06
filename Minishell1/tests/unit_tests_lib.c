/*
** EPITECH PROJECT, 2025
** mini_printf
** File description:
** unit_tests
*/

#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"
#include "../include/linked_lists.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//region  lib's tests

//region my_compute_power_rec's tests

Test (my_compute_power_rec, negative_numbers, .init = redirect_all_std)
{
    const int a  = my_compute_power_rec(15, -6);
    cr_assert_eq(a, 0);
}

//endregion

//region my_compute_square_root's tests

Test (my_compute_square_root, basics_false, .init = redirect_all_std)
{
    const int a  = my_compute_square_root(5);
    cr_assert_eq(a, 0);
}

Test (my_compute_square_root, basics_true, .init = redirect_all_std)
{
    const int a  = my_compute_square_root(4);
    cr_assert_eq(a, 2);
}

Test (my_compute_square_root, neagtive, .init = redirect_all_std)
{
    const int a  = my_compute_square_root(-12);
    cr_assert_eq(a, 0);
}

//endregion

//region my_find_prime_sup's tests

Test (my_find_prime_supp, basic, .init = redirect_all_std)
{
    const int a  = my_find_prime_sup(6);
    cr_assert_eq(a, 7);
}

Test (my_find_prime_supp, basic_1, .init = redirect_all_std)
{
    const int a  = my_find_prime_sup(1);
    cr_assert_eq(a, 2);
}

//endregion

//region my_get_nbr's tests

Test (my_get_nbr, basic, .init = redirect_all_std)
{
    const int a  = my_getnbr("12");
    cr_assert_eq(a, 12);
}

Test (my_get_nbr, basic_neg, .init = redirect_all_std)
{
    const int a  = my_getnbr("-12");
    cr_assert_eq(a, -12);
}

Test (my_get_nbr, basic_min_int, .init = redirect_all_std)
{
    const int a  = my_getnbr("5464686131687665");
    cr_assert_eq(a, 0);
}

//endregion

//region my_is_neg's tests

Test(my_isneg, negatif, .init = redirect_all_std)
{
    my_isneg(-12);
    cr_assert_stdout_eq_str("N\n");
}

Test(my_isneg, positif, .init = redirect_all_std)
{
    my_isneg(12);
    cr_assert_stdout_eq_str("P\n");
}

//endregion

//region my_put_nbr_base's tests

Test(my_put_nbr_base, basic, .init = redirect_all_std)
{
    my_putnbr_base(12, "012");
    cr_assert_stdout_eq_str("110");
}

Test(my_put_nbr_base, negatif, .init = redirect_all_std)
{
    my_putnbr_base(-26, "0123456789abcdef");
    cr_assert_stdout_eq_str("1a");
}


//endregion

//region my_revstr's tests

Test(my_revstr, basic, .init = redirect_all_std)
{
    char str[6] = "Hello";

    my_revstr(str);
    cr_assert_str_eq(str, "olleH");
}

//endregion

//region my_is_prime's tests

Test(my_is_prime, basic, .init = redirect_all_std)
{
    int a = my_is_prime(1);
    cr_assert_eq(a, 0);
}

//endregion

//region my_str_isalpha's tests

Test(my_str_isalpha, basic, .init = redirect_all_std)
{
    int a = my_str_isalpha("Hello");
    cr_assert_eq(a, 1);
}

Test(my_str_isalpha, false, .init = redirect_all_std)
{
    int a = my_str_isalpha("5Hello");
    cr_assert_eq(a, 0);
}

//endregion

//region my_str_islower's tests

Test(my_str_islower, basic, .init = redirect_all_std)
{
    int a = my_str_islower("hello");
    cr_assert_eq(a, 1);
}

Test(my_str_islower, false, .init = redirect_all_std)
{
    int a = my_str_islower("Hello");
    cr_assert_eq(a, 0);
}

//endregion

//region my_str_isnum's tests

Test(my_str_isnum, basic, .init = redirect_all_std)
{
    int a = my_str_isnum("123");
    cr_assert_eq(a, 1);
}

Test(my_str_isnum, false, .init = redirect_all_std)
{
    int a = my_str_isnum("5Hello");
    cr_assert_eq(a, 0);
}

//endregion

//region my_str_isprintable's tests

Test(my_str_isprintable, basic, .init = redirect_all_std)
{
    int a = my_str_isprintable("Hello");
    cr_assert_eq(a, 1);
}

Test(my_str_isprintable, false, .init = redirect_all_std)
{
    int a = my_str_isprintable("45\n");
    cr_assert_eq(a, 0);
}

//endregion

//region my_str_isupper's tests

Test(my_str_isupper, basic, .init = redirect_all_std)
{
    int a = my_str_isupper("HELLO");
    cr_assert_eq(a, 1);
}

Test(my_str_isupper, false, .init = redirect_all_std)
{
    int a = my_str_isupper("5Hello");
    cr_assert_eq(a, 0);
}

//endregion

//region my_str_to_word_array's tests

Test(my_str_to_word_array, basic, .init = redirect_all_std)
{
    char **str = my_str_to_word_array("Hello World Bonjour ", " ");
    char *str2[] = {"Hello", "World", "Bonjour"};

    for (int i = 0; str[i] != NULL; i++)
        cr_assert_str_eq(str[i], str2[i]);
}

//endregion

//region my_strcapitalize's tests

Test(my_strcapitalize, basic, .init = redirect_all_std)
{
    char str[12] = "hello world";

    my_strcapitalize(str);
    cr_assert_str_eq(str, "Hello World");
}

//endregion

//region my_strcat's tests

Test(my_strcat, basic, .init = redirect_all_std)
{
    char *str = "hello";
    char *str2 = "world";
    char *new;

    new = my_strconcat(str, str2);
    cr_assert_str_eq(new, "helloworld");
}

Test(my_strcat, one_is_empty, .init = redirect_all_std)
{
    char *str = "";
    char *str2 = "world";
    char *new;

    new = my_strconcat(str, str2);
    cr_assert_str_eq(new, "world");
}

//endregion

//region my_strcmp's tests

Test(my_strcmp, basic, .init = redirect_all_std)
{
    char str[6] = ".hello";
    char str2[6] = ".hello";
    int a = my_strcmp(str, str2);

    cr_assert_eq(a, 0);
}

//endregion

//region my_strdup's tests

Test(my_strdup, basic, .init = redirect_all_std)
{
    char str[6] = "hello";
    char *str2 = my_strdup(str, 0);

    cr_assert_str_eq(str2, "hello");
}

//endregion

//region my_strlowcase's tests

Test(my_strlowcase, basic, .init = redirect_all_std)
{
    char str[6] = "HELLO";

    my_strlowcase(str);
    cr_assert_str_eq(str, "hello");
}

//endregion

//region my_strncat's tests

Test(my_strncat, basic, .init = redirect_all_std)
{
    char str[6] = "hello";
    char str2[6] = "world";

    my_strncat(str, str2, 2);
    cr_assert_str_eq(str, "hellowo");
}

//endregion

//region my_strncmp's tests

Test(my_strncmp, basic, .init = redirect_all_std)
{
    char str[6] = "hello";
    char str2[6] = "hello";
    int a = my_strncmp(str, str2, 2);

    cr_assert_eq(a, 0);
}

Test(my_strncmp, n_egal_zero, .init = redirect_all_std)
{
    char str[6] = "hello";
    char str2[6] = "he";
    int a = my_strncmp(str, str2, 0);

    cr_assert_eq(a, 0);
}

//endregion

//region my_strncpy's tests

Test(my_strncpy, i_inferior_n, .init = redirect_all_std)
{
    char str[6] = "hello";
    char str2[6] = "world";

    my_strncpy(str, str2, 8);
    cr_assert_str_eq(str, "world");
}

//endregion

//region my_strstr's tests

Test(my_strstr, basic, .init = redirect_all_std)
{
    char str[12] = "hello world";
    char str2[3] = "wo";
    char *str3 = my_strstr(str, str2);

    cr_assert_str_eq(str3, "world");
}

Test(my_strstr, false, .init = redirect_all_std)
{
    char str[12] = "hello world";
    char str2[3] = "wx";
    char *str3 = my_strstr(str, str2);

    cr_assert_eq(str3, NULL);
}

//endregion

//region my_strupcase's tests

Test(my_strupcase, basic, .init = redirect_all_std)
{
    char str[6] = "hello";

    my_strupcase(str);
    cr_assert_str_eq(str, "HELLO");
}

//endregion

//region my_swap's tests

Test(my_swap, basic, .init = redirect_all_std)
{
    int a = 5;
    int b = 10;

    my_swap(&a, &b);
    cr_assert_eq(a, 10);
    cr_assert_eq(b, 5);
}

//endregion

//region free_array's tests

Test(free_array, true, .init = redirect_all_std)
{
    char **arr = my_str_to_word_array("toto va a la plage", " ");
    free_array(arr);
    int a = 0;
    cr_assert_eq(a, 0);
}

//endregion

//region my_nbr_to_str's tests

Test(my_nbr_to_str, basic_int, .init = redirect_all_std)
{
    char *str = my_nbr_to_str(1234, 0);

    cr_assert_str_eq(str, "1234.");
}

Test(my_nbr_to_str, with_decimal, .init = redirect_all_std)
{
    char *str = my_nbr_to_str(12.34, 2);

    cr_assert_str_eq(str, "12.34");
}

Test(my_nbr_to_str, zero_case, .init = redirect_all_std)
{
    char *str = my_nbr_to_str(0, 3);

    cr_assert_str_eq(str, ".");
}


//endregion

//region cmp_alpha's tests

Test(cmp_alpha, moves_max_to_to_cmp, .init = redirect_all_std)
{
    char *array[] = {"b", "a", "c"};
    char **res = cmp_alpha(array, 1, 3);

    cr_assert_eq(res, array);
    cr_assert_str_eq(array[1], "c");
    cr_assert_str_eq(array[0], "a");
    cr_assert_str_eq(array[2], "b");
}

Test(cmp_alpha, no_swap_if_already_max, .init = redirect_all_std)
{
    char *array[] = {"z", "b", "a"};
    cmp_alpha(array, 0, 3);

    cr_assert_str_eq(array[0], "z");
    cr_assert_str_eq(array[1], "b");
    cr_assert_str_eq(array[2], "a");
}

Test(cmp_alpha, duplicates, .init = redirect_all_std)
{
    char *array[] = {"aa", "aa", "ab"};
    cmp_alpha(array, 0, 3);

    cr_assert_str_eq(array[0], "ab");
}

//endregion

//region my_array_len's tests

Test(my_array_len, basic_array, .init = redirect_all_std)
{
    char *array[] = {"one", "two", "three", NULL};
    int len = my_array_len(array);

    cr_assert_eq(len, 3);
}

Test(my_array_len, empty_array, .init = redirect_all_std)
{
    char *array[] = {NULL};
    int len = my_array_len(array);

    cr_assert_eq(len, 0);
}

Test(my_array_len, single_element, .init = redirect_all_std)
{
    char *array[] = {"hello", NULL};
    int len = my_array_len(array);

    cr_assert_eq(len, 1);
}

//endregion

//region minimum_int_from_list's tests

Test(minimum_int_from_list, basic, .init = redirect_all_std)
{
    int min = minimum_int_from_list(5, 3, 8, 1, 4);

    cr_assert_eq(min, 1);
}


//endregion

//region sort_word_array's tests

Test(sort_word_array, basic_sort, .init = redirect_all_std)
{
    char *array[] = {"banana", "apple", "cherry", NULL};
    sort_word_array(array);

    cr_assert_str_eq(array[0], "apple");
    cr_assert_str_eq(array[1], "banana");
    cr_assert_str_eq(array[2], "cherry");
}

//endregion

//region Openator's tests

Test(openator, empty_file, .init = redirect_all_std)
{
    char *buffer = openator("tests/testing_empty_file");

    cr_assert_eq(buffer, NULL,
        "openator devrait retourner un pointeur vide");
    cr_assert_stderr_eq_str("FILE IS EMPTY\n",
        "openator devrait afficher 'FILE IS EMPTY' pour un fichier vide");
}

Test(openator, non_existent_file, .init = redirect_all_std)
{
    char *buffer = openator("tests/non_existent_file");

    cr_assert_eq(buffer, NULL,
        "openator devrait retourner un pointeur vide");
    cr_assert_stderr_eq_str("FAILURE IN OPEN : FILE NOT FOUND OR DOESN'T EXIST\n",
        "openator devrait afficher 'FAILURE IN OPEN : FILE NOT FOUND OR DOESN'T EXIST\n' pour un fichier inexistant");
}

Test(openator, okay, .init = redirect_all_std)
{
    char *buffer = openator("tests/testin_hello_file");

    cr_assert_str_eq(buffer, "hello_world",
        "openator devrait lire correctement le contenu du fichier");
    free(buffer);
}

//endregion

//region get_file_size_stat tests

Test(get_file_size_stat, existing_file, .init = redirect_all_std)
{
    off_t size = get_file_size_stat("tests/testin_hello_file");

    cr_assert_eq(size, 11,
        "get_file_size_stat devrait retourner la taille correcte du fichier");
}

Test(get_file_size_stat, non_existent_file, .init = redirect_all_std)
{
    off_t size = get_file_size_stat("tests/non_existent_file");

    cr_assert_eq(size, -84,
        "get_file_size_stat devrait retourner -1 pour un fichier inexistant");
}

//endregion

//region my_char_array_dup's tests

Test(my_char_array_dup, basic, .init = redirect_all_std)
{
    char *original[] = {"Hello", "World", NULL};
    char **duplicate = my_char_array_dup(original);

    cr_assert_not_null(duplicate,
        "my_char_array_dup devrait retourner un pointeur non NULL");

    for (int i = 0; original[i] != NULL; i++) {
        cr_assert_str_eq(duplicate[i], original[i],
            "Les chaînes dupliquées devraient être identiques aux originales");
        cr_assert_neq(duplicate[i], original[i],
            "Les chaînes dupliquées devraient être des copies distinctes");
    }

    free_array(duplicate);
}

//endregion

//region linked_lists's tests

//region free_list's tests

Test(free_list_basic, empty_list)
{
    node_t *head = NULL;

    free_list(&head);

    cr_assert_null(head,
        "Après free_list sur une liste vide, head devrait être NULL.");
}

Test(free_list_basic, single_element_list)
{
    node_t *head = malloc(sizeof(node_t));

    int *testing_value = malloc(sizeof(int));

    cr_assert_not_null(head, "Échec du malloc dans le tests.");

    *testing_value = 42;
    head->data = testing_value;
    head->next = NULL;

    free_list(&head);

    cr_assert_null(head, "Après free_list sur une liste à un élément, head devrait être NULL.");
}

Test(free_list_basic, multiple_elements_list)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));
    node_t *n3 = malloc(sizeof(node_t));

    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    int *data3 = malloc(sizeof(int));

    cr_assert_not_null(data1, "Échec du malloc pour data1.");
    cr_assert_not_null(data2, "Échec du malloc pour data2.");
    cr_assert_not_null(data3, "Échec du malloc pour data3.");

    cr_assert_not_null(n1, "Échec du malloc pour n1.");
    cr_assert_not_null(n2, "Échec du malloc pour n2.");
    cr_assert_not_null(n3, "Échec du malloc pour n3.");

    *data1 = 1;
    *data2 = 2;
    *data3 = 3;

    n1->data = data1;
    n2->data = data2;
    n3->data = data3;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    node_t *head = n1;

    free_list(&head);

    cr_assert_null(head,
        "Après free_list sur une liste à plusieurs éléments, head devrait être NULL.");
}


Test(free_list_basic, head_pointer_itself_is_valid)
{
    node_t *head = NULL;

    free_list(&head);

    cr_assert_null(head, "free_list doit pouvoir gérer un pointeur valide vers un head NULL.");
}

Test(free_list_basic, nodes_with_null_data)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));

    cr_assert_not_null(n1, "Échec du malloc pour n1.");
    cr_assert_not_null(n2, "Échec du malloc pour n2.");

    n1->data = NULL;      // data volontairement NULL
    n2->data = NULL;
    n1->next = n2;
    n2->next = NULL;

    node_t *head = n1;

    free_list(&head);

    cr_assert_null(head,
        "Après free_list sur une liste avec des data NULL, head devrait être NULL.");
}

//endregion

//region get_at's tests

Test(get_at_basic, empty_list_returns_null)
{
    node_t *head = NULL;

    void *res = get_at(head, 0);

    cr_assert_null(res,
        "get_at sur une liste vide doit retourner NULL.");
}

Test(get_at_basic, negative_position_returns_null)
{
    node_t *head = malloc(sizeof(node_t));
    cr_assert_not_null(head);

    int *value = malloc(sizeof(int));
    cr_assert_not_null(value);
    *value = 10;

    head->data = value;
    head->next = NULL;

    void *res = get_at(head, -1);

    cr_assert_null(res,
        "get_at avec position négative doit retourner NULL.");

    free(head->data);
    free(head);
}

Test(get_at_basic, single_element_valid_access)
{
    node_t *head = malloc(sizeof(node_t));
    cr_assert_not_null(head);

    int *value = malloc(sizeof(int));
    cr_assert_not_null(value);
    *value = 42;

    head->data = value;
    head->next = NULL;

    void *res = get_at(head, 0);

    cr_assert_not_null(res,
        "get_at(0) sur une liste à un seul élément doit retourner le data.");
    cr_assert_eq(*(int *)res, 42,
        "La valeur retournée doit correspondre à celle stockée.");

    free(head->data);
    free(head);
}

Test(get_at_basic, single_element_invalid_access)
{
    node_t *head = malloc(sizeof(node_t));
    cr_assert_not_null(head);

    int *value = malloc(sizeof(int));
    cr_assert_not_null(value);
    *value = 42;

    head->data = value;
    head->next = NULL;

    void *res = get_at(head, 1);

    cr_assert_null(res,
        "get_at(1) sur liste à un élément doit retourner NULL.");

    free(head->data);
    free(head);
}

Test(get_at_basic, multiple_elements_access)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));
    node_t *n3 = malloc(sizeof(node_t));

    cr_assert_not_null(n1);
    cr_assert_not_null(n2);
    cr_assert_not_null(n3);

    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));
    int *d3 = malloc(sizeof(int));

    cr_assert_not_null(d1);
    cr_assert_not_null(d2);
    cr_assert_not_null(d3);

    *d1 = 10;
    *d2 = 20;
    *d3 = 30;

    n1->data = d1; n1->next = n2;
    n2->data = d2; n2->next = n3;
    n3->data = d3; n3->next = NULL;

    // pos = 0
    cr_assert_eq(*(int *)get_at(n1, 0), 10,
        "get_at(pos=0) doit retourner data du premier nœud.");

    // pos = 1
    cr_assert_eq(*(int *)get_at(n1, 1), 20,
        "get_at(pos=1) doit retourner data du second nœud.");

    // pos = 2
    cr_assert_eq(*(int *)get_at(n1, 2), 30,
        "get_at(pos=2) doit retourner data du troisième nœud.");

    // pos hors borne
    cr_assert_null(get_at(n1, 3),
        "get_at(pos trop grand) doit retourner NULL.");

    free(d1); free(n1);
    free(d2); free(n2);
    free(d3); free(n3);
}

Test(get_at_basic, node_with_null_data)
{
    node_t *head = malloc(sizeof(node_t));
    cr_assert_not_null(head);

    head->data = NULL;
    head->next = NULL;

    void *res = get_at(head, 0);

    cr_assert_null(res,
        "get_at doit retourner NULL si data du nœud est NULL.");

    free(head);
}

//endregion

//region get_back's tests

Test(get_back_basic, empty_list_returns_null)
{
    node_t *head = NULL;

    void *res = get_back(head);

    cr_assert_null(res, "get_back sur une liste vide devrait retourner NULL.");
}

Test(get_back_basic, single_element_returns_only_data)
{
    node_t *head = malloc(sizeof(node_t));
    cr_assert_not_null(head, "Échec du malloc pour head.");

    int *value = malloc(sizeof(int));
    cr_assert_not_null(value, "Échec du malloc pour value.");
    *value = 99;

    head->data = value;
    head->next = NULL;

    void *res = get_back(head);

    cr_assert_not_null(res,
        "get_back sur une liste à un élément ne doit pas retourner NULL.");
    cr_assert_eq(*(int *)res, 99,
        "get_back sur une liste à un élément doit retourner la valeur de cet élément.");

    free(value);
    free(head);
}

Test(get_back_basic, multiple_elements_returns_last_data)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));
    node_t *n3 = malloc(sizeof(node_t));

    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    int *v3 = malloc(sizeof(int));

    cr_assert_not_null(n1); cr_assert_not_null(n2); cr_assert_not_null(n3);
    cr_assert_not_null(v1); cr_assert_not_null(v2); cr_assert_not_null(v3);

    *v1 = 1; *v2 = 2; *v3 = 3;

    n1->data = v1; n1->next = n2;
    n2->data = v2; n2->next = n3;
    n3->data = v3; n3->next = NULL;

    node_t *head = n1;

    void *res = get_back(head);

    cr_assert_not_null(res,
        "get_back sur une liste non vide ne doit pas retourner NULL.");
    cr_assert_eq(*(int *)res, 3,
        "get_back doit retourner la data du dernier élément (ici 3).");

    // on vérifie aussi que le pointeur head n'a pas été modifié côté appelant
    cr_assert_eq(head, n1,
        "get_back ne doit pas modifier le pointeur head passé en paramètre.");

    free(v1); free(v2); free(v3);
    free(n1); free(n2); free(n3);
}

//endregion

//region get_front's tests

Test(get_front_basic, null_head)
{
    node_t *head = NULL;

    void *res = get_front(head);

    cr_assert_null(res, "get_front devrait retourner NULL si la liste est vide.");
}

Test(get_front_basic, single_element)
{
    node_t *head = malloc(sizeof(node_t));
    int *value = malloc(sizeof(int));

    cr_assert_not_null(head);
    cr_assert_not_null(value);

    *value = 42;
    head->data = value;
    head->next = NULL;

    void *res = get_front(head);

    cr_assert_eq(res, value,
        "get_front devrait retourner le data du premier élément.");
}

Test(get_front_basic, multiple_elements)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));
    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));

    cr_assert_not_null(n1);
    cr_assert_not_null(n2);
    cr_assert_not_null(v1);
    cr_assert_not_null(v2);

    *v1 = 10;
    *v2 = 20;

    n1->data = v1;
    n1->next = n2;
    n2->data = v2;
    n2->next = NULL;

    void *res = get_front(n1);

    cr_assert_eq(res, v1,
        "get_front devrait retourner le data du premier élément dans une liste chaînée.");
}

//endregion

//region insert_node's tests

Test(insert_node_basic, insert_at_head)
{
    node_t *head = NULL;

    int *data = malloc(sizeof(int));
    cr_assert_not_null(data);
    *data = 42;

    insert_node(&head, data, 0);

    cr_assert_not_null(head, "Le head devrait pointer vers le nouveau nœud.");
    cr_assert_eq(*(int *)head->data, 42, "La valeur insérée en tête est incorrecte.");
    cr_assert_null(head->next, "Le next du nœud inséré en tête devrait être NULL.");
}

Test(insert_node_basic, insert_in_middle)
{
    node_t *head = NULL;

    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));
    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));
    cr_assert_not_null(n1); cr_assert_not_null(n2);
    cr_assert_not_null(d1); cr_assert_not_null(d2);

    *d1 = 10; *d2 = 20;
    n1->data = d1; n1->next = n2;
    n2->data = d2; n2->next = NULL;
    head = n1;

    int *d_mid = malloc(sizeof(int));
    cr_assert_not_null(d_mid);
    *d_mid = 15;

    insert_node(&head, d_mid, 1);

    cr_assert_eq(*(int *)head->next->data, 15,
        "La valeur insérée au milieu est incorrecte.");
    cr_assert_eq(*(int *)head->next->next->data, 20,
        "Le chaînage après insertion au milieu est incorrect.");
}

Test(insert_node_basic, insert_at_end)
{
    node_t *head = NULL;

    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));
    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));
    cr_assert_not_null(n1); cr_assert_not_null(n2);
    cr_assert_not_null(d1); cr_assert_not_null(d2);

    *d1 = 1; *d2 = 2;
    n1->data = d1; n1->next = n2;
    n2->data = d2; n2->next = NULL;
    head = n1;

    int *d_new = malloc(sizeof(int));
    cr_assert_not_null(d_new);
    *d_new = 99;

    insert_node(&head, d_new, 2);

    cr_assert_not_null(n2->next, "Le nœud final devrait pointer vers le nouveau nœud.");
    cr_assert_eq(*(int *)n2->next->data, 99, "La valeur insérée en fin est incorrecte.");
}

Test(insert_node_basic, insert_out_of_bounds_should_do_nothing)
{
    node_t *head = NULL;

    node_t *n1 = malloc(sizeof(node_t));
    int *d1 = malloc(sizeof(int));
    cr_assert_not_null(n1); cr_assert_not_null(d1);
    *d1 = 123;
    n1->data = d1;
    n1->next = NULL;
    head = n1;

    int *d_new = malloc(sizeof(int));
    cr_assert_not_null(d_new);
    *d_new = 999;

    insert_node(&head, d_new, 5);

    cr_assert_null(head->next,
        "Aucune insertion ne doit avoir lieu si pos dépasse la taille de la liste.");
    cr_assert_eq(*(int *)head->data, 123,
        "La liste ne doit pas être modifiée pour une pos hors bornes.");
}

//endregion

//region list_len's tests

Test(list_len_basic, empty_list)
{
    node_t *head = NULL;

    int res = list_len(head, 0);

    cr_assert_eq(res, 0, "Une liste vide devrait avoir une taille de 0.");
}

Test(list_len_basic, empty_list_with_nonzero_initial_len)
{
    node_t *head = NULL;

    int res = list_len(head, 5);

    cr_assert_eq(res, 5,
        "list_len doit simplement ajouter la longueur de la liste au paramètre 'len'.");
}

Test(list_len_basic, single_element_list)
{
    node_t *head = malloc(sizeof(node_t));
    cr_assert_not_null(head);

    int *data = malloc(sizeof(int));
    cr_assert_not_null(data);
    *data = 10;

    head->data = data;
    head->next = NULL;

    int res = list_len(head, 0);

    cr_assert_eq(res, 1, "Une liste avec 1 élément devrait retourner 1.");
}

Test(list_len_basic, multiple_elements_list)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));
    node_t *n3 = malloc(sizeof(node_t));

    cr_assert_not_null(n1);
    cr_assert_not_null(n2);
    cr_assert_not_null(n3);

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    n1->data = NULL;
    n2->data = NULL;
    n3->data = NULL;

    int res = list_len(n1, 0);

    cr_assert_eq(res, 3, "Une liste de 3 éléments devrait retourner 3.");
}

Test(list_len_basic, with_initial_len)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));

    cr_assert_not_null(n1);
    cr_assert_not_null(n2);

    n1->data = NULL;
    n2->data = NULL;

    n1->next = n2;
    n2->next = NULL;

    int res = list_len(n1, 10);

    cr_assert_eq(res, 12,
        "list_len(head, 10) avec 2 éléments devrait retourner 12.");
}

//endregion

//region pop_at's tests

Test(pop_at_basic, pop_from_empty_list)
{
    node_t *head = NULL;

    pop_at(&head, 0);

    cr_assert_null(head, "pop_at sur une liste vide ne doit rien modifier.");
}

Test(pop_at_basic, pop_first_element)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));

    n1->data = NULL;
    n2->data = NULL;

    n1->next = n2;
    n2->next = NULL;

    node_t *head = n1;

    pop_at(&head, 0);

    cr_assert_eq(head, n2,
        "Après suppression du premier élément, head doit pointer sur le second.");
}

Test(pop_at_basic, pop_middle_element)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));
    node_t *n3 = malloc(sizeof(node_t));

    n1->data = NULL;
    n2->data = NULL;
    n3->data = NULL;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    node_t *head = n1;

    pop_at(&head, 1);

    cr_assert_eq(n1->next, n3,
        "Après suppression du noeud en position 1, n1->next doit être n3.");
}

Test(pop_at_basic, pop_last_element)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));

    n1->data = NULL;
    n2->data = NULL;

    n1->next = n2;
    n2->next = NULL;

    node_t *head = n1;

    pop_at(&head, 1);

    cr_assert_null(n1->next,
        "Après suppression du dernier élément, le précédent doit pointer sur NULL.");
}

Test(pop_at_basic, pos_out_of_bounds_high)
{
    node_t *n1 = malloc(sizeof(node_t));
    n1->data = NULL;
    n1->next = NULL;

    node_t *head = n1;

    pop_at(&head, 10);

    cr_assert_eq(head, n1,
        "Une position trop grande ne doit rien modifier.");
}

Test(pop_at_basic, pos_out_of_bounds_negative)
{
    node_t *n1 = malloc(sizeof(node_t));
    n1->data = NULL;
    n1->next = NULL;

    node_t *head = n1;

    pop_at(&head, -5);

    cr_assert_eq(head, n1,
        "Une position négative ne doit rien modifier.");
}

//endregion

//region pop_back's tests

Test(pop_back_basic, empty_list)
{
    node_t *head = NULL;

    pop_back(&head);

    cr_assert_null(head,
        "pop_back sur une liste vide doit laisser head à NULL.");
}

Test(pop_back_basic, single_element_list)
{
    node_t *head = malloc(sizeof(node_t));
    int *data = malloc(sizeof(int));
    *data = 42;

    head->data = data;
    head->next = NULL;

    pop_back(&head);

    cr_assert_null(head,
        "pop_back sur une liste d'un seul élément doit mettre head à NULL.");
}

Test(pop_back_basic, multiple_elements_list)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));
    node_t *n3 = malloc(sizeof(node_t));

    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));
    int *d3 = malloc(sizeof(int));

    *d1 = 1; *d2 = 2; *d3 = 3;

    n1->data = d1; n2->data = d2; n3->data = d3;
    n1->next = n2; n2->next = n3; n3->next = NULL;

    node_t *head = n1;

    pop_back(&head);

    cr_assert_not_null(head, "La tête ne doit pas devenir NULL.");
    cr_assert_not_null(head->next, "Le deuxième élément doit rester.");
    cr_assert_null(head->next->next,
        "Après pop_back, le dernier élément doit être supprimé.");
}

Test(pop_back_basic, two_elements_list)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));

    int *d1 = malloc(sizeof(int));
    int *d2 = malloc(sizeof(int));

    *d1 = 10; *d2 = 20;

    n1->data = d1;
    n2->data = d2;
    n1->next = n2;
    n2->next = NULL;

    node_t *head = n1;

    pop_back(&head);

    cr_assert_not_null(head, "La tête ne doit pas devenir NULL.");
    cr_assert_null(head->next,
        "Après pop_back sur 2 éléments, il ne doit rester que le premier.");

    cr_assert_eq(*(int*)head->data, 10,
        "Le premier élément restant doit être celui initialement en tête.");
}

//endregion

//region pop_front's tests

Test(pop_front_basic, empty_list)
{
    node_t *head = NULL;

    pop_front(&head);

    cr_assert_null(head,
        "pop_front sur liste vide doit laisser head à NULL.");
}

Test(pop_front_basic, single_element_list)
{
    node_t *head = malloc(sizeof(node_t));
    cr_assert_not_null(head);
    head->data = malloc(sizeof(int));
    head->next = NULL;

    pop_front(&head);

    cr_assert_null(head,
        "Après pop_front sur une liste à un élément, head doit être NULL.");
}

Test(pop_front_basic, multiple_elements_list)
{
    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));
    node_t *n3 = malloc(sizeof(node_t));

    cr_assert_not_null(n1);
    cr_assert_not_null(n2);
    cr_assert_not_null(n3);

    n1->data = malloc(sizeof(int));
    n2->data = malloc(sizeof(int));
    n3->data = malloc(sizeof(int));

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    node_t *head = n1;

    pop_front(&head);

    cr_assert_eq(head, n2,
        "Après pop_front, head doit pointer vers l’ancien deuxième élément.");
    cr_assert_eq(head->next, n3,
        "La chaîne doit rester correcte après suppression du premier élément.");
}

//endregion

//region push_back's tests

Test(push_back_basic, push_into_empty_list)
{
    node_t *head = NULL;
    int *value = malloc(sizeof(int));
    cr_assert_not_null(value, "Échec du malloc pour value.");
    *value = 10;

    push_back(&head, value);

    cr_assert_not_null(head, "Après push_back, la tête ne doit pas être NULL.");
    cr_assert_eq(*(int *)head->data, 10, "La donnée du premier élément doit être 10.");
    cr_assert_null(head->next, "La liste ne doit contenir qu'un élément.");
}

Test(push_back_basic, push_into_non_empty_list)
{
    node_t *head = malloc(sizeof(node_t));
    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));

    cr_assert_not_null(head);
    cr_assert_not_null(v1);
    cr_assert_not_null(v2);

    *v1 = 5;
    *v2 = 20;

    head->data = v1;
    head->next = NULL;

    push_back(&head, v2);

    cr_assert_not_null(head->next, "Le second élément devrait exister.");
    cr_assert_eq(*(int *)head->next->data, 20,
        "La donnée du dernier élément doit être 20.");
    cr_assert_null(head->next->next, "Le dernier élément ne doit pas avoir de next.");
}

//endregion

//region push_front's tests

Test(push_front_basic, add_to_empty_list)
{
    node_t *head = NULL;

    int *value = malloc(sizeof(int));
    *value = 10;

    push_front(&head, value);

    cr_assert_not_null(head, "La liste ne doit plus être NULL après push_front.");
    cr_assert_eq(*(int *)head->data, 10, "La valeur insérée n'est pas correcte.");
    cr_assert_null(head->next, "La liste doit contenir un seul élément.");
}

Test(push_front_basic, add_to_non_empty_list)
{
    node_t *head = malloc(sizeof(node_t));
    int *first_value = malloc(sizeof(int));
    *first_value = 20;

    head->data = first_value;
    head->next = NULL;

    int *new_value = malloc(sizeof(int));
    *new_value = 30;

    push_front(&head, new_value);

    cr_assert_not_null(head, "Le head doit être mis à jour.");
    cr_assert_eq(*(int *)head->data, 30, "La nouvelle valeur doit être en tête.");
    cr_assert_not_null(head->next, "L'ancien head doit devenir le second élément.");
    cr_assert_eq(*(int *)head->next->data, 20, "L'ancien head n'est pas correctement placé.");
}

Test(push_front_basic, malloc_failure_safe)
{
    node_t *head = NULL;

    push_front(&head, NULL);

    cr_assert(1, "push_front ne doit pas provoquer de crash même si data est NULL.");
}

//endregion

//region search_in_list's tests

static int cmp_int(void *a, void *b)
{
    return (*(int*)a - *(int*)b);
}

Test(search_in_list_basic, empty_list)
{
    node_t *head = NULL;
    int target = 10;

    int result = search_in_list(head, &target, cmp_int);

    cr_assert_eq(result, 84,
        "search_in_list() doit renvoyer 84 quand la liste est vide.");
}

Test(search_in_list_basic, value_at_first_position)
{
    int *v1 = malloc(sizeof(int));
    *v1 = 5;

    node_t *n1 = malloc(sizeof(node_t));
    n1->data = v1;
    n1->next = NULL;

    int target = 5;

    int result = search_in_list(n1, &target, cmp_int);

    cr_assert_eq(result, 1,
        "search_in_list() doit renvoyer 1 lorsque l’élément est en première position.");

    free(v1);
    free(n1);
}

Test(search_in_list_basic, value_in_middle)
{
    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    int *v3 = malloc(sizeof(int));
    *v1 = 1; *v2 = 2; *v3 = 3;

    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));
    node_t *n3 = malloc(sizeof(node_t));

    n1->data = v1; n1->next = n2;
    n2->data = v2; n2->next = n3;
    n3->data = v3; n3->next = NULL;

    int target = 2;

    int result = search_in_list(n1, &target, cmp_int);

    cr_assert_eq(result, 2,
        "search_in_list() doit renvoyer 2 lorsque l’élément est au milieu.");

    free(v1); free(v2); free(v3);
    free(n1); free(n2); free(n3);
}

Test(search_in_list_basic, value_at_end)
{
    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    *v1 = 10; *v2 = 20;

    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));

    n1->data = v1; n1->next = n2;
    n2->data = v2; n2->next = NULL;

    int target = 20;

    int result = search_in_list(n1, &target, cmp_int);

    cr_assert_eq(result, 2,
        "search_in_list() doit renvoyer 2 lorsque l’élément est en fin de liste.");

    free(v1); free(v2);
    free(n1); free(n2);
}

Test(search_in_list_basic, value_not_found)
{
    int *v1 = malloc(sizeof(int));
    int *v2 = malloc(sizeof(int));
    *v1 = 1; *v2 = 2;

    node_t *n1 = malloc(sizeof(node_t));
    node_t *n2 = malloc(sizeof(node_t));

    n1->data = v1; n1->next = n2;
    n2->data = v2; n2->next = NULL;

    int target = 999;

    int result = search_in_list(n1, &target, cmp_int);

    cr_assert_eq(result, 84,
        "search_in_list() doit renvoyer 84 lorsque l’élément est introuvable.");

    free(v1); free(v2);
    free(n1); free(n2);
}

//endregion


//endregion

//endregion

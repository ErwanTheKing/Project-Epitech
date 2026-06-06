/*
** EPITECH PROJECT, 2026
** secured
** File description:
** The unit_tests.c
*/
/**
 * @file unit_tests.c
 * @brief The unit_tests.c
 * @author Erwan Lo Presti
 */

#include <stdint.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/hashtable.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static int malloc_call_count = 0;
static int fail_on_call = -1;

void *__real_malloc(size_t);

void *__wrap_malloc(size_t size)
{
    malloc_call_count++;
    if (malloc_call_count == fail_on_call)
        return NULL;
    return __real_malloc(size);
}

Test(hashtable_create, basic, .init = redirect_all_std)
{
    hashtable_t *hashtable = new_hashtable(&hash, 4);

    ht_dump(hashtable);
    cr_assert_stdout_eq_str("[0]:\n[1]:\n[2]:\n[3]:\n");
    delete_hashtable(hashtable);
}

Test(hashtable_create, len_inf, .init = redirect_all_std)
{
    hashtable_t *hashtable = new_hashtable(&hash, 0);

    ht_dump(hashtable);
    cr_assert_stdout_eq_str("");
    delete_hashtable(hashtable);
}

Test(hashtable_create, malloc_fail)
{
    malloc_call_count = 0;
    fail_on_call = 1;

    hashtable_t *ht = new_hashtable(&hash, 10);

    cr_assert_null(ht);
}

Test(hashtable_create, buckets_malloc_fail)
{
    malloc_call_count = 0;
    fail_on_call = 2;

    hashtable_t *ht = new_hashtable(&hash, 10);

    cr_assert_null(ht);
}

Test(add_element, add_one_element, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 1);

    ht_insert(ht, "vision", "salut");
    ht_dump(ht);
    cr_assert_stdout_eq_str("[0]:\n> 1799 - salut\n");
    delete_hashtable(ht);
}

Test(del_element, del_one_element, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 2);

    ht_insert(ht, "vision", "salut");
    ht_insert(ht, "test", "salut");
    ht_delete(ht, "vision");
    ht_delete(ht, "test");
    ht_dump(ht);
    cr_assert_stdout_eq_str("[0]:\n[1]:\n");
    delete_hashtable(ht);
}

Test(search_element, search_one_element, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 1);

    ht_insert(ht, "vision", "salut");
    ht_search(ht, "vision");
    ht_dump(ht);
    cr_assert_stdout_eq_str("[0]:\n> 1799 - salut\n");
    delete_hashtable(ht);
}

Test(del_element, del_inf_element, .init = redirect_all_std)
{
    hashtable_t *ht = new_hashtable(&hash, 0);

    ht_insert(ht, "vision", "salut");
    ht_delete(ht, "vision");
    ht_dump(ht);
    cr_assert_stdout_eq_str("");
    delete_hashtable(ht);
}

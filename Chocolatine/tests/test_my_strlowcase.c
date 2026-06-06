/*
** EPITECH PROJECT, 2026
** PainAuChocolat
** File description:
** The test_my_strlowcase.c
*/
/**
 * @file test_my_strlowcase.c
 * @brief The test_my_strlowcase.c
 * @author Erwan Lo Presti
 */

#include <criterion/criterion.h>
#include "../test.h"

Test(lowcasetest, lowcasetest)
{
    char str[7] = "ABcDEF";

    my_strlowcase(str);
    cr_assert_str_eq(str, "abcdef");
}

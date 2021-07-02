/*
** EPITECH PROJECT, 2020
** criterion
** File description:
** error test
*/

#include <criterion/criterion.h>

int check_char(const char *content);

Test(test_1, test_my_errors)
{
    char str[] = "2:A3:A4\n3:D1:C1\n4:F8:C8\n5:B3:B8\n";
    int test = check_char(str);

    cr_assert_eq(test, 0);
}

Test(test_2, test_my_errors)
{
    char str[] = "7fvhvhdwrjAhbrqdhve<sbv\nse<fhbceqfhe";
    int test = check_char(str);

    cr_assert_eq(test, 1);
}
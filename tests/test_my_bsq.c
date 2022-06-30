/*
** EPITECH PROJECT, 2021
** B-CPE-110-RUN-1-1-BSQ-junot-hery-nantenaina.montpre
** File description:
** test_my_bsq
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(bsq, test_basic_map, .init = redirect_all_std)
{
    bsq_t *s = malloc(sizeof(bsq_t));
    bsq("mouli_maps/intermediate_map_one_filled_box", s);
    free(s);
    cr_assert_stdout_eq_str("o\n");
}

Test(bsq, test_basic_map_empty, .init = redirect_all_std)
{
    bsq_t *s = malloc(sizeof(bsq_t));
    bsq("mouli_maps/intermediate_map_one_empty_box", s);
    free(s);
    cr_assert_stdout_eq_str("x\n");
}

Test(my_put_nbr, simple_number, .init = redirect_all_std)
{
    my_put_nbr(-12);
    cr_assert_stdout_eq_str("-12");
}

Test(my_getnbr, simple_number, .init = redirect_all_std)
{
    my_getnbr("12", '\0');
    cr_assert_stdout_neq_str("12");
}

Test(my_putstr, simple_number, .init = redirect_all_std)
{
    my_putstr("toto");
    cr_assert_stdout_eq_str("toto");
}

Test(my_strcpy, simple_number, .init = redirect_all_std)
{
    char *dest = my_strcpy(my_strdup("toto"), "toto");
    cr_assert_stdout_neq_str("tototo");
}

Test(my_getnbr, simple_number_with_char, .init = redirect_all_std)
{
    my_getnbr("-55to", '\0');
    cr_assert_stdout_neq_str("-55");
}

Test(my_getnbr, simple_big_nbr, .init = redirect_all_std)
{
    my_getnbr("55555555555555a", '\0');
    cr_assert_stdout_neq_str("0");
}

Test(my_nblen, simple_big_nbr, .init = redirect_all_std)
{
    my_nblen(-55);
    cr_assert_stdout_neq_str("2");
}

Test(bsq, middle_map, .init = redirect_all_std)
{
    bsq_t *s = malloc(sizeof(bsq_t));
    bsq("mouli_maps/toto", s);
    free(s);
    cr_assert_stdout_neq_str("xx..xx..\n.o..\n");
}

Test(bsq, map_null, .init = redirect_all_std)
{
    bsq_t *s = malloc(sizeof(bsq_t));
    bsq("mouli_maps/tata", s);
    free(s);
    cr_assert_stdout_neq_str("");
}

Test(bsq, map_invalid, .init = redirect_all_std)
{
    bsq_t *s = malloc(sizeof(bsq_t));
    int r = bsq("mouli_maps/null", s);
    free(s);
    cr_assert_neq(84, r);
}

Test(free_intarray, map_null, .init = redirect_all_std)
{
    int **map = NULL;
    int r = free_intarray(map, 2);
    cr_assert_eq(84, r);
}

Test(bsq, bsq_map_nor_meta, .init = redirect_all_std)
{
    bsq_t *s = malloc(sizeof(bsq_t));
    int r = bsq("mouli_maps/tutu", s);
    free(s);
    cr_assert_stdout_eq_str(".xx\noxx\n...\n");
}

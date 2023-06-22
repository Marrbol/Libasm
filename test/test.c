#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include <dlfcn.h>

void *handle;
void *(*my_memset)(void * str, int c, size_t n);
void *(*my_memcpy)(void * str, void* c, size_t n);
void *(*my_memmove)(void * str, void* c, size_t n);
int (*my_strlen)(char const * str);
char *(*my_strchr)(char const * str, char c);
char *(*my_strrchr)(char const * str, char c);
int (*my_strcmp)(char *str, char *c);
int (*my_strncmp)(char *str, char *c, size_t n);

void ope_li(void)
{
    handle = dlopen("./libasm.so", RTLD_LAZY);
    *(void**)(&my_strlen) = dlsym(handle, "strlen");
    *(void**)(&my_memset) = dlsym(handle, "memset");
    *(void**)(&my_memcpy) = dlsym(handle, "memcpy");
    *(void**)(&my_memmove) = dlsym(handle, "memcpy");
    *(void**)(&my_strchr) = dlsym(handle, "strchr");
    *(void**)(&my_strrchr) = dlsym(handle, "strrchr");
    *(void**)(&my_strcmp) = dlsym(handle, "strcmp");
    *(void**)(&my_strncmp) = dlsym(handle, "strncmp");
}

void close_li(void)
{
    dlclose(handle);
}

Test(strlen, oui, .init = ope_li, .fini = close_li) {
    cr_assert(my_strlen("str") == 3);
}

Test(strlen, 0,.init = ope_li, .fini = close_li) {
    cr_assert(my_strlen("") == 0);
}

Test(my_strchr, One_mort_test,.init = ope_li, .fini = close_li) {
    cr_assert(strcmp(my_strchr("proutzoui", 'z'), "oui"));
}

Test(my_strchr, no_empty_0, .init = ope_li, .fini = close_li) {
    cr_assert(strcmp(my_strchr("One more test!", '\0'), "") == 0);
}

Test(my_strchr, empty_0, .init = ope_li, .fini = close_li) {
    cr_assert(strcmp(my_strchr("", '\0'), "") == 0);
}

Test(my_memset, classique, .init = ope_li, .fini = close_li) {
    char str[6] = "nnnnn";
    my_memset(str, 'o', 4);
    cr_assert(strcmp(str, "oooon") == 0);
}

Test(my_memset, empty, .init = ope_li, .fini = close_li) {
    char str[6] = "";
    my_memset(str, 'o', 4);
    cr_assert(strcmp(str, "oooo") == 0);
}

Test(my_memset, mérédith, .init = ope_li, .fini = close_li) {
    char str[6] = "nnnnn";
    my_memset(str, 'o', 4);
    cr_assert(strcmp(str, "oooon") == 0);
}

Test(my_memcpy, classique, .init = ope_li, .fini = close_li) {
    char str[6] = "nnnnn";
    char stcpy[6] = "nnnnn";
    memcpy(stcpy, "oui", 4);
    my_memcpy(str, "oui", 4);
    cr_assert_str_eq(str, stcpy);
}

Test(my_memcpy, 0, .init = ope_li, .fini = close_li) {
    char str[6] = "";
    char stcpy[6] = "";
    memcpy(stcpy, "oui", 4);
    my_memcpy(str, "oui", 4);
    cr_assert_str_eq(str, stcpy);
}

Test(my_memcpy, test, .init = ope_li, .fini = close_li) {
    char str[6] = "jetest";
    char stcpy[6] = "jetest";
    memcpy(stcpy, "oui", 4);
    my_memcpy(str, "oui", 4);
    cr_assert_str_eq(str, stcpy);
}

Test(my_strcmp, classique, .init = ope_li, .fini = close_li) {
    char str[6] = "jetest";
    int i = strcmp(str, "oui");
    int j = my_strcmp(str, "oui");
    cr_assert_eq(i, j);
}

Test(my_strcmp, same, .init = ope_li, .fini = close_li) {
    char str[6] = "jetest";
    int i = strcmp(str, "jetest");
    int j = my_strcmp(str, "jetest");
    cr_assert_eq(i, j);
}

Test(my_strcmp, plus_grand, .init = ope_li, .fini = close_li) {
    char str[6] = "12345";
    int i = strcmp(str, "22345");
    int j = my_strcmp(str, "22345");
    cr_assert_eq(i, j);
}

Test(my_strcmp, plus_petit, .init = ope_li, .fini = close_li) {
    char str[6] = "22345";
    int i = strcmp(str, "12345");
    int j = my_strcmp(str, "12345");
    cr_assert_eq(i, j);
}

Test(my_strcmp, empty, .init = ope_li, .fini = close_li) {
    char str[6] = "";
    int i = strcmp(str, "12345");
    int j = my_strcmp(str, "12345");
    cr_assert_eq(i, j);
}

Test(my_strcmp, empty2, .init = ope_li, .fini = close_li) {
    char str[6] = "12345";
    int i = strcmp(str, "");
    int j = my_strcmp(str, "");
    cr_assert_eq(i, j);
}

Test(my_strcmp, empty3, .init = ope_li, .fini = close_li) {
    char str[6] = "";
    int i = strcmp(str, "");
    int j = my_strcmp(str, "");
    cr_assert_eq(i, j);
}

Test(my_strcmp, space, .init = ope_li, .fini = close_li) {
    char str[6] = "12345";
    int i = strcmp(str, " ");
    int j = my_strcmp(str, " ");
    cr_assert_eq(i, j);
}

Test(my_strcmp, minishell2, .init = ope_li, .fini = close_li) {
    char str[6] = "env";
    int i = strcmp(str, "cp");
    int j = my_strcmp(str, "cp");
    cr_assert_eq(i, j);
}

Test(my_strncmp, classique, .init = ope_li, .fini = close_li) {
    char str[6] = "jetest";
    int i = strncmp(str, "oui", 2);
    int j = my_strncmp(str, "oui", 2);
    cr_assert_eq(i, j);
}


Test(my_strncmp, empty, .init = ope_li, .fini = close_li) {
    char str[6] = "";
    int i = strncmp(str, "oui", 2);
    int j = my_strncmp(str, "oui", 2);
    cr_assert_eq(i, j);
}

Test(my_strncmp, 0, .init = ope_li, .fini = close_li) {
    char str[6] = "";
    int i = strncmp(str, "oui", 0);
    int j = my_strncmp(str, "oui", 0);
    cr_assert_eq(i, j);
}


Test(my_strncmp, full_empty, .init = ope_li, .fini = close_li) {
    char str[6] = "";
    int i = strncmp(str, "", 0);
    int j = my_strncmp(str, "", 0);
    cr_assert_eq(i, j);
}

Test(my_strncmp, full_empty2, .init = ope_li, .fini = close_li) {
    char str[6] = "";
    int i = strncmp(str, "", 2);
    int j = my_strncmp(str, "", 2);
    cr_assert_eq(i, j);
}

Test(my_strncmp, oui_empty, .init = ope_li, .fini = close_li) {
    char str[6] = "oui";
    int i = strncmp(str, "", 2);
    int j = my_strncmp(str, "", 2);
    cr_assert_eq(i, j);
}

Test(my_strncmp, switch_case, .init = ope_li, .fini = close_li) {
    char str[6] = "oui";
    int i = strncmp(str, "OUI", 2);
    int j = my_strncmp(str, "OUI", 2);
    cr_assert_eq(i, j);
}

Test(my_strncmp, more_size, .init = ope_li, .fini = close_li) {
    char str[6] = "oui";
    int i = strncmp(str, "OUI", 10);
    int j = my_strncmp(str, "OUI", 10);
    cr_assert_eq(i, j);
}

Test(my_memmove, classique, .init = ope_li, .fini = close_li) {
    char str[6] = "nnnnn";
    char stcpy[6] = "nnnnn";
    memmove(stcpy, "oui", 4);
    my_memmove(str, "oui", 4);
    cr_assert_str_eq(str, stcpy);
}
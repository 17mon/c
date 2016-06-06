#include <stdio.h>
#include <string.h>
#include "ipip.h"

char *strtok_r_2(char *str, char const *delims, char **context) {
    char *p, *ret = NULL;

    if (str != NULL)
        *context = str;

    if (*context == NULL)
        return NULL;

    if ((p = strpbrk(*context, delims)) != NULL) {
        *p = 0;
        ret = *context;
        *context = ++p;
    }
    else if (**context) {
        ret = *context;
        *context = NULL;
    }
    return ret;
}

int main() {
    init("ipip.datx");
    char *ip = "223.255.152.0";
    char result[128];
    find(ip, result);
        printf("%s -> %s\n", ip, result);
        char *rst = NULL;
        char *lasts;
        rst = strtok_r_2(result, "\t", &lasts);
        while (rst) {
            printf("%s\n", rst);
            rst = strtok_r_2(NULL, "\t", &lasts);
        }
    destroy();

    init("ipip.datx");
    if (find("127.0.0.1", result)) {
        printf("%s -> %s", "127.0.0.1", result);
    }
    destroy();
    return 0;
}

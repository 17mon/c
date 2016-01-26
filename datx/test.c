#include <stdio.h>
#include "ipip.h"

int main() {
    init("ipip.datx");
    char *ip = "8.8.8.8";
    char result[128];
    find(ip, result);
    printf("%s -> %s", ip, result);
    destroy();

    init("ipip.datx");
    find("127.0.0.1", result);
    printf("%s -> %s", ip, result);
    destroy();
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int i;
    int opt;
    int n = 0;

    while ((opt = getopt(argc, argv, "n")) != -1) {
        switch (opt) {
            case 'n':
                n = 1;
                break;
            default:
                printf("Usage: %s [-n] [string]\n", argv[0]);
                return 1;
        }
    }

    for (i = optind; i < argc; i++) {
        printf("%s ", argv[i]);
    }

    if (n == 0) {
        printf("\n");
    }

    return 0;
}

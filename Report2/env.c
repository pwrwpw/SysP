#include <stdio.h>
#include <stdlib.h>

int main() {
    extern char** environ;

    // 환경 변수 출력
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }

    return 0;
}

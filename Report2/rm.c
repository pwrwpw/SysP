#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    char *fileName = argv[1];

    if (remove(fileName) != 0) {
        perror("파일 삭제 실패");
        return 1;
    }

    return 0;
}

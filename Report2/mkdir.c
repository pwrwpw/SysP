#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) { // 명령줄 인수의 개수가 2가 아닌 경우
        printf("사용법: %s <폴더명>\n", argv[0]);
        return 1;
    }

    char *folderName = argv[1]; // 입력한 폴더명을 변수에 저장
p
    if (mkdir(folderName, 0777) != 0) { // 폴더 생성 시도
        perror("디렉토리 생성 실패"); // 생성 실패 시 에러 메시지 출력
        return 1;
    }

    return 0;
}

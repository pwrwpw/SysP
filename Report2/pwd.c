#include <unistd.h>
#include <stdio.h>

int main() {
    char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {  // 현재 작업 중인 디렉토리 경로 가져오기
        printf("현재 디렉토리: %s\n", cwd);  // 현재 디렉토리 경로 출력
    } else {
        perror("현재 디렉토리 확인 실패");  // 현재 디렉토리 확인 실패 시 에러 메시지 출력
        return 1;
    }

    return 0;
}

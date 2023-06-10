#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // unix kill commands

    // 명령행 인수의 개수가 3개가 아닌 경우, 사용법 출력 후 프로그램 종료
    if (argc != 3) {
        printf("사용법: %s <signal> <pid>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sig = atoi(argv[1]);  // signal 번호를 정수형으로 변환
    pid_t pid = atoi(argv[2]);  // pid를 정수형으로 변환

    // kill 함수를 사용하여 프로세스에 시그널 전송, 실패한 경우 오류 출력 후 프로그램 종료
    if (kill(pid, sig) == -1) {
        perror("kill");
        exit(EXIT_FAILURE);
    }

    printf("프로세스 %d에 시그널 %d가 전송되었습니다.\n", pid, sig);
    exit(EXIT_SUCCESS);
}

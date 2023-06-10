#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("잘못된 사용법입니다. 사용법: %s <대기 시간>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* time = argv[1]; // 대기 시간을 문자열로 저장
    int length = strlen(time); // 대기 시간 문자열의 길이 저장
    int seconds = 0; // 대기 시간(초) 저장할 변수

    if (length < 2) { // 대기 시간 형식이 올바르지 않은 경우
        printf("잘못된 대기 시간 형식입니다. 올바른 형식 예시: 3s, 5m, 2h\n");
        exit(EXIT_FAILURE);
    }

    int multiplier; // 대기 시간 변환 상수
    switch (time[length - 1]) {
        case 's':
            multiplier = 1; // 초 단위
            break;
        case 'm':
            multiplier = 60; // 분 단위
            break;
        case 'h':
            multiplier = 3600; // 시간 단위
            break;
        default:
            printf("잘못된 대기 시간 형식입니다. 올바른 형식 예시: 3s, 5m, 2h\n");
            exit(EXIT_FAILURE);
    }

    time[length - 1] = '\0'; // 대기 시간 문자열에서 단위 문자 제거
    seconds = atoi(time) * multiplier; // 대기 시간(초) 계산

    sleep(seconds); // 프로세스를 대기 시간만큼 일시 정지

    exit(EXIT_SUCCESS);
}

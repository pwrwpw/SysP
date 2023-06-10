#include <stdio.h>
#include <time.h>

const char* today(struct tm t);

int main(int argc, char* argv[]) {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    printf("%d년 %d월 %d일 %s요일 %d시 %d분 %d초\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, today(*tm), tm->tm_hour, tm->tm_min, tm->tm_sec);
    return 0;
}

const char* today(struct tm t) {
    const char* day[7] = { "일", "월", "화", "수", "목", "금", "토" };
    return day[t.tm_wday];
}

#include <stdio.h>
#include <unistd.h>

int main() {
    char hostname[256];

    if (gethostname(hostname, sizeof(hostname)) != 0) {
        perror("호스트 이름 가져오기 실패");
        return 1;
    }

    printf("%s\n", hostname);

    return 0;
}

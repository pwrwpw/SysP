#include <stdio.h>
#include <unistd.h>

int main() {
    char username[256];
    if (getlogin_r(username, sizeof(username)) == 0) {
        printf("%s\n", username);
        return 0;
    } else {
        perror("사용자 이름을 가져올 수 없습니다.");
        return 1;
    }
}

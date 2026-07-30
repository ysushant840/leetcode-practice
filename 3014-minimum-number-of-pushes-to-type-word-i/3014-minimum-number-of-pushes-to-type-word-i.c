#include <string.h>

int minimumPushes(char* word) {
    int n = strlen(word);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += (i / 8) + 1;
    }

    return ans;
}
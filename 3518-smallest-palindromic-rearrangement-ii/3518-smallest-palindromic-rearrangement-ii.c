#include <stdlib.h>
#include <string.h>

#define LIMIT 1000005LL

long long comb(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r > n - r) r = n - r;

    long long ans = 1;
    for (int i = 1; i <= r; i++) {
        ans = ans * (n - r + i) / i;
        if (ans > LIMIT) return LIMIT;
    }
    return ans;
}

long long countWays(int cnt[]) {
    int total = 0;
    for (int i = 0; i < 26; i++) total += cnt[i];

    long long ans = 1;
    int rem = total;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        ans *= comb(rem, cnt[i]);
        if (ans > LIMIT) ans = LIMIT;
        rem -= cnt[i];
    }

    return ans;
}

char* smallestPalindrome(char* s, int k) {
    int freq[26] = {0};
    int half[26] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++)
        freq[s[i] - 'a']++;

    char mid = '\0';
    int halfLen = 0;

    for (int i = 0; i < 26; i++) {
        half[i] = freq[i] / 2;
        halfLen += half[i];
        if (freq[i] % 2)
            mid = 'a' + i;
    }

    char *left = (char *)malloc(halfLen + 1);
    int idx = 0;

    for (int pos = 0; pos < halfLen; pos++) {
        int found = 0;

        for (int c = 0; c < 26; c++) {
            if (half[c] == 0) continue;

            half[c]--;
            long long ways = countWays(half);

            if (ways >= k) {
                left[idx++] = 'a' + c;
                found = 1;
                break;
            }

            k -= ways;
            half[c]++;
        }

        if (!found) {
            free(left);
            char *ans = (char *)malloc(1);
            ans[0] = '\0';
            return ans;
        }
    }

    left[idx] = '\0';

    char *ans = (char *)malloc(n + 1);

    for (int i = 0; i < halfLen; i++)
        ans[i] = left[i];

    int p = halfLen;

    if (mid)
        ans[p++] = mid;

    for (int i = halfLen - 1; i >= 0; i--)
        ans[p++] = left[i];

    ans[p] = '\0';

    free(left);
    return ans;
}
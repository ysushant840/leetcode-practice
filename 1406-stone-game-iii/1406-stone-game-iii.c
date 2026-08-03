#include <stdlib.h>
#include <limits.h>

char* stoneGameIII(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;

    int* dp = (int*)malloc((n + 1) * sizeof(int));

    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        dp[i] = INT_MIN;
        int take = 0;

        for (int k = 0; k < 3 && i + k < n; k++) {
            take += stoneValue[i + k];
            int diff = take - dp[i + k + 1];
            if (diff > dp[i])
                dp[i] = diff;
        }
    }

    char* ans;
    if (dp[0] > 0)
        ans = "Alice";
    else if (dp[0] < 0)
        ans = "Bob";
    else
        ans = "Tie";

    free(dp);
    return ans;
}
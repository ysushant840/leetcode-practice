#include <string.h>
#include <stdlib.h>

int dp[105][105];
int suffix[105];
int n;

int solve(int i, int M) {
    if (i >= n)
        return 0;

    // Remaining piles can all be taken
    if (n - i <= 2 * M)
        return suffix[i];

    if (dp[i][M] != -1)
        return dp[i][M];

    int ans = 0;

    for (int X = 1; X <= 2 * M && i + X <= n; X++) {

        int newM = (M > X) ? M : X;

        int current = suffix[i] - solve(i + X, newM);

        if (current > ans)
            ans = current;
    }

    return dp[i][M] = ans;
}

int stoneGameII(int* piles, int pilesSize) {

    n = pilesSize;

    // Suffix sum
    suffix[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = piles[i] + suffix[i + 1];
    }

    // Initialize DP with -1
    memset(dp, -1, sizeof(dp));

    return solve(0, 1);
}
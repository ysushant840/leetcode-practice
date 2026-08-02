#include <stdlib.h>
#include <stdbool.h>

bool stoneGame(int* piles, int pilesSize) {
    int dp[500][500];

    for (int i = 0; i < pilesSize; i++)
        dp[i][i] = piles[i];

    for (int len = 2; len <= pilesSize; len++) {
        for (int i = 0; i + len - 1 < pilesSize; i++) {
            int j = i + len - 1;

            int left = piles[i] - dp[i + 1][j];
            int right = piles[j] - dp[i][j - 1];

            dp[i][j] = (left > right) ? left : right;
        }
    }

    return dp[0][pilesSize - 1] > 0;
}
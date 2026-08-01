#include <stdbool.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

bool predictTheWinner(int* nums, int numsSize) {
    int dp[21][21] = {0};

    // Base case
    for (int i = 0; i < numsSize; i++)
        dp[i][i] = nums[i];

    // Fill DP table
    for (int len = 2; len <= numsSize; len++) {
        for (int i = 0; i + len - 1 < numsSize; i++) {
            int j = i + len - 1;

            int takeLeft = nums[i] - dp[i + 1][j];
            int takeRight = nums[j] - dp[i][j - 1];

            dp[i][j] = max(takeLeft, takeRight);
        }
    }

    return dp[0][numsSize - 1] >= 0;
}
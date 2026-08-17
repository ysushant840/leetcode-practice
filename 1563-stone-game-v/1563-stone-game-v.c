int stoneGameV(int* stoneValue, int stoneValueSize) {
    int n = stoneValueSize;

    long long prefix[n + 1];
    int dp[n][n];

    prefix[0] = 0;
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + stoneValue[i];
    }

    // dp[l][r] = maximum score for subarray [l, r]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // Process intervals from shorter to longer.
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;

            for (int k = l; k < r; k++) {
                long long leftSum = prefix[k + 1] - prefix[l];
                long long rightSum = prefix[r + 1] - prefix[k + 1];

                if (leftSum < rightSum) {
                    int score = (int)(leftSum + dp[l][k]);
                    if (score > dp[l][r])
                        dp[l][r] = score;
                }
                else if (leftSum > rightSum) {
                    int score = (int)(rightSum + dp[k + 1][r]);
                    if (score > dp[l][r])
                        dp[l][r] = score;
                }
                else {
                    int score1 = (int)(leftSum + dp[l][k]);
                    int score2 = (int)(rightSum + dp[k + 1][r]);

                    if (score1 > dp[l][r])
                        dp[l][r] = score1;
                    if (score2 > dp[l][r])
                        dp[l][r] = score2;
                }
            }
        }
    }

    return dp[0][n - 1];
}
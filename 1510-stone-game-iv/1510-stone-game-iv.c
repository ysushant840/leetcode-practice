#include <stdbool.h>
#include <math.h>

bool winnerSquareGame(int n) {
    bool dp[n + 1];

    dp[0] = false;

    for (int i = 1; i <= n; i++) {
        dp[i] = false;

        for (int j = 1; j * j <= i; j++) {
            // If we can move to a losing position,
            // current player wins.
            if (dp[i - j * j] == false) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}
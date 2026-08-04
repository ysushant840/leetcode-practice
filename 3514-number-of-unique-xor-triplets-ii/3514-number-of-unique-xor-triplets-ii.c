#include <stdbool.h>
#include <string.h>

int uniqueXorTriplets(int* nums, int numsSize) {
    const int MAXX = 2048;   

    bool dp[4][MAXX];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = true;


    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        for (int cnt = 2; cnt >= 0; cnt--) {
            for (int x = 0; x < MAXX; x++) {
                if (dp[cnt][x]) {
                    dp[cnt + 1][x ^ v] = true;
                }
            }
        }
    }

    bool seen[MAXX];
    memset(seen, 0, sizeof(seen));


    for (int i = 0; i < numsSize; i++) {
        seen[nums[i]] = true;
    }


    for (int x = 0; x < MAXX; x++) {
        if (dp[3][x]) {
            seen[x] = true;
        }
    }

    int ans = 0;
    for (int x = 0; x < MAXX; x++) {
        if (seen[x]) ans++;
    }

    return ans;
}
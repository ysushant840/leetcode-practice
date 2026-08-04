/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    int min = nums[0];
    int max = nums[numsSize - 1];

    // Maximum possible missing elements
    int *ans = (int *)malloc((max - min + 1) * sizeof(int));
    int idx = 0;

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = nums[i] + 1; j < nums[i + 1]; j++) {
            ans[idx++] = j;
        }
    }

    *returnSize = idx;
    return ans;
}
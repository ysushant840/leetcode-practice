void backtrack(int* candidates, int candidatesSize, int target, int start,
               int* path, int pathSize,
               int*** result, int* returnSize,
               int** returnColumnSizes) {

    if (target == 0) {
        (*result) = realloc((*result), ((*returnSize) + 1) * sizeof(int*));
        (*returnColumnSizes) = realloc((*returnColumnSizes),
                                       ((*returnSize) + 1) * sizeof(int));

        (*result)[*returnSize] = malloc(pathSize * sizeof(int));
        memcpy((*result)[*returnSize], path, pathSize * sizeof(int));

        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            break;

        path[pathSize] = candidates[i];
        backtrack(candidates, candidatesSize,
                  target - candidates[i], i + 1,
                  path, pathSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** combinationSum2(int* candidates, int candidatesSize, int target,
                      int* returnSize, int** returnColumnSizes) {

    qsort(candidates, candidatesSize, sizeof(int), cmp);

    int **result = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;

    int path[100];

    backtrack(candidates, candidatesSize, target, 0,
              path, 0,
              &result, returnSize, returnColumnSizes);

    return result;
}
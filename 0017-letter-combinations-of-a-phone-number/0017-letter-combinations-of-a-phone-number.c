/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char *map[] = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

void backtrack(char *digits, int pos, char *temp, char **result, int *index) {
    if (digits[pos] == '\0') {
        temp[pos] = '\0';
        result[*index] = (char *)malloc(strlen(temp) + 1);
        strcpy(result[*index], temp);
        (*index)++;
        return;
    }

    char *letters = map[digits[pos] - '0'];
    for (int i = 0; letters[i] != '\0'; i++) {
        temp[pos] = letters[i];
        backtrack(digits, pos + 1, temp, result, index);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    if (digits == NULL || digits[0] == '\0') {
        *returnSize = 0;
        return NULL;
    }

    int total = 1;
    for (int i = 0; digits[i] != '\0'; i++) {
        total *= strlen(map[digits[i] - '0']);
    }

    char **result = (char **)malloc(total * sizeof(char *));
    char temp[5];
    int index = 0;

    backtrack(digits, 0, temp, result, &index);

    *returnSize = index;
    return result;
}
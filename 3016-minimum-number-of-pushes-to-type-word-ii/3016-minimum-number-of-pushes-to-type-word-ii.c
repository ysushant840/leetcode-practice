#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);   // Descending order
}

int minimumPushes(char* word) {
    int freq[26] = {0};

    // Count frequency of each character
    for (int i = 0; word[i] != '\0'; i++) {
        freq[word[i] - 'a']++;
    }

    // Sort frequencies in descending order
    qsort(freq, 26, sizeof(int), cmp);

    int ans = 0;

    // Assign costs
    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0)
            break;
        ans += freq[i] * (i / 8 + 1);
    }

    return ans;
}
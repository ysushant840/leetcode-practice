
char* smallestPalindrome(char* s) {
    int freq[26] = {0};
    int n = strlen(s);

    // Count frequency
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    // Allocate memory for answer
    char *ans = (char *)malloc((n + 1) * sizeof(char));

    int left = 0;
    int right = n - 1;
    char mid = '\0';

    // Build palindrome
    for (int i = 0; i < 26; i++) {
        while (freq[i] >= 2) {
            ans[left++] = 'a' + i;
            ans[right--] = 'a' + i;
            freq[i] -= 2;
        }
        if (freq[i] == 1) {
            mid = 'a' + i;
        }
    }

    // Place middle character (if any)
    if (mid != '\0') {
        ans[left] = mid;
    }

    ans[n] = '\0';
    return ans;
}
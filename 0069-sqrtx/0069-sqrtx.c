int mySqrt(int x) {
    if (x == 0 || x == 1)
        return x;

    long long low = 1, high = x;
    int ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long square = mid * mid;

        if (square == x)
            return (int)mid;
        else if (square < x) {
            ans = (int)mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}
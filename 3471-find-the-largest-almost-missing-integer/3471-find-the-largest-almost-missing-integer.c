int largestInteger(int* nums, int numsSize, int k) {
    int subarray_counts[51] = {0};
    for (int i = 0; i <= numsSize - k; i++) {
        
        int seen_in_current[51] = {0};
        for (int j = i; j < i + k; j++) {
            int num = nums[j];
            
           
            if (seen_in_current[num] == 0) {
                seen_in_current[num] = 1; 
                subarray_counts[num]++;    
            }
        }
    }

    
    int largest_almost_missing = -1;
    for (int num = 0; num <= 50; num++) {
        if (subarray_counts[num] == 1) {
            if (num > largest_almost_missing) {
                largest_almost_missing = num;
            }
        }
    }

    return largest_almost_missing;
}

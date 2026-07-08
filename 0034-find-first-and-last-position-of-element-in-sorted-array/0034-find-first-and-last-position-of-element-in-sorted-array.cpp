class Solution {
public:

    int firstOcc(vector<int>& nums, int target) {

        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;

        while (s <= e) {

            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                ans = mid;
                e = mid - 1;
            }
            else if (nums[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return ans;
    }

    int lastOcc(vector<int>& nums, int target) {

        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;

        while (s <= e) {

            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                ans = mid;
                s = mid + 1;
            }
            else if (nums[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans;

        ans.push_back(firstOcc(nums, target));
        ans.push_back(lastOcc(nums, target));

        return ans;
    }
};
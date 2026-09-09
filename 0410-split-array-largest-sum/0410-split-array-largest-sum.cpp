class Solution {
private:
    int findSum(vector<int>& nums, int x, int k) {
        int count = 1;
        int arrsum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (arrsum + nums[i] <= x) {
                arrsum += nums[i];
            } else {
                count++;
                arrsum = nums[i];
            }
        }
        return count;
    }

public:
    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for (int i = 0; i < nums.size(); i++) {
            high += nums[i];
        }

        while (low <= high) {
            int mid = (low + high) / 2;
            if (findSum(nums, mid, k) <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
class Solution {
private:
    int atMost(vector<int>& nums, int goal) {
        if(goal < 0) return 0;

        int l = 0;
        int r = 0;
        int sum = 0;
        int ans = 0;

        while (r < nums.size()) {
            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal) - atMost(nums,goal - 1);
    }
};
class Solution {
private:
    int findDiv(vector<int>& nums, int k, int threshold) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += ceil((double)nums[i] / k);
        }

        return sum;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        while (low <= high) {

            int mid = (low + high) / 2;

            if (findDiv(nums, mid, threshold) <= threshold) {
                
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
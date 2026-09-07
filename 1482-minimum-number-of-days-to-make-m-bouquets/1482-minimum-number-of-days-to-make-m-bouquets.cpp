class Solution {
private:
    bool possible(vector<int>& bloomDay, int day, int k, int m){
        long long bouquets = 0;
        long long count = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
            }
            else{
                bouquets += count/k;
                count = 0;
            }
        }
        bouquets += count/k;

        return bouquets >= m;

    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        int low  = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low <= high){
            int mid = low + (high - low)/2;

            if( 1LL*  m * k > n ) return -1;

            if(possible(bloomDay,mid,k,m)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};
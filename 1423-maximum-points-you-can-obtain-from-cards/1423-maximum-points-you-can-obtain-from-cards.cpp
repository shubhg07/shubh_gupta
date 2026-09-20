class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int maxsum = 0;
        int lsum = 0;
        int rsum = 0;

        for(int i = 0; i < k; i++){
             lsum += cardPoints[i];
        }
        maxsum = lsum;
        int rind = cardPoints.size()-1;
        int lind = k-1;
        while(lsum != 0){
            lsum -= cardPoints[lind--];
            rsum += cardPoints[rind--];
            int totalsum = lsum + rsum;
            maxsum = max(maxsum,totalsum);
        }
        return maxsum;
    }
};
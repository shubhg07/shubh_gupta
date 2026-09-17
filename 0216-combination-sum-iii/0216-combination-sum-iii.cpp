class Solution {
private:
    void help(int num,vector<int>&ds, vector<vector<int>>&ans,int k , int n){
        
        if(n==0 && ds.size() == k){
            ans.push_back(ds);
            return;
        }
        if(n < 0){
            return;
        }
        
            for(int i = num; i < 10; i++){

            ds.push_back(i);
            help(i+1,ds,ans,k,n-i);
            ds.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        help(1,ds,ans,k,n);
        return ans;
    }
};
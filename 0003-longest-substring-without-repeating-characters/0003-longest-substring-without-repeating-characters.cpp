class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxlen = 0;
        unordered_map<char,int>mp;


        while(right < s.size()){
            if(mp[s[right]] != 1){
                mp[s[right]] = 1;
                maxlen = max(maxlen, right-left+1);
                right++;
            }
            else{
                while(s[left] != s[right]){
                    mp.erase(s[left]);                    
                    left++;
                }

                mp.erase(s[left]);
                left++;
            }
        }
    return maxlen;
    }
};
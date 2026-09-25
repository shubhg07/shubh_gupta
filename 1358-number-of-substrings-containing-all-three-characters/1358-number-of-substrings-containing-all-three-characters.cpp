class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<char,int> mp;  //ele , freq
        //for (int i = 0; i < s.size(); i++){
        //    mp[s[i]]++;
        //}
        while (r < s.size()) {
            mp[s[r]]++;

            while (mp.size() == 3){
                ans = ans + 1;
                ans += s.size() - r - 1;
                mp[s[l]]--;

                if (mp[s[l]] == 0){
                    mp.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};
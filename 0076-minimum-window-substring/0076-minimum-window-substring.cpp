class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256,0);
        int l = 0;
        int r = 0;
        int minlen = INT_MAX;
        int startI = -1;
        int count = 0;

        for (int i = 0; i < t.size(); i++){
            hash[t[i]-'A']++;
        }

        while (r < s.size()){
            if (hash[s[r]-'A'] > 0){
                count++;
            }

            hash[s[r]-'A']--;
            
            while (count == t.size()) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    startI = l;
                }
                hash[s[l]-'A']++;
                
                if (hash[s[l] - 'A'] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }
        return startI == -1 ? "" : s.substr(startI,minlen);
    }
};
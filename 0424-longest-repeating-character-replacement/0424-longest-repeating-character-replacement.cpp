class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxfreq = 0;
        int maxlen = 0;
        int len = 0;
        unordered_map<char, int> mp;

        while (r < s.size()) {
            mp[s[r]]++;
            maxfreq = max(maxfreq, mp[s[r]]);
            len = r - l + 1;

            if (len - maxfreq > k) {
                while (len - maxfreq > k) {
                    mp[s[l]]--;
                    l++;
                    len = r - l + 1;
                }
            }
            maxlen = max(maxlen, len);
            r++;
        }
        return maxlen;
    }
};
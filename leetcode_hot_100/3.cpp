class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos [256] = {0};
        int start = 0;
        int end = 0;
        int len, max_len = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (pos[s[i]] > start)
            {
                start = pos[s[i]];
            }
            len = i - start + 1;
            if (len > max_len)
                max_len = len;
            pos[s[i]] = i + 1;
            //cout <<start<<' '<<i<<' '<<len<<' '<<pos[s[i]]<<endl;
        }
        return max_len;
    }
};
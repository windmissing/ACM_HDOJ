class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0, j;
        string ret;
        for(int i = 0; i < s.length(); i++)
        {
            //int cur_len = 1;
            for (j = 0; i+j < s.length(); j++)
            {
                if (i < j || s[i-j]!=s[i+j])
                    break;
            }
            //cout<<i<<' '<<j<<endl;
            if (2*j-1 > max_len){
                max_len=2*j-1;
                ret = string(s, i-j+1, max_len);
                //cout<<ret<<endl;
                }
        }
        for(int i = 0; i < s.length(); i++)
        {
            //int cur_len = 1;
            for (j = 1; i+j < s.length(); j++)
            {
                if (i < j-1 || s[i-j+1]!=s[i+j])
                    break;
            }
            if (2*j-2 > max_len){
                max_len = 2 * j-2;
                ret = string(s, i-j+2, max_len);
                }
        }
        return ret;
    }
};
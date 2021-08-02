#include <string>
#include <vector>
struct node
{
    string str;
    bool once;
};

// fix_size: 固定的字符个数
// star_size: *的个数
// max_star_size: *总共代表的字符个数
// curr_star_size: 当前*已经代表的字符个数

class Solution {
public:
    vector<int> ans;
    int fix_size = 0;
    int star_size = 0;
    vector<node> V;
    string generateStr(vector<node> V, vector<int> ans)
    {
        //for(int i = 0; i < ans.size(); i++)
        //    cout<<ans[i]<<endl;
        int cnt = 0;
        string ret = "";
        for(int i = 0; i < V.size(); i++)
        {

            if(V[i].once)
                ret = ret + V[i].str;
            else if (cnt == ans.size())
                break;
            else
                ret = ret + string(ans[cnt++], V[i].str[0]);
        }
        return ret;
    }

    bool compare(string s1, string s2)
    {
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != '.' && s1[i] != s2[i])
                return false;
        }
        return true;
    }
    bool bfs(string s, int max_star_size, int curr_star_size, int curr_ceil)
    {
        //cout<<"bfs curr_size = "<<curr_star_size<<", curr_ceil = "<< curr_ceil
        //    <<", star_size = " << star_size<<endl;
        if (curr_ceil == star_size)
        {
            if (curr_star_size < max_star_size)
                return false; 
        }
        string gen = generateStr(V, ans);
        cout<<"gen = "<<gen<<endl;
        bool ret = compare(gen, s);
        if (! ret || (curr_ceil == star_size))
            return ret;
        for (int i = 0; i+curr_star_size <= max_star_size; i++)
        {
            ans.push_back(i);
            bool ret = bfs(s, max_star_size, i+curr_star_size, curr_ceil+1);
            if (ret)
                return ret;
            ans.pop_back();
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int start = 0;
        for(int i = 0; i < p.length(); i++)
        {
            if(p[i] == '*')
            {
                if (start < i-1)
                {
                    string str_temp(p, start, i-1-start);
                    node n{str_temp, true};
                    V.push_back(n);
                    fix_size += str_temp.length();
                }
                start = i + 1;
                string str_temp(p, i-1, 1);
                node n{str_temp, false};
                if (V.size() > 0)
                {
                    node last = V.back();
                    if (last.once == false && last.str == str_temp)
                        continue;
                }
                    V.push_back(n);

                    star_size++;
            }
        }
        if (start < p.length())
        {
            string str_temp(p, start, p.length()-start);
            node n{str_temp, true};
            V.push_back(n);
            fix_size += str_temp.length();
        }
        for(int i = 0; i < V.size(); i++)
        {
            cout<<V[i].str<<' '<<V[i].once<<endl;
        }
        int max_star_size = s.length() - fix_size;
        if (max_star_size < 0)
            return false;
        if (max_star_size > 0 && star_size == 0)
            return false;
        //cout<<"max_star_size = "<<max_star_size<<endl;
        bool ret = bfs(s, max_star_size, 0, 0);
        return ret;
        //return false;
    }
};
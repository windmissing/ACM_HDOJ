/*并查集的应用，注意点的个数为0的时候，注意输入*/
#include <iostream>
#include "UFS.h"
using namespace std;
 
UFS ufs;
bool flag[MAXN]={0}, f;
int cnt_e, cnt_v;
void init();
int main()
{
    int n,m;
	init();
    while(cin>>n>>m)
    {
        if(m==-1&&n==-1)return 0;
        if(m==0&&n==0)
        {
            getchar();getchar();
			/*条件：1.ufs不冲突2.v=e+1(v=0时例外)*/
            if(f) cout<<"No"<<endl;
            else if(cnt_v==0)cout<<"Yes"<<endl;
            else if(cnt_v!=cnt_e+1)cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
			init();
        }
        else
        {
            if(flag[m] == 0)
			{
				flag[m] = 1;
				cnt_v++;
			}
			if(flag[n] == 0)
			{
				flag[n] = 1;
				cnt_v++;
			}
			m = ufs.Find(m);
			n = ufs.Find(n);
            if(m==n) f=1;
            else
			{
				ufs.Union(m, n);
				cnt_e++;
			}
        }
    }
    return 0;
}
void init()
{
	ufs.clear();
	memset(flag, 0, sizeof(flag));
	f = 0;
	cnt_v = 0;
	cnt_e = 0;
}
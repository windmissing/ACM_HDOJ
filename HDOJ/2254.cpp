//最原始的矩阵应用，不解释
#include "Mat.h"
#include <iostream>
#include<map>
#include<string>
using namespace std;
 
map<string, int> M;
Mat mat, temp1, temp2;
int main()
{
	int n, cnt, k, t1, t2, ans, a1, a2;
	string p1, p2, v1, v2;
	mod = 2008;
 
	while(cin>>n)
	{
		mat.clear();
		M.clear();
		cnt = 1;
		while(n--)
		{
			cin>>p1>>p2;
			if(M[p1] == 0)
				M[p1] = cnt++;
			if(M[p2] == 0)
				M[p2] = cnt++;
			mat.s[M[p1]][M[p2]]++;
		}
		mat.sizei = cnt;
		mat.sizej = cnt;
 
		cin>>k;
		while(k--)
		{
			cin>>v1>>v2>>t1>>t2;
			if(M[v1]==0||M[v2]==0||(t1==0&&t2==0))  
			{
                cout<<0<<endl;
				continue;
			}
			if(t1>t2)
				swap(t1, t2);
			temp1 = mat;temp2 = mat;
			temp1.solve(t2);a1 = temp1.s[M[v1]][M[v2]];
			if(t1 <= 1) a2 = 0;
			else
			{
				temp2.solve(t1-1);
				a2 = temp2.s[M[v1]][M[v2]];
			}
			ans = (a1 - a2 + mod ) % mod;
			cout<<ans<<endl;
		}
	}
	return 0;
}

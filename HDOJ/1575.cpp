#include "Mat.h"
#include <iostream>
using namespace std;
 
int main()
{
	int t,n , ans, k, i, j;
	Mat mat;
	mod = 9973;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		mat.ReSize(n, n, 0);
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
				cin>>mat.s[i][j];
		}
		mat.Er_work(k);
		ans = 0;
		for(i = 0; i < n; i++)
			ans = ans + mat.s[i][i];
		cout<<ans%mod<<endl;
	}
	return 0;
}
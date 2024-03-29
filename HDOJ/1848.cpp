/*HDU1847博弈SG函数
3.可选步数为一系列不连续的数，用GetSG(计算)
最终结果是所有SG值异或的结果
*/
#include "SG.h"
#include<iostream>
using namespace std;
int Array[MAX];
int main()
{
	int n, i, m, p, ans;
	Array[1] = 1;
	for(i = 2; ; i++)
	{
		Array[i] = Array[i-1] + Array[i-2];
		if(Array[i] > MAX)
			break;
	}
	Array[0] = i - 1;
	GetSG(Array);
	while(cin>>m>>n>>p && m)
	{
		ans = SG[m]^SG[n]^SG[p];
		if(ans == 0) cout<<"Nacci"<<endl;
		else cout<<"Fibo"<<endl;                 
	}             
	return 0;   
}
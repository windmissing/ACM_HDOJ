/*
HDU1846博弈
每走一步可以取走1…m个石子，则SG(x) = x % (m+1)
SG(x) != 0 为必胜点
*/
#include<iostream>
using namespace std;
int main()
{
	int c,m,n,i,j;
	cin>>c;
	while(c--)
	{
		cin>>m>>n;	
		int ans = m % (n+1);
		if(ans || m < n)
			cout<<"first"<<endl;
		else
			cout<<"second"<<endl;
	}               
	return 0;   
}
/*HDU1847博弈SG函数
3.可选步数为一系列不连续的数，用GetSG(计算)
*/
#include "SG.h"
#include<iostream>
using namespace std;
int Array[MAX];
int main()
{
	int n,i,j = 1;
	for(i=1,j=1; j <= MAX;i++,j=j*2)
		Array[i] = j;
	Array[0] = i - 1;
	GetSG(Array);
	while(cin>>n)
	{
		if(SG[n])
			cout<<"Kiki"<<endl;
		else
			cout<<"Cici"<<endl;
	}               
	return 0;   
}
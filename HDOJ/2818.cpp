//很祼的并查集
#include "UnionFindSet.h"
#include <iostream>
using namespace std;
 
int main()
{
	UFS ufs;
    int P, X, Y;
	char ch;
	cin>>P;
	while(P--)
	{
		cin>>ch;
		if(ch == 'M')
		{
			cin>>X>>Y;
			ufs.Union(X,Y,-1);
		}
		else
		{
			cin>>X;
			ufs.Find(X); 
			cout<<ufs.depth[X]<<endl;
		}
	}
	return 0;
}

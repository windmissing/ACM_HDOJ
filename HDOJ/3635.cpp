//很祼的并查集
#include "UnionFindSet.h"
#include <iostream>
using namespace std;
 
int main()  
{ 
	UFS ufs;
	int t,Case, n,q,a,b;  
	char ch;
	scanf("%d", &t);
	for(Case = 1; Case <= t; Case++)  
	{ 
		printf("Case %d:\n",Case);
		scanf("%d%d", &n,&q);  
		ufs.n = n;
		ufs.clear();
		while(q--)  
		{  
			getchar();  
			scanf("%c",&ch);  
			if(ch == 'T')  
			{  
				scanf("%d%d", &a,&b);  
				ufs.Union(a, b, 1);  
			}  
			else  
			{
				cin>>a; 
				int tmp = ufs.Find(a); 
				printf("%d %d %d\n", tmp, ufs.rank[tmp], ufs.depth[a]);  
			}  
		}  
	}  
	return 0;  
}  

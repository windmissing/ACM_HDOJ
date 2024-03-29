//很纯的二维树状数组
#include "TreeArray.h"
#include <iostream>
using namespace std;
 
int main()
{
	bool flag[MAX][MAX];
	TreeArray ta(2);
	int m,x1,x2,y1,y2;  
	char op;
 
	while(scanf("%d",&m)!=EOF)
	{
		memset(flag, 0, sizeof(flag));    
		ta.clear();
		while(m--)
		{
			getchar();
			scanf("%c", &op);
			if(op == 'B')
			{
				scanf("%d%d",&x1,&x2); 
				x1++; x2++;  
				if(flag[x1][x2])
					continue;  
				flag[x1][x2] = 1;  
				ta.modify(x1,x2,1);  
			}
			else if(op=='D')
			{
				scanf("%d%d",&x1,&x2);  
				x1++; x2++;  
				if(!flag[x1][x2])
					continue;  
				flag[x1][x2] = 0;  
				ta.modify(x1,x2,-1);  
			}
			else
			{
				scanf("%d%d%d%d",&x1,&x2,&y1,&y2);  
				x1++,x2++,y1++,y2++;  
				if(x1>x2)swap(x1,x2); 
				if(y1>y2)swap(y1,y2);    
				printf("%d\n",ta.sum(x2,y2)+ta.sum(x1-1,y1-1)-ta.sum(x1-1,y2)-ta.sum(x2,y1-1));  
			}  
		}  
	}  
    return 0;     
}
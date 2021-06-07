#include <iostream>
#include "TreeArray.h"
using namespace std;
int main()
{
    int t,cnt,i, n, b, c;
	char a[6];
	//调用 树状数组模版
	TreeArray Tra(1);
    scanf("%d",&t);
    for(cnt=1;cnt<=t;cnt++)
    {
		//树状数组初始化
		Tra.clear();
        printf("Case %d:\n",cnt);
		//输入数组的初始值
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            Tra.modify(i,x);
        }
		//动态修改和求和
        while(scanf("%s",a))
        {
            if(strcmp(a,"End")==0)break;
            scanf("%d%d",&b,&c);
            if(strcmp(a,"Add")==0)Tra.modify(b, c);
            else if(strcmp(a,"Sub")==0)Tra.modify(b, -c);
            else printf("%d\n",Tra.sum(c)-Tra.sum(b-1));
        }
    }
    return 0;
}


#include <iostream>
#include <string.h>
using namespace std;
 
int word[11][11],f[10001],bag,n;//bag表示背包的总容量 
 
void ZeroOnePack(int cost,int weight);//01背包
void CompletePack(int cost,int weight);//完全背包
void MultiplePack(int cost,int weight,int count);//多重背包 
int main()
{
	int i,j,value,complexity;
	
	char str[15];
	while(scanf("%d%d",&n,&bag) != EOF)
	{
		memset(word,0,sizeof(word));
		for(i = 1; i <= n; i++)
		{
			scanf("%s%d%d",str,&value,&complexity);
			word[complexity][value]++;
		}
		memset(f,0,sizeof(f));
		for(int i=0;i<11;i++)
			for(int j=0;j<11;j++)
				if(word[i][j])
					MultiplePack(i,j,word[i][j]);
        printf("%d\n",f[bag]);
    }
	return 0;
}
 
void ZeroOnePack(int cost,int weight){//01背包 
     for(int i=bag;i>=cost;i--)
        if(f[i]<f[i-cost]+weight)
           f[i]=f[i-cost]+weight;
}
void CompletePack(int cost,int weight){//完全背包 
     for(int i=cost;i<=bag;i++)
        if(f[i]<f[i-cost]+weight)
           f[i]=f[i-cost]+weight;
}
void MultiplePack(int cost,int weight,int count){//多重背包 
     if(cost*count>=bag)//相对于背包的容量，它的数量是无限多的
        CompletePack(cost,weight);
     else{
          int k=1; //这里就是应用了二进制压缩多重背包的思想 
          while(k<count){//一次取k个
                ZeroOnePack(k*cost,k*weight);
                count-=k;
                k*=2;
          }
          ZeroOnePack(count*cost,count*weight);
     }
}

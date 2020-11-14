```c++
/* 
UnionFindSet.h 
并查集，非递归方法，含路径压缩，数组从0开始
合并时，前者合并入后者，不区分大小
*/ 
#include <iostream>   
using namespace std;  
  
#define MAXN 30005  
  
class UFS
{
public:
	int n;
	int father[MAXN+1];//集合根结点
	int rank[MAXN+1];  //集合中点的个数
	int depth[MAXN+1]; //每个结点改变一次所属的集合，增加一些值
public:
	UFS(int size = MAXN);
	void clear();
	int Find(int x);
	//a并入b中，不区分大小
	//value表示：如果a并入b中，a中r所有元素能获得的值
	void Union(int a, int b, int value = 0);
};
UFS::UFS(int size):n(size)
{
	//必须从0开始
	for(int i = 0; i <= n; i++)  
	{  
		father[i] = i;  
		rank[i] = 1;  
		depth[i] = 0;  
	}
}
void UFS::clear()
{
	for(int i = 0; i <= n; i++)  
	{  
		father[i] = i;  
		rank[i] = 1;  
		depth[i] = 0;  
	}
}
int UFS::Find(int x)
{
	int temp = x,sum = 0,ans;  
    while(temp != father[temp]) {  
       sum = sum + depth[temp];  
       temp = father[temp];  
    }  
    ans = temp;  
    while(x != ans) {  
       sum -= depth[x];  
       depth[x] += sum;  
       temp = father[x];  
       father[x] = ans;  
       x = temp;  
    }  
    return ans;
}
void UFS::Union(int a, int b,int value)
{
	int x = Find(a);  
    int y = Find(b);
	if(x == y)
		return ;
	if(value >= 0)
		depth[x] = value;
	else depth[x] = rank[y];
	rank[y] += rank[x];  
	father[x] = y;  
}
```
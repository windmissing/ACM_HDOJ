/*
2.可选步数为任意步，SG(x) = x; 
本题中每一堆都可以选任意个，所以每一堆的SG值都是所剩余的个数。
最后结果是所有堆的SG值异或的结果。令ans = 所有堆的SG值异或的结果
如果ans == 0，则是必败点。
如果ans != 0，使取后结果为0的策略是必胜策略
具体怎么取呢？
每一堆的数值与ans相异或，所得的结果就是这一堆可以取的数量。
但是，如要这一堆数量没有这么多，就不可以这么取
*/
#include <iostream>  
using namespace std;  
int value[101];  
int main ()  
{  
    int n,sum,count,i;  
    while (cin>>n && n)  
    {  
        sum=0;  
        for (i=0;i<n;i++)  
        {  
            cin>>value[i];  
            sum^=value[i];  
        }  
        count=0;  
        for (i=0;i<n;i++)  
        {  
            sum^=value[i];  
            if (value[i]>sum) count++;  
            sum^=value[i];  
        }  
        cout<<count<<endl;  
    }  
    return 0;  
}
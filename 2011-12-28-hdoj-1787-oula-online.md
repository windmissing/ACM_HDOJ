欧拉函数的介绍：  

φ函数的值通式：φ(x)=x(1-1/p1)(1-1/p2)(1-1/p3)(1-1/p4)…..(1-1/pn),
其中p1, p2……pn为x的所有质因数，x是不为0的整数。
(注意：每种质因数只一个。比如12=2*2*3　　那么φ（12）=12*（1-1/2）*(1-1/3)=4)
若n是质数p的k次幂，φ(n)=p^k-p^(k-1)=(p-1)p^(k-1)，因为除了p的倍数外，其他数都跟n互质。
φ(1)=1（唯一和1互质的数就是1本身）。
欧拉函数是积性函数——若m,n互质，φ(mn)=φ(m)φ(n)。
特殊性质：当n为奇数时，φ(2n)=φ(n), 证明于上述类似。

```c++
#include <iostream>
using namespace std;
int eo(int m)
{
   int i,s=1;
   for(i=2;i*i<=m;i++)
   {
       if(m%i==0)
       {
           m/=i;
           s*=i-1;
           while(m%i==0)
           {
               m/=i;
               s*=i;
           }
       }
   }
   if(m>1)
       s*=m-1;
   return s;
}
int main()
{
   int m;
   while(cin>>m && m)
       cout<<m-1-eo(m)<<endl;
   return 0;
}
```
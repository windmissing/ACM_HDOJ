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
/*1.可选步数为1-m的连续整数，直接取模即可，SG(x) = x % (m+1); */
#include <iostream>
using namespace std;
int main()
{
    int t,i,m,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n%(m+1)==0)cout<<"Rabbit"<<endl;
        else cout<<"Grass"<<endl;
    }
    return 0;
}
/*不能算是并查集，只是用了路径压缩和树的特点，
和1272的区别在于它是有向图，它的父结点是固定的*/
#include <iostream>
using namespace std;
int main()
{
    int n,m,k=0,s[100005]={0},j=0,i,big;
    bool f=0;
    bool flag[100005]={0};
    while(cin>>n>>m)
    {
        if(m==-1&&n==-1)return 0;
        if(m==0&&n==0)
        {
            k++;
            int c=0;
            for(i=1;i<=big;i++){if(flag[i]){c++;flag[i]=0;s[i]=0;}}
            if(f) cout<<"Case "<<k<<" is not a tree."<<endl;
            else if(c==0)cout<<"Case "<<k<<" is a tree."<<endl;
            else if(c!=j+1)cout<<"Case "<<k<<" is not a tree."<<endl;
            else cout<<"Case "<<k<<" is a tree."<<endl;
            j=0;
            f=0;
            big=0;
        }
        else
        {
            j++;
            flag[n]=flag[m]=1;
            if((m>n?m:n)>big)big=(m>n?m:n);
			//如果已经有父结点，但是父结点不是n，那就是不树了
            if(s[m]!=0&&s[m]!=n)f=1;
            else s[m]=n;
        }
    }
    return 0;
}

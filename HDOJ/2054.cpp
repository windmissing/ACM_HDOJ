//2054 模拟题
#include <iostream>
using namespace std;
int main()
{
    char p(char x[100000]);
    int j,i;
    char a[100000],b[100000];
    while(cin>>a>>b)
    {
		//处理类似于3.000这样的情况
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='.')
            {
                int l=strlen(a);
                int t=l-1;
                while(a[t]=='0')
                {
                    a[t]='\0';
                    t--;
                }
                if(a[t]=='.'){a[t]='\0';}
            }
        }
        for(i=0;i<strlen(b);i++)
        {
            if(b[i]=='.')
            {
                int l=strlen(b);
                int t=l-1;
                while(b[t]=='0')
                {
                    b[t]='\0';
                    t--;
                }
                if(b[t]=='.'){b[t]='\0';}
            }
        }
        bool x=1;
        j=0;
        while(a[j]!='\0'||b[j]!='\0')
        {
            if(a[j]!=b[j]) x=0;
            j++;
        }
        if(x==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
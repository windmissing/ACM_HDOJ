#include <iostream>   
#include <string>   
using namespace std;  
int n,m,a,b,cnt,father[2000000],s[1000041],ans;  
int find(int x);
void merge(int x,int y);
 
//固定根节点,n+1~n+n作为根节点,而1~n作为虚拟根节点(指向n+1~n+n),之后在增添n+n~n+n+m作为备用节点   
//删除时直接修改1~n指向的节点到n+n后的节点   
int main(){  
	int Case = 1, n, m, i, a, b, ans;  
	char ch;
	while(cin>>n>>m && (n||m))
	{  
		for(i = 0; i < n; i++)
			father[i] = i + n;
		for(i = n; i < n*2+m;i++)
			father[i] = i;
		cnt = 2 * n; ans = 0;
		memset(s, 0, sizeof(s));
		while(m--)
		{
			cin>>ch;
			if(ch == 'M')
			{
				cin>>a>>b;
				merge(a, b);
			}
			else
			{
				cin>>a;
				father[a] = cnt++;
			}
		}
		for(i = 0; i < n; i++)
		{
			int temp = find(i);
			if(s[temp] == 0)
			{
				ans++;
				s[temp] = 1;
			}
		}
		cout<<"Case #"<<Case<<": "<<ans<<endl;
		Case++;
	}  
	return 0;     
}  
int find(int x) {
    int temp = x,sum = 0,ans;
    while(temp != father[temp]) {
       temp = father[temp];
    }
	ans = temp;
    while(x != ans) {
       temp = father[x];
       father[x] = ans;
       x = temp;
    }
    return ans;
}
 
void merge(int a,int b)
{
	int x = find(a);
	int y = find(b);
	if(x < y)
		father[y] = x;
	else if(x > y)
		father[x] = y;
}
#include <iostream>
using namespace std;

const int MAXN = 105;
int N, M;   
bool map[MAXN][MAXN];
int xM[MAXN], yM[MAXN]; 
bool chk[MAXN];

bool SearchPath(int &u,bool &flag);
int MaxMatch();
bool Can();

int main()
{
    int i,a,b,K,ans,Case = 0;
	while(cin>>N>>M>>K)
    {
		//初始化
        N--;M--;Case++;
        memset(map,0,sizeof(map));
        for (i = 0; i < K; i++)
        {
			cin>>a>>b;
            map[--a][--b] = 1;
        }
		//二分匹配，求最大匹配数
        ans = MaxMatch();    
        int tmp,num = 0;
        for (int u = 0; u <= N; u++)
        {
			//是一条匹配边
            if (xM[u] != -1)
            {
				//删除这条匹配边
                tmp = xM[u];
                xM[u] = -1;
                yM[tmp] = -1;
                map[u][tmp] = 0;
				//是否找到新的增广路
                if (!Can())num++;
				//恢复这条边
                xM[u] = tmp;
                yM[tmp] = u;
                map[u][tmp] = 1;
            }
        }
		//输出结果
		cout<<"Board "<<Case<<" have "<<num<<" important blanks for "<<ans<<" chessmen."<<endl;
	}
    return 0;
}
//二分匹配，求最大匹配数，这个过程类似于DFS
int MaxMatch()
{
	//初始化
    int u, ret = 0 ;
    bool flag = true;
    memset(xM, -1, sizeof (xM));
    memset(yM, -1, sizeof (yM));
    //对每个未匹配的顶点进行尝试匹配
    for(u = 0; u <= N; u++)
    {
		//若顶点还没有找到匹配
        if(xM[u] == -1)
        {
			//初始化
            memset(chk, false, sizeof (chk));
			//尝试匹配，若成功，计数+1
            if(SearchPath(u,flag)) ret++;
        }
    }
    return ret;
}
//尝试匹配
bool SearchPath(int &u,bool &flag)
{
    int v;
    for(v = 0; v <= M; v++)
    {
        if(map[u][v] && !chk[v])
        {
            chk[v] = true;
            if(yM[v] == -1 || SearchPath(yM[v],flag))
            {
                if (flag)
                {
                    yM[v] = u; xM[u] = v;
                }
                return true ;
            }
        }
    }
    return false ;
}
//是否找到新的增广路
bool Can()
{
    int u;
    bool flag = false;  
	//以对所有未匹配的顶点进行尝试匹配
    for(u = 0; u <= N; u++)
    {
        if(xM[u] == -1)
        {
            memset(chk, false, sizeof (chk));
			//找到一条增广路
            if(SearchPath(u,flag)) 
                return true;
        }
    }
    return false;
}
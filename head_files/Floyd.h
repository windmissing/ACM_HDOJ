/*
Floyd.h
时间复杂库：O(N^3)
用途：
1.判断中否联通
s[a][b] != inf -> 联通
s[a][b] == inf -> 不联通
2.两点间最短路径长度
s[a][b] != inf -> 最短路径长度 = s[a][b]
s[a][b] == inf -> 不联通
3.两点间的最短路径的跳数
初始化时所有路径长度设为单位长度
s[a][b] != inf -> 跳数 = s[a][b]
s[a][b] == inf -> 不联通
*/
#include <iostream>  
using namespace std;  
#define MAX 100
#define inf 0x3FFFFFFF
 
class Floyd
{
public:
	int n;
	//记录两点间最短路径的长度
	int s[MAX][MAX];
	//记录最短路径
	int path[MAX][MAX];
public:
	Floyd(int size = MAX);
	void clear();
	void ShortestPath();
};
Floyd::Floyd(int size):n(size)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i = j) s[i][j] = 0;
			else s[i][j] = inf;
			path[i][j] = j;
		}
	}
}
Floyd::clear()
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(i = j) s[i][j] = 0;
			else s[i][j] = inf;
			path[i][j] = j;
		}
	}
}
void Floyd::ShortestPath()
{
	int i,j,k;  
    for(k = 0; k < MAX; k++)  
    {  
        for(i = 0; i < MAX; i++)  
        {  
            for(j = 0; j < MAX; j++)  
            {  
                if(s[i][j] > s[i][k] + s[k][j]))
                {
                    s[i][j] = s[i][k] + s[k][j];     /*最短路径值*/ 
                    path[i][j] = k;     /*最短路径*/ 
                }  
            }  
        }  
    } 
}

#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 301;
int val[maxn][maxn];
 
int M,N;
 
//RMQ 2D
int dp[maxn][maxn][9][9];
void RMQ_2D_PRE()
{
	for(int row = 1; row <= N; row++)
		for(int col = 1; col <=M; col++)
			dp[row][col][0][0] = val[row][col];
    int mx = log(double(N)) / log(2.0);
    int my = log(double(M)) / log(2.0);
    for(int i=0; i<= mx; i++)
	{
        for(int j = 0; j<=my; j++)
        {
			if(i == 0 && j ==0) continue;
            for(int row = 1; row+(1<<i)-1 <= N; row++)
			{
				for(int col = 1; col+(1<<j)-1 <= M; col++)
				{
					if(i == 0)//y轴二分
						dp[row][col][i][j]=max(dp[row][col][i][j-1],dp[row][col+(1<<(j-1))][i][j-1]);  
					else//x轴二分
						dp[row][col][i][j]=max(dp[row][col][i-1][j],dp[row+(1<<(i-1))][col][i-1][j]);  
				}
            }
		}
	}
}
int RMQ_2D(int x1,int x2,int y1,int y2)
{
	int kx = log(double(x2-x1+1)) / log(2.0);
    int ky = log(double(y2-y1+1)) / log(2.0);
	int m1 = dp[x1][y1][kx][ky];
	int m2 = dp[x2-(1<<kx)+1][y1][kx][ky];
	int m3 = dp[x1][y2-(1<<ky)+1][kx][ky];
	int m4 = dp[x2-(1<<kx)+1][y2-(1<<ky)+1][kx][ky];
    return max( max(m1,m2) , max(m3,m4));
}
//END
 
int  main()
{
	int Q,x1,y1,x2,y2,i,j;
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		for(i = 1; i <= N; i++)
			for(j = 1; j <= M; j++)
				scanf("%d",&val[i][j]);
        RMQ_2D_PRE();
		scanf("%d",&Q);
		while(Q--)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int ans = RMQ_2D(x1,x2,y1,y2);
			printf("%d",ans);
			if(ans == val[x1][y1] || ans == val[x2][y1] || ans == val[x1][y2] || ans == val[x2][y2])
				printf(" yes\n");
			else printf(" no\n");
		}
	}
    return 0;
}  

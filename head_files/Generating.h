// 普通母函数

struct node//用于存储每个元素的大小与数量
{
	int value;//大小
	int num;//数量
}lottery[100];

void Generating(int n, int sum)//母函数过程，n表示元素的个数，sum表示和的最大值
{
	int c1[1000] = {1};
	int c2[1000] = {0};
	int i, j, k;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j <= sum; j++)
		{
			for(k = 0; k+j<sum&&k<=lottery[i].num*lottery[i].time; k = k + lottery[i].time)
				c2[j+k] = c2[j+k] + c1[j];
		}
		for(j = 0; j <= sum; j++)
		{
			c1[j] = c2[j];
			c2[j] = 0;
		}
	}
}

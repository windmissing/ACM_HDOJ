#include <iostream>
using namespace std;
#define MAX 50005
#include "NiXuShu.h"
 
int main()
{
	int a[MAX], b[MAX];
	int n, i;
    while (scanf("%d", &n) == 1)
    {
		memset(a, 0, sizeof(a));
        int sum = 0;
        for (int i = 1; i <= n; i ++)
		{
            scanf ("%d", &a[i]);
			//如果使用归并排序来做，因为会改变数组的值，所以要另外开辟一个数组。
			//如果使用树状数组，则不需要这一步，直接调用
			b[i] = a[i];
		}
        sum = NiXuShu(b, n+1);
        int ans = sum;
        for (int i = 1; i <= n; i++)
        {
            sum = sum - a[i] + (n - a[i] - 1);
            ans = min(ans, sum);
        }
        printf("%d\n", ans);
    }
    return 0;
}
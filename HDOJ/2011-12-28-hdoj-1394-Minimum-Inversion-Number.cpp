    #include <stdio.h>  
    #define MAXN 10000  
      
    int c[MAXN],a[MAXN],n;  
      
    int min(int a,int b)  
    {  
        if (a < b) return a;  
        else return b;  
    }  
      
    int lowbit(int i)  
    {  
        return i & -i;  
    }  
      
      
    void update(int i,int x)  
    {  
        while (i <= n)  
        {  
            c[i] += x;  
            i += lowbit(i);  
        }  
    }  
      
    int getsum(int x)  
    {  
        int sum = 0;  
        while (x > 0)  
        {  
            sum += c[x];  
            x -= lowbit(x);  
        }  
        return sum;  
    }  
      
    int main()  
    {  
        while (scanf("%d", &n) == 1)  
        {  
            for (int i = 1; i <= n; i++)  
                c[i] = 0;  
            int sum = 0;  
            for (int i = 1; i <= n; i ++)  
            {  
                scanf ("%d", &a[i]);  
            }  
            for (int i = n; i >= 1; i --)  
            {  
                update (a[i] + 1, 1);  
                sum += getsum (a[i]);  
            }  
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
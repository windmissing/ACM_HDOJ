#include<iostream>
#include<string>
using namespace std;
#define N 1200
string s;
int n, sa[4*N], rank[N], height[N];
int buf[4*N], ct[N], sx[N], sax[N];
inline bool leq(int a, int b, int x, int y);
inline bool leq(int a, int b, int c, int x, int y, int z);
inline int geti(int t, int nx, int sa[]);
//基数排序
static void radix(int a[], int b[], int s[], int n, int k);
/*
倍增算法,构造后缀数组的最坏时间复杂度为O(nlogn)。
参数：
int *r：待排序的字符串放在 r 数组中 ， 从 r[0] 到 r[n-1] ， 长度为 n ， 且最大值小于 m 。
为了函数操作的方便，约定除r[n-1] 外所有的 r[i] 都大于 0, r[n-1]=0 。
int *sa：函数结束后，结果放在 sa 数组中，从 sa[0] 到 sa[n-1] 。 
*/
void suffix(int s[], int sa[], int n, int k);
/*
后缀数组 SA 是一个一维数组，它保存 1..n 的某个排列SA[1]，SA[2]，……，SA[n]，
并且保证 Suffix(SA[i]) < Suffix(SA[i+1]) ， 1 ≤ i<n 。
也就是将 S 的 n 个后缀从小到大进行排序之后把排好序的后缀的开头位置顺次放入 SA 中。 
*/
void makesa();
/*
名次数组 Rank[i] 保存的是 Suffix(i) 在所有后缀中从小到大 排列的 “ 名次 ” 。
容易看出，后缀数组和名次数组为互逆运算。
设字符串的长度为 n 。
为了方便比较大小，可以在字符串后面添加一个字符，这个字符没有在前面的字符中出现过，而且比前面的字符都要小。
在求出名次数组后，可以仅用 O(1) 的时间比较任意两个后缀的大小。
在求出后缀数组或名次数组中的其中一个以后，便可以用 O(n) 的时间求出另外一个。
任意两个后缀如果直接比较大小，最多需要比较字符 n 次，也就是说最迟在比较第 n 个字符时一定能分出 “ 胜负 ” 。 
*/
void getRank();
/*
对两个字符串u,v定义函数lcp(u,v)=max{i|u=iv}，也就是从头开始顺次比较u和v的对应字符，对应字符持续相等的最大位置，
称为这两个字符串的最长公共前缀。
对正整数i,j定义LCP(i,j)=lcp(Suffix(SA[i]),Suffix(SA[j]))，其中i,j均为1至n的整数。LCP(i,j)也就是后缀数组中第i个
和第j个后缀的最长公共前缀的长度。
定义一维数组height，令height[i]=LCP(i-1,i)，1<i≤n，并设height[1]=0。
*/
void lcp();
int main()
{
 
    while(cin>>s && s[0] != '#')
    {
		n = s.length() + 1;
        makesa();
        getRank();
        lcp();
		int ans = 0, minid, maxid;
		//枚举字串长度h
        for(int i = 1; i <= (n >> 1); i++)
        {
            minid = 1200, maxid = -1;
			//对于每一次的h，利用height数组，找出连续的height大于等于h的里面最左端和最右端得为之l和r。
            for(int j = 2; j < n; j++)
                if (height[j] >= i)
                {
                    if (sa[j - 1] < minid) minid = sa[j - 1];
                    if (sa[j - 1] > maxid) maxid = sa[j - 1];
                    if (sa[j] < minid) minid = sa[j];
                    if (sa[j] > maxid) maxid = sa[j];
                }
                else
                {
					//如果l + h - 1 < r的话，说明没有重叠，答案加1.
                    if (maxid != -1 && minid + i <= maxid) ans++;
                    minid = 1200, maxid = -1;
                }
			//如果l + h - 1 < r的话，说明没有重叠，答案加1.
            if (maxid != -1 && minid + i <= maxid) ans++;
        }
       cout<<ans<<endl;
    }
}
inline bool leq(int a, int b, int x, int y)
{
    return (a < x || a == x && b <= y);
}
inline bool leq(int a, int b, int c, int x, int y, int z)
{
    return (a < x || a == x && leq(b, c, y, z));
}
inline int geti(int t, int nx, int sa[])
{
    return (sa[t]<nx ? sa[t]*3+1 : (sa[t]-nx)*3+2);
}
//基数排序
static void radix(int a[], int b[], int s[], int n, int k)
{ // sort a[0..n-1] to b[0..n-1] with keys in 0..k from s
    int i, t, sum;
    memset(ct, 0, (k + 1) * sizeof(int));
    for (i = 0; i < n; ++i) ct[s[a[i]]]++;
    for (i = 0, sum = 0; i <= k; ++i)
    {
        t = ct[i]; ct[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++) b[ct[s[a[i]]]++] = a[i];
}
/*
倍增算法,构造后缀数组的最坏时间复杂度为O(nlogn)。
参数：
int *r：待排序的字符串放在 r 数组中 ， 从 r[0] 到 r[n-1] ， 长度为 n ， 且最大值小于 m 。
为了函数操作的方便，约定除r[n-1] 外所有的 r[i] 都大于 0, r[n-1]=0 。
int *sa：函数结束后，结果放在 sa 数组中，从 sa[0] 到 sa[n-1] 。 
*/
void suffix(int s[], int sa[], int n, int k)
{ // !!! require s[n] = s[n+1] = s[n+2] = 0, n >= 2.
    int i, j, e, p, t;
    int name = 0, cx = -1, cy = -1, cz = -1;
    int nx = (n+2)/3, ny = (n+1)/3, nz = n/3, nxz = nx+nz;
    int *syz = s + n + 3, *sayz = sa + n + 3;
    for (i=0, j=0; i < n + (nx - ny); i++)
    if (i%3 != 0) syz[j++] = i;
    radix(syz , sayz, s+2, nxz, k);
    radix(sayz, syz , s+1, nxz, k);
    radix(syz , sayz, s , nxz, k);
    for (i = 0; i < nxz; i++)
    {
        if (s[ sayz[i] ] != cx || s[ sayz[i] + 1 ] != cy ||s[ sayz[i] + 2 ] != cz)
        {
            name++; cx = s[ sayz[i] ];
            cy = s[ sayz[i] + 1 ]; cz = s[ sayz[i] + 2 ];
        }
        if (sayz[i] % 3 == 1) syz[ sayz[i] / 3 ] = name;
        else syz[ sayz[i]/3 + nx ] = name;
    }
    if (name < nxz)
    {
        suffix(syz, sayz, nxz, name);
        for (i = 0; i < nxz; i++) syz[sayz[i]] = i + 1;
    }
    else
    {
        for (i = 0; i < nxz; i++) sayz[syz[i] - 1] = i;
    }
    for (i = j = 0; i < nxz; i++)
    if (sayz[i] < nx) sx[j++] = 3 * sayz[i];
    radix(sx, sax, s, nx, k);
    for (p=0, t=nx-ny, e=0; e < n; e++)
    {
        i = geti(t, nx, sayz); j = sax[p];
        if ( sayz[t] < nx ?leq(s[i], syz[sayz[t]+nx], s[j], syz[j/3]) :
            leq(s[i], s[i+1], syz[sayz[t]-nx+1],
        s[j], s[j+1], syz[j/3+nx]) )
        {
            sa[e] = i;
            if (++t == nxz)
            {
                for (e++; p < nx; p++, e++)
                sa[e] = sax[p];
            }
        }
        else
        {
            sa[e] = j;
            if (++p == nx) for (++e; t < nxz; ++t, ++e)
            sa[e] = geti(t, nx, sayz);
        }
    }
}
/*
后缀数组 SA 是一个一维数组，它保存 1..n 的某个排列SA[1]，SA[2]，……，SA[n]，
并且保证 Suffix(SA[i]) < Suffix(SA[i+1]) ， 1 ≤ i<n 。
也就是将 S 的 n 个后缀从小到大进行排序之后把排好序的后缀的开头位置顺次放入 SA 中。 
*/
void makesa()
{
    memset(buf, 0, 4 * n * sizeof(int));
    memset(sa, 0, 4 * n * sizeof(int));
    for (int i=0; i<n; ++i) buf[i] = s[i] & 0xff;
    suffix(buf, sa, n, 255);
}
/*
名次数组 Rank[i] 保存的是 Suffix(i) 在所有后缀中从小到大 排列的 “ 名次 ” 。
容易看出，后缀数组和名次数组为互逆运算。
设字符串的长度为 n 。
为了方便比较大小，可以在字符串后面添加一个字符，这个字符没有在前面的字符中出现过，而且比前面的字符都要小。
在求出名次数组后，可以仅用 O(1) 的时间比较任意两个后缀的大小。
在求出后缀数组或名次数组中的其中一个以后，便可以用 O(n) 的时间求出另外一个。
任意两个后缀如果直接比较大小，最多需要比较字符 n 次，也就是说最迟在比较第 n 个字符时一定能分出 “ 胜负 ” 。 
*/
void getRank()
{
    for(int i = 1;i < n; ++ i)
        rank[sa[i]] = i;
}
/*
对两个字符串u,v定义函数lcp(u,v)=max{i|u=iv}，也就是从头开始顺次比较u和v的对应字符，对应字符持续相等的最大位置，
称为这两个字符串的最长公共前缀。
对正整数i,j定义LCP(i,j)=lcp(Suffix(SA[i]),Suffix(SA[j]))，其中i,j均为1至n的整数。LCP(i,j)也就是后缀数组中第i个
和第j个后缀的最长公共前缀的长度。
定义一维数组height，令height[i]=LCP(i-1,i)，1<i≤n，并设height[1]=0。
*/
void lcp()
{ // O(4 * N)
    int i, j, k;
    for (j = rank[height[i=k=0]=0]; i < n - 1; i++, k++)
        while (k >= 0 && s[i] != s[ sa[j-1] + k ])
            height[j] = (k--), j = rank[ sa[j] + 1 ];
}

#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#define FOR(i,s,e) for (int (i)=(s); (i)<(e); i++)
/*求素数[1,MAXPRI]*/
const int MAXPRI=50000+10;
bool NotPrime[MAXPRI];
int  PrimeList[MAXPRI];
void Prime()
{
	int i,j,up = sqrt(MAXPRI*1.0);
	memset(NotPrime,0,sizeof(NotPrime));
	memset(PrimeList,0,sizeof(PrimeList));
	for(i = 2; i <= up; i++) 
	{
		if(NotPrime[i] == 0)
		{
			PrimeList[++PrimeList[0]] = i;
			for(j = i + i; j < MAXPRI*1.0; j = j + i)
				NotPrime[j] = 1;
		}
	}
	for(i = up + 1; i < MAXPRI; i++)
		if(NotPrime[i] == 0)
			PrimeList[++PrimeList[0]] = i;
}
__int64  euler(__int64  x)
{
    int i ;
    __int64  res = x,up = (__int64 )sqrt(x * 1.0) + 1;
    for (i = 1; PrimeList[i] < up && i < PrimeList[0]; i++)
    if (x % PrimeList[i] == 0)
    {
        res = res / PrimeList[i] *( PrimeList[i] - 1);
        while (x % PrimeList[i] == 0 )
			x/=PrimeList[i];
     }
	if (x > 1)
		res = res / x * (x-1);
    return res;
}
 
__int64 gcd(__int64 a, __int64 b)
{
    if (a < b)
		return gcd(b,a);
    __int64 c ;
	while (b) 
	{
		c=a%b;
		a=b;
		b=c;
	}
    return a;
}
__int64  power_mod(__int64 A, __int64  B, __int64 C)
{
    __int64  R = 1, D = A;
    while (B )
    {
        if (B&1) R = (R*D)%C;
        D = (D*D)%C;
        B >>=1;
    }
    return R;
}
 
int main()
{
    __int64 x,y,a0,t;
    __int64 min,ph;
	Prime();
    while (scanf("%I64d%I64d%I64d",&x,&y,&a0)!=EOF)
    {
        t = y / (x-1);
        if (t % a0 == 0)  
        {
			printf("1\n");
			continue;
		}
        __int64 temp = gcd(a0,t);
        a0 = a0 / temp;
        if  (gcd(x,a0) != 1)
        {
			printf("Impossible!\n");
			continue;
		}
		/*A^B = C MOD D,其中A=X，C=1，D=a0， 求B*/
        ph = euler(a0);
        min = ph;
        for (int i=1; i*i<=ph; i++)
        if (ph % i == 0)
        {
            if (i<min && power_mod(x,i,a0) == 1)
                min = i;
            if (ph/i < min && power_mod(x,ph/i,a0) == 1)
                min = ph/i;
        }
        printf("%I64d\n",min);
 
    }
    return 0;
}

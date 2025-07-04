#include<iostream>

using namespace std;

#define MOD 1000000007
int n,k;

long long f(int a,int b)
{
    long long r = 1;
    for(int i=a;i<=b;i++)
    {
        r = r * i % MOD;
    }
    return r;
}

long long p(long long a,long long b)
{
    if(b==0) return 1;
    else if(b==1) return a;
    long long tmp = p(a,b/2);
    if(b%2 == 0) return tmp * tmp % MOD;
    else return tmp * tmp % MOD * a % MOD;
}



int main()
{
    cin >> n >> k;
    cout << f(n-k+1,n)*p(f(1,k),MOD-2) % MOD;
}
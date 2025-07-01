#include<iostream>

using namespace std;

#define MAX 2001

int b[MAX][MAX];

long long n,k,m;
int r = 1;

int main()
{
    cin >> n >> k >> m;
    for(int i=0;i<m;i++)
    {
        b[i][0] = 1;
        for(int j=1;j<=i;j++)
        {
            b[i][j] = (b[i-1][j-1] + b[i-1][j])%m;
        }
    }
    while(n || k)
    {
        r *= b[n%m][k%m];
        n /= m;
        k /= m;
        r %= m;
    }
    cout << r ;
}
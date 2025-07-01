#include<iostream>
#include<algorithm>

using namespace std;

int n,k;
int w[101];
int v[101];
int dp[101][100001];

int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> w[i] >> v[i];
    }
    for(int j=1;j<=k;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(w[i] <= j)
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
                //cout << i << " " << j<< " " << dp[i][j] << endl;
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k];
}
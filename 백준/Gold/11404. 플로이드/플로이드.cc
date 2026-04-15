#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1e9

int dp[101][101];
int n,m;

int main(){
    cin >> n >> m;
    int a,b,c;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j] = (i==j ? 0 : MAX); 

    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dp[i][j] == MAX) cout << 0 << " ";
            else cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
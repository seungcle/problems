#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1e9

int n;
int m[501][2];
int dp[501][501];
 
 
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> m[i][0] >> m[i][1];
    }
    
    for(int i=1; i<n; i++){
        for(int j=1; i+j<=n; j++){
            dp[j][i+j] = MAX;
            for(int k=j; k<=i+j; k++){
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + m[j][0]*m[k][1]*m[i+j][1]);
            }
        }
    }
 
    cout << dp[1][n];
 
    return 0;
}
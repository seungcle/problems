#include <iostream>
using namespace std;

#define MAX 1e9

int t,n;
int c[501];
int sum[501];
int dp[501][501];

void input(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> c[i];
}

void reset(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j] = 0;

    sum[0] = c[0];
    for(int i=1;i<n;i++)
        sum[i] = sum[i-1] + c[i];
}

int getSum(int i, int j){
    if(i == 0) return sum[j];
    return sum[j] - sum[i-1];
}

void solve(){
    cin >> t;
    while(t--){
        input();
        reset();

        for(int len=1; len<n; len++){
            for(int i=0; i+len<n; i++){
                int j = i + len;
                dp[i][j] = MAX;

                for(int mid=i; mid<j; mid++){
                    dp[i][j] = min(dp[i][j],
                        dp[i][mid] + dp[mid+1][j] + getSum(i,j));
                }
            }
        }

        cout << dp[0][n-1] << "\n";
    }
}

int main(){
    solve();
}
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int t[1001];
int p[1001];
int dp[1010];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t[i] >> p[i];
    }
    for(int i=0;i<n;i++){
        dp[i+1] = max(dp[i+1], dp[i]);
        if(i + t[i] <= n)
        dp[i+t[i]] = max(dp[i+t[i]], dp[i] + p[i]);
    }
    cout << dp[n];
}

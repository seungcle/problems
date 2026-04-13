#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,M;
int arr[2001];
int S,E;
int dp[2001][2001];

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> arr[i];
    }

    for(int i=1;i<=N;i++)
        dp[i][i] = 1;
    
    for(int len = 2; len <= N; len++){
        for(int i = 1; i + len - 1 <= N; i++){
            int j = i + len - 1;

            if(len == 2 && arr[i] == arr[j]) dp[i][j] = 1;
            else if(arr[i] == arr[j] && dp[i+1][j-1]) dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }
    

    cin >> M;
    for(int i=0;i<M;i++){
        cin >> S >> E;
        cout << dp[S][E] <<"\n";
    }
}
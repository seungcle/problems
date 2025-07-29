#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int mem[101], cost[101];
int dp[10001]; // dp[i] = 비용 i로 얻을 수 있는 최대 메모리

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mem[i];
    for (int i = 0; i < n; i++) cin >> cost[i];

    for (int i = 0; i < n; i++) {
        for (int j = 10000; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + mem[i]);
        }
    }

    for (int i = 0; i <= 10000; i++) {
        if (dp[i] >= m) {
            cout << i;
            return 0;
        }
    }
}

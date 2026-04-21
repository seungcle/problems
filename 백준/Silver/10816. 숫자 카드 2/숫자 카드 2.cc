#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, x;
    cin >> N;
    vector<int> num(N);
    for (int i = 0; i < N; i++) cin >> num[i];
    
    sort(num.begin(), num.end());

    cin >> M;
    while (M--) {
        cin >> x;
        int cnt = upper_bound(num.begin(), num.end(), x) - lower_bound(num.begin(), num.end(), x);
        cout << cnt << " ";
    }
}

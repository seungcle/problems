#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1000001];

int main() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> lis;
    vector<int> trace;           // 각 길이별 마지막 인덱스
    vector<int> parent(n, -1);   // 이전 인덱스

    for(int i=0;i<n;i++){
        int x = arr[i];
        auto it = lower_bound(lis.begin(), lis.end(), x);
        int pos = it - lis.begin();

        if(it == lis.end()){
            lis.push_back(x);
            trace.push_back(i);
        } else {
            *it = x;
            trace[pos] = i;
        }

        if(pos > 0){
            parent[i] = trace[pos-1];
        }
    }

    // 복원
    int cur = trace.back();
    vector<int> ans;

    while(cur != -1){
        ans.push_back(arr[cur]);
        cur = parent[cur];
    }

    reverse(ans.begin(), ans.end());

    // 출력
    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " ";
}
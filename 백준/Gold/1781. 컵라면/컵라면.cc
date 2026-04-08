#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;

struct Node {
    int a; // deadline
    int b; // ramen
};

int main() {
    cin >> n;
    vector<Node> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i].a >> v[i].b;
    }

    // deadline 기준 정렬
    sort(v.begin(), v.end(), [](Node x, Node y){
        return x.a < y.a;
    });

    priority_queue<int> pq; // ramen 기준 max heap

    int idx = n - 1;
    int result = 0;

    // 최대 deadline부터 시작
    int maxDay = v[n-1].a;

    for(int day = maxDay; day >= 1; day--) {

        // 현재 day까지 가능한 것만 추가
        while(idx >= 0 && v[idx].a >= day) {
            pq.push(v[idx].b);
            idx--;
        }

        // 그 중 최고값 선택
        if(!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result;
}
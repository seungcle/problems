#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;

struct Node {
    int m; 
    int v; 
};

int main() {
    cin >> n >> k;
    vector<Node> v(n);
    vector<int> c;

    for(int i = 0; i < n; i++){
        cin >> v[i].m >> v[i].v;
    }

    for(int i=0; i<k; i++){
        int x;
        cin >> x;
        c.push_back(x);  
    }

    sort(v.begin(), v.end(), [](Node x, Node y){
        return x.m < y.m;
    });

    sort(c.begin(),c.end());

    priority_queue<int> pq; 

    int idx = 0;
    long long result = 0;

    int maxM = v[n-1].m;

    for(int i = 0; i < k; i++) {

        while(idx < n && v[idx].m <= c[i]) {
            pq.push(v[idx].v);
            idx++;
        }

        if(!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result;
}
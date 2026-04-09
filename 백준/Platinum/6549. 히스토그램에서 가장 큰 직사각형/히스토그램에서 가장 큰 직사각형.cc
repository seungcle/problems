#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
    while(1){
        cin >> n;
        if(n == 0) break;
        vector<int> v;
        stack<int> stk;
        long long result = 0;
        v.push_back(0);
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        v.push_back(0);
        for(int i=0;i<=n+1;i++){
            while(!stk.empty() && v[stk.top()] > v[i]){
                int h = v[stk.top()];
                stk.pop();

                int w;
                if(stk.empty()) w = i;
                else w = i - stk.top() - 1;

                result = max(result, (long long)h * w);
            }
            stk.push(i);
        }
        cout << result << "\n";
    }
}
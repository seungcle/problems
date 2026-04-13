#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int aws, n;
vector<pair<int,int> > v;

bool check(int col, int row){
    int cur = v.size();

    for(int i=0;i<cur;i++){
        // 같은 열 or 같은 행
        if(v[i].first == col || v[i].second == row) return false;

        // 대각선
        if(abs(v[i].first - col) == abs(v[i].second - row)) return false;
    }

    return true;
}

void dfs(int row){
    if(row == n){
        aws++;
        return;
    }

    for(int i=0;i<n;i++){
        if(check(i,row)){
            v.push_back({i,row});
            dfs(row+1);
            v.pop_back();
        }
    }
}

int main(){
    cin >> n;
    dfs(0);
    cout << aws;
}
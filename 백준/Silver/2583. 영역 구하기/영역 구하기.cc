#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int M,N,K;
int visited[100][100];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void input(){
    cin >> M >> N >> K;
    int x1,x2,y1,y2;
    for(int k=0;k<K;k++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1;i<x2;i++)
            for(int j=y1;j<y2;j++)
                visited[j][i] = 1;
    }
}

int bfs(int y,int x){
    queue<pair<int,int> > q;
    int cnt = 1;
    q.push({y,x});
    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(ny < 0 || ny >= M || nx < 0 || nx >= N) continue;
            if(visited[ny][nx] == 1) continue;
            visited[ny][nx] = 1;
            cnt++;
            q.push({ny,nx});
        }
    }
    return cnt;
}

void solve(){
    vector<int> ans;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++){
            if(visited[i][j] == 0) {
                visited[i][j] = 1;
                ans.push_back(bfs(i,j));
            }
        }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
}

int main(){
    input();
    solve();
}
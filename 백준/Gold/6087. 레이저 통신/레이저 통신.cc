#include <iostream>
#include <deque>
using namespace std;

#define MAX 1e9

int w,h;
char map[101][101];
int dist[101][101][4]; 

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

pair<int, int> Start,End;

struct Node{
    int x; int y;
    int dir; int cnt;
};

void input(){
    int tmp = 0;
    cin >> w >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> map[i][j];
            if(map[i][j] == 'C'){
                if(tmp == 0){
                    Start = {i,j};
                    tmp++;
                } else{
                    End = {i,j};
                }
            }
            for(int d=0; d<4; d++) dist[i][j][d] = MAX;
        }
    }
}

int bfs(int a,int b){
    deque<Node> q;

    for(int i=0;i<4;i++){
        dist[a][b][i] = 0;
        q.push_back({a,b,i,0});
    }

    while(!q.empty()){
        Node cur = q.front();
        q.pop_front();

        int x = cur.x;
        int y = cur.y;
        int dir = cur.dir;
        int cnt = cur.cnt;

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncnt = cnt;

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(map[nx][ny] == '*') continue;

            if(dir != i) ncnt++;

            if(dist[nx][ny][i] > ncnt){
                dist[nx][ny][i] = ncnt;

                if(dir == i) q.push_front({nx,ny,i,ncnt}); 
                else q.push_back({nx,ny,i,ncnt});          
            }
        }
    }

    int ans = MAX;
    for(int i=0;i<4;i++){
        ans = min(ans, dist[End.first][End.second][i]);
    }
    return ans;
}

int main(){
    input();
    cout << bfs(Start.first, Start.second);
}
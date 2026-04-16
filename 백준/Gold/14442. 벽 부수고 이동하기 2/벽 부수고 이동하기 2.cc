#include <iostream>
#include <queue>
#include <string> 

using namespace std;

int arr[1000][1000];
int visited[1000][1000][11];
int N,M,K;

struct Dir
{
    int x,y;
};

struct Node
{
    int x,y,z,cnt;
};

Dir dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<Node> Q;

void input(){
    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        string s; cin >> s; 
        for(int j=0;j<M;j++){
            arr[i][j] = s[j] - '0';
        }
    }
}

void bfs(){
    Q.push({0,0,0,1});
    visited[0][0][0] = 1;

    while(!Q.empty()){
        int x = Q.front().x;
        int y = Q.front().y;
        int z = Q.front().z;
        int cnt = Q.front().cnt;
        Q.pop();

        if(x == N-1 && y == M-1){ 
            cout << cnt;
            return;
        }

        for(int i=0;i<4;i++){
            int nx = x + dir[i].x;
            int ny = y + dir[i].y;

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if(arr[nx][ny] == 0 && visited[nx][ny][z] == 0){
                visited[nx][ny][z] = 1;
                Q.push({nx,ny,z,cnt+1});
            }

            if(arr[nx][ny] == 1 && z < K && visited[nx][ny][z+1] == 0){
                visited[nx][ny][z+1] = 1; 
                Q.push({nx,ny,z+1,cnt+1});
            }
        }
    }

    cout << "-1";
}

int main(){
    input();
    bfs();
}
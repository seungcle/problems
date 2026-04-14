#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[101][101];

struct Dir{
    int x,y;
};

Dir dir[4] = {
    {1,0},{-1,0},{0,1},{0,-1}
};

int bfs(int low, int high){
    if(arr[0][0] < low || arr[0][0] > high) return 0;

    queue<pair<int,int> > q;
    int visited[101][101] = {0}; 
    
    q.push({0,0});
    visited[0][0] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == n-1 && y == n-1) return 1; 

        for(int i=0;i<4;i++){
            int nx = x + dir[i].x;
            int ny = y + dir[i].y;

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;

            if(arr[nx][ny] < low || arr[nx][ny] > high) continue;

            visited[nx][ny] = 1; 
            q.push({nx,ny});
        }
    }
    return 0;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> arr[i][j];

    int answer = 1e9;

    for(int low=0; low<=200; low++){
        int start = 0, end = 200;

        while(start <= end){
            int mid = (start + end) / 2;

            if(bfs(low, low + mid)){
                answer = min(answer, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }

    cout << answer;
}
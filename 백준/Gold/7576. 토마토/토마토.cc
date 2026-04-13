#include <iostream>
#include <queue>

using namespace std;

int M, N;
int rest; //안 익은 토마토

struct Dir{
    int dn, dm;
};

struct Node{
    int days, n, m;
};

Dir dir[4] = {
    {1,0},{-1,0},{0,1},{0,-1}
};

int main(){
    cin >> M >> N;
    int map[N][M];
    queue<Node> Queue;
    int aws = 0;

    for (int n = 0; n < N; n++) for (int m = 0; m < M; m++){
        cin >> map[n][m];
        if (map[n][m] == 1)
            Queue.push({0, n, m});
        else if(map[n][m] == 0)rest++;
    }
    
while (!Queue.empty()){
    Node cur = Queue.front(); Queue.pop();

    int days = cur.days;
    int n = cur.n, m = cur.m;

    aws = days;

    for (int i = 0; i < 4; i++){
        int dn = dir[i].dn, dm = dir[i].dm;

        if (
            0 <= n + dn && n + dn < N &&
            0 <= m + dm && m + dm < M &&
            map[n + dn][m + dm] == 0){

            Queue.push({days + 1, n + dn, m + dm});
            map[n + dn][m + dm] = 1;
            rest--;
        }
    }
}

    cout << (rest ? -1 : aws);
}
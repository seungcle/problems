#include <iostream>
#include <queue>

using namespace std;

int M, N, O, P, Q, R, S, T, U, V, W;
int rest; //안 익은 토마토

struct Dir{
    int dw, dv, du, dt, ds, dr, dq, dp, do_, dn, dm;
};

struct Node{
    int days, w, v, u, t, s, r, q, p, o, n, m;
};

Dir dir[22] = {{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};

int main(){
    cin >> M >> N >> O >> P >> Q >> R >> S >> T >> U >> V >> W;
    int map[W][V][U][T][S][R][Q][P][O][N][M];
    queue<Node> Queue;
    int aws = 0;

    for (int w = 0; w < W; w++) for (int v = 0; v < V; v++) for (int u = 0; u < U; u++) 
    for (int t = 0; t < T; t++) for (int s = 0; s < S; s++) for (int r = 0; r < R; r++) 
    for (int q = 0; q < Q; q++) for (int p = 0; p < P; p++) for (int o = 0; o < O; o++) 
    for (int n = 0; n < N; n++) for (int m = 0; m < M; m++){
        cin >> map[w][v][u][t][s][r][q][p][o][n][m];
        if (map[w][v][u][t][s][r][q][p][o][n][m] == 1)
            Queue.push({0, w, v, u, t, s, r, q, p, o, n, m});
        else if(map[w][v][u][t][s][r][q][p][o][n][m] == 0)rest++;
    }
    
while (!Queue.empty()){
    Node cur = Queue.front(); Queue.pop();

    int days = cur.days;
    int w = cur.w, v = cur.v, u = cur.u, t = cur.t, s = cur.s;
    int r = cur.r, q = cur.q, p = cur.p, o = cur.o, n = cur.n, m = cur.m;

    aws = days;

    for (int i = 0; i < 22; i++){
        int dw = dir[i].dw, dv = dir[i].dv, du = dir[i].du, dt = dir[i].dt;
        int ds = dir[i].ds, dr = dir[i].dr, dq = dir[i].dq, dp = dir[i].dp;
        int do_ = dir[i].do_, dn = dir[i].dn, dm = dir[i].dm;

        if (0 <= w + dw && w + dw < W &&
            0 <= v + dv && v + dv < V &&
            0 <= u + du && u + du < U &&
            0 <= t + dt && t + dt < T &&
            0 <= s + ds && s + ds < S &&
            0 <= r + dr && r + dr < R &&
            0 <= q + dq && q + dq < Q &&
            0 <= p + dp && p + dp < P &&
            0 <= o + do_ && o + do_ < O &&
            0 <= n + dn && n + dn < N &&
            0 <= m + dm && m + dm < M &&
            map[w + dw][v + dv][u + du][t + dt][s + ds][r + dr][q + dq][p + dp][o + do_][n + dn][m + dm] == 0){

            Queue.push({days + 1, w + dw, v + dv, u + du, t + dt, s + ds, r + dr, q + dq, p + dp, o + do_, n + dn, m + dm});
            map[w + dw][v + dv][u + du][t + dt][s + ds][r + dr][q + dq][p + dp][o + do_][n + dn][m + dm] = 1;
            rest--;
        }
    }
}

    cout << (rest ? -1 : aws);
}
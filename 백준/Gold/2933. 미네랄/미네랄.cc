#include <bits/stdc++.h>
using namespace std;

int R, C, N;
vector<string> cave;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool visited[101][101];

bool inRange(int x, int y) {
    return (0 <= x && x < R && 0 <= y && y < C);
}

void bfs(int sx, int sy, vector<pair<int,int>> &cluster) {
    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    cluster.push_back({sx, sy});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (!inRange(nx, ny)) continue;
            if (!visited[nx][ny] && cave[nx][ny] == 'x') {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cluster.push_back({nx, ny});
            }
        }
    }
}

void throwStick(int height, bool fromLeft) {
    int row = R - height;
    if (fromLeft) {
        for (int j = 0; j < C; j++) {
            if (cave[row][j] == 'x') {
                cave[row][j] = '.';
                return;
            }
        }
    } else {
        for (int j = C - 1; j >= 0; j--) {
            if (cave[row][j] == 'x') {
                cave[row][j] = '.';
                return;
            }
        }
    }
}

void applyGravity(vector<pair<int,int>> &cluster) {
    for (auto &p : cluster) cave[p.first][p.second] = '.';

    int drop = 1e9;
    for (auto &p : cluster) {
        int x = p.first, y = p.second;
        int cnt = 0;
        while (true) {
            int nx = x + cnt + 1;
            if (nx >= R) break; 
            if (cave[nx][y] == 'x') break; 
            cnt++;
        }
        drop = min(drop, cnt);
    }

    for (auto &p : cluster) {
        cave[p.first + drop][p.second] = 'x';
    }
}

void processAfterThrow() {
    memset(visited, false, sizeof(visited));

    for (int j = 0; j < C; j++) {
        if (cave[R - 1][j] == 'x' && !visited[R - 1][j]) {
            vector<pair<int,int>> tmp;
            bfs(R - 1, j, tmp);
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (cave[i][j] == 'x' && !visited[i][j]) {
                vector<pair<int,int>> cluster;
                bfs(i, j, cluster);
                applyGravity(cluster);
                return; 
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    cave.resize(R);
    for (int i = 0; i < R; i++) cin >> cave[i];
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; i++) cin >> heights[i];

    bool fromLeft = true;
    for (int i = 0; i < N; i++) {
        throwStick(heights[i], fromLeft);
        processAfterThrow();
        fromLeft = !fromLeft;
    }

    for (int i = 0; i < R; i++) cout << cave[i] << "\n";
    return 0;
}

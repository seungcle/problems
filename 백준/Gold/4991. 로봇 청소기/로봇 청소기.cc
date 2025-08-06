#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

int w, h;
vector<string> board;
vector<Point> points; 
int dist[15][15];     

vector<vector<int>> bfs(Point start) {
    vector<vector<int>> d(h, vector<int>(w, -1));
    queue<Point> q;
    q.push(start);
    d[start.x][start.y] = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        Point cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (board[nx][ny] == 'x') continue;
            if (d[nx][ny] != -1) continue;
            d[nx][ny] = d[cur.x][cur.y] + 1;
            q.push({nx, ny});
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        board.assign(h, "");
        points.clear();

        Point start;
        for (int i = 0; i < h; i++) {
            cin >> board[i];
            for (int j = 0; j < w; j++) {
                if (board[i][j] == 'o') start = {i, j};
            }
        }

        points.push_back(start); 

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '*') {
                    points.push_back({i, j});
                }
            }
        }

        int n = points.size();

        bool possible = true;
        for (int i = 0; i < n; i++) {
            auto d = bfs(points[i]);
            for (int j = 0; j < n; j++) {
                dist[i][j] = d[points[j].x][points[j].y];
                if (dist[i][j] == -1) {
                    possible = false; 
                }
            }
        }

        if (!possible) {
            cout << -1 << "\n";
            continue;
        }

        vector<vector<int>> dp(1 << n, vector<int>(n, 1e9));
        dp[1][0] = 0; 

        for (int mask = 1; mask < (1 << n); mask++) {
            for (int u = 0; u < n; u++) {
                if (!(mask & (1 << u))) continue;
                for (int v = 0; v < n; v++) {
                    if (mask & (1 << v)) continue; 
                    int nextMask = mask | (1 << v);
                    dp[nextMask][v] = min(dp[nextMask][v], dp[mask][u] + dist[u][v]);
                }
            }
        }

        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[(1 << n) - 1][i]);
        }

        cout << ans << "\n";
    }

    return 0;
}

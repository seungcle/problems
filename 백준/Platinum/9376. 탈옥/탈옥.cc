#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

vector<vector<int>> zeroOneBFS(int sy, int sx, const vector<string>& g) {
    int H = g.size(), W = g[0].size();
    vector<vector<int>> dist(H, vector<int>(W, INF));
    deque<pair<int,int>> dq;
    dist[sy][sx] = 0;
    dq.emplace_front(sy, sx);

    while (!dq.empty()) {
        auto [y, x] = dq.front(); dq.pop_front();
        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir], nx = x + dx[dir];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (g[ny][nx] == '*') continue; // 벽은 못 감

            int w = (g[ny][nx] == '#') ? 1 : 0; // 문이면 비용 1, 아니면 0
            if (dist[ny][nx] > dist[y][x] + w) {
                dist[ny][nx] = dist[y][x] + w;
                if (w == 0) dq.emplace_front(ny, nx);
                else dq.emplace_back(ny, nx);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if(!(cin >> T)) return 0;
    while (T--) {
        int h, w;
        cin >> h >> w;
        vector<string> a(h);
        for (int i = 0; i < h; ++i) cin >> a[i];

        // 패딩: 바깥에서 들어올 수 있게 사방에 '.' 한 겹
        vector<string> g(h + 2, string(w + 2, '.'));
        vector<pair<int,int>> prisoners;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                g[i + 1][j + 1] = a[i][j];
                if (a[i][j] == '$') {
                    prisoners.emplace_back(i + 1, j + 1);
                    g[i + 1][j + 1] = '.'; // 죄수 칸은 빈칸 취급
                }
            }
        }

        // 3개의 시작점: 바깥(0,0), 죄수 2명
        auto d0 = zeroOneBFS(0, 0, g);
        auto d1 = zeroOneBFS(prisoners[0].first, prisoners[0].second, g);
        auto d2 = zeroOneBFS(prisoners[1].first, prisoners[1].second, g);

        int H = h + 2, W = w + 2;
        int ans = INF;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (d0[i][j] == INF || d1[i][j] == INF || d2[i][j] == INF) continue;
                long long sum = (long long)d0[i][j] + d1[i][j] + d2[i][j];
                if (g[i][j] == '#') sum -= 2; // 문 공유 보정
                ans = min(ans, (int)sum);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

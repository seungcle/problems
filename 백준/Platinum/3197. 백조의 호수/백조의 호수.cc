#include <iostream>
#include <queue>

using namespace std;

int r, c, date;
char arr[1500][1500];
bool visited1[1500][1500]; // 백조 BFS
bool visited2[1500][1500]; // 물 확장 BFS
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pair<int, int> swan[2];

queue<pair<int, int>> q1, q2;
queue<pair<int, int>> w_q1, w_q2;

void input() {
    int swanCnt = 0;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %c", &arr[i][j]);  // 공백 필수!
            if (arr[i][j] == 'L') {
                swan[swanCnt++] = {i, j};
                w_q1.push({i, j}); // 물 취급
            } else if (arr[i][j] == '.') {
                w_q1.push({i, j});
            }
        }
    }

    // 첫 번째 백조만 시작점
    q1.push(swan[0]);
    visited1[swan[0].first][swan[0].second] = true;
}

bool bfs_l() {
    while (!q1.empty()) {
        int x = q1.front().first;
        int y = q1.front().second;
        q1.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (visited1[nx][ny]) continue;

            // 다른 백조를 만나면
            if (nx == swan[1].first && ny == swan[1].second) return true;

            visited1[nx][ny] = true;

            if (arr[nx][ny] == '.') {
                q1.push({nx, ny});
            } else if (arr[nx][ny] == 'X') {
                q2.push({nx, ny}); // 얼음이면 내일 처리
            }
        }
    }
    return false;
}

void bfs_w() {
    while (!w_q1.empty()) {
        int x = w_q1.front().first;
        int y = w_q1.front().second;
        w_q1.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (visited2[nx][ny]) continue;

            visited2[nx][ny] = true;

            if (arr[nx][ny] == 'X') {
                arr[nx][ny] = '.';
                w_q2.push({nx, ny});
            } else {
                w_q1.push({nx, ny});
            }
        }
    }
}

void solution() {
    while (true) {
        if (bfs_l()) {
            cout << date << "\n";
            return;
        }
        bfs_w();
        date++;

        // 큐 스왑 (move 사용하면 O(1))
        q1 = std::move(q2);
        w_q1 = std::move(w_q2);
    }
}

int main() {
    input();
    solution();
}
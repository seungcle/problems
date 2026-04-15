#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C;
char a[26][26];

// 상(0), 하(1), 좌(2), 우(3)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool connect(char c, int d) {
    if (c == '|') return (d == 0 || d == 1);
    if (c == '-') return (d == 2 || d == 3);
    if (c == '+') return true;
    if (c == '1') return (d == 1 || d == 3); // 하, 우
    if (c == '2') return (d == 0 || d == 3); // 상, 우
    if (c == '3') return (d == 0 || d == 2); // 상, 좌
    if (c == '4') return (d == 1 || d == 2); // 하, 좌
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> R >> C)) return 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (a[i][j] != '.') continue;

            bool chk[4] = {false};
            int cnt = 0;

            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                
                if (connect(a[nx][ny], d ^ 1)) {
                    chk[d] = true;
                    cnt++;
                }
            }

            if (cnt > 0) {
                char ans = ' ';
                if (cnt == 4) ans = '+';
                else if (chk[0] && chk[1]) ans = '|';
                else if (chk[2] && chk[3]) ans = '-';
                else if (chk[1] && chk[3]) ans = '1';
                else if (chk[0] && chk[3]) ans = '2';
                else if (chk[0] && chk[2]) ans = '3';
                else if (chk[1] && chk[2]) ans = '4';

                cout << i + 1 << " " << j + 1 << " " << ans << endl;
                return 0;
            }
        }
    }

    return 0;
}
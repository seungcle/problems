#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n, m, ans_min = 100;
char board[11][11];
pair<int, int> r, b;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int move(int dir)
{
    int n_rx = r.first, n_ry = r.second, n_bx = b.first, n_by = b.second;
    while (board[n_bx + dx[dir]][n_by + dy[dir]] == '.')
    {
        n_bx += dx[dir];
        n_by += dy[dir];
    }
    if (board[n_bx + dx[dir]][n_by + dy[dir]] == 'O')
        return -1;

    while (board[n_rx + dx[dir]][n_ry + dy[dir]] == '.')
    {
        n_rx += dx[dir];
        n_ry += dy[dir];
    }
    
    if (board[n_rx + dx[dir]][n_ry + dy[dir]] == 'O')
        return 1;

    if ((n_rx == n_bx) && (n_ry == n_by))
    {
        if (dir == 0)
            r.first < b.first ? n_bx++ : n_rx++;
        else if (dir == 1) 
            r.first > b.first ? n_bx-- : n_rx--;
        else if (dir == 2) 
            r.second < b.second ? n_by++ : n_ry++;
        else 
            r.second > b.second ? n_by-- : n_ry--;
    }
    r = {n_rx, n_ry};
    b = {n_bx, n_by};
    return 0;
}

void func(int cnt)
{
    if (cnt >= 10)
        return;

    for (int dir = 0; dir < 4; dir++)
    {
        auto tmp_r = r, tmp_b = b;
        int flag = move(dir);
        if (flag == -1)
            continue;
        else if (flag == 1)
        {
            ans_min = min(ans_min, cnt + 1);
            continue;
        }
        else
            func(cnt + 1);
        r = tmp_r;
        b = tmp_b;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                board[i][j] = '.';
                r = {i, j};
            }

            if (board[i][j] == 'B')
            {
                board[i][j] = '.';
                b = {i, j};
            }
        }
    }

    func(0);
    if (ans_min == 100)
        cout << "-1\n";
    else
        cout << ans_min << '\n';
}
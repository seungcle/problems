#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n,k;
bool visited[100001];
queue<pair<int,int> > q;
int dx[3] = {1,-1,0};
int prevInt[100001];

void bfs()
{
    q.push(make_pair(n,0));
    visited[n] = true;
    while(!q.empty())
    {
        int cur = q.front().first;
        int dist = q.front().second;
        if(cur == k)
        {
            cout << dist << "\n";
            break;
        }
        for(int i=0;i<3;i++)
        {
            int nx = cur + dx[i];
            if(dx[i] == 0)
            {
                nx = cur + cur;
            }
            if(nx<0 || nx>100000) continue;
            if(visited[nx]) continue;
            visited[nx] = true;
            q.push(make_pair(nx,dist+1));
            prevInt[nx] = cur;
        }
        q.pop();
    }
}


void input()
{
    cin >> n >> k;
}

int main()
{
    input();
    bfs();
    
    vector<int> path;
    for (int cur = k; cur != n; cur = prevInt[cur]) {
        path.push_back(cur);
    }
    path.push_back(n);
    reverse(path.begin(), path.end());

    for (int x : path) {
        cout << x << " ";
    }
    cout << "\n";
}
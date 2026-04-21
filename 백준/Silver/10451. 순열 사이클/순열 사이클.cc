#include<iostream>
#include<queue>

using namespace std;

int visited[1001];
int arr[1001];
int T,N;
int cnt;
queue<int> q;

void input()
{
    cin >> N;
    for(int i=1;i<N+1;i++)
    {
        cin >> arr[i];
    }
}

void reset()
{
    for(int i=1;i<N+1;i++)
    {
        visited[i] = 0;
        arr[i] = 0;
        cnt = 0;
    }
}

void solve(int x)
{
    q.push(x);
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        visited[tmp] = 1;
        if(!visited[arr[tmp]])
        {
            q.push(arr[tmp]);
        }
    }
    cnt++;
}

int main()
{
    cin >> T;
    for(int j=0;j<T;j++)
    {
        input();
        for(int i=1;i<N+1;i++)
        {
            if(!visited[i])
                solve(i);
        }
        cout << cnt << endl;
        reset();
    }
}
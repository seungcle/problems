#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M; // N 전자기기 수  // M 콘센트 갯수
priority_queue<int,vector<int>,greater<int> > pq;
int device[10000];

void input()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
        cin >> device[i];
}

void solve()
{
    sort(device,device+N,greater<int>());
    for(int i=0;i<M;i++)
    {
        pq.push(device[i]);
    }
    for(int i=M;i<N;i++)
    {
        int top = pq.top();
        top = top + device[i];
        pq.pop();
        pq.push(top);
    }
    while(pq.size() > 1)
    {
        pq.pop();
    }
    cout << pq.top();
}

int main()
{
    input();
    solve();
}
#include<iostream>
#include<queue>

using namespace std;

int arr[101][101] ={0};
int vs[101][101] = {0};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct point
{
    int x;
    int y;
};

queue<point> q;

void bfs(int k,int n)
{
    while(!q.empty())
    {
        point tmp;
        tmp = q.front();
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if(vs[nx][ny] == 0 && arr[nx][ny] > k)
            {
                vs[nx][ny] = 1;
                point tmp2;
                tmp2.x = nx;
                tmp2.y = ny;
                q.push(tmp2);
            }
        }
    }
}

void reset_vs(int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            vs[i][j] = 0;
}

int main()
{
    int n;
    cin >> n;
    int max = 0;
    int r = 0;
    int safeArea = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(max < arr[i][j])
                max = arr[i][j];
        }
    for(int k=0;k<=max;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vs[i][j] == 0 && arr[i][j] > k)
                {
                    point tmp;
                    tmp.x = i;
                    tmp.y = j;
                    vs[i][j] = 1;
                    q.push(tmp);
                    bfs(k , n);
                    safeArea++;
                }
            }
        }
        if(r < safeArea)
            r = safeArea;
        safeArea = 0;
        reset_vs(n);
    }
    cout<<r<<endl;
}
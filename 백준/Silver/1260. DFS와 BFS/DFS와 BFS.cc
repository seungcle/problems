#include<iostream>
#include<queue>
#include<cstring>
#define MAX 1001

using namespace std;

int map[MAX][MAX];
int visited[MAX];
queue<int> q;
int n,m,v;

void dfs(int v){
    cout<<v<<" ";
    visited[v]=1;
    for(int i=1;i<=n;i++){
        if(map[v][i] && !visited[i]){
            dfs(i);
        }
    }
} 

void bfs(int v){
    cout<<v<<" ";
    visited[v]=1;
    q.push(v);
    while(!q.empty()){
        v=q.front();
        for(int i=1;i<=n;i++){
            if(map[v][i] && !visited[i]){
                cout<<i<<" ";
                visited[i]=1;
                q.push(i);
            }
        } 
        q.pop();
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m>>v;
    memset(map,0,sizeof(map));
    memset(visited,0,sizeof(visited));
    
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        map[a][b]=1;
        map[b][a]=1;
    }
    dfs(v);
    cout<<"\n";
    
    memset(visited,0,sizeof(visited));
    
    bfs(v);
    cout<<"\n";
}
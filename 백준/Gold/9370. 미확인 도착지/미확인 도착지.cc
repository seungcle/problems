#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1e9

int T;
int n,m,t;
int s,g,h;

vector<pair<int,int>> v[2001]; 
int distS[2001], distG[2001], distH[2001];

void dijkstra(int start, int dist[]){
    fill(dist, dist + 2001, MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int d = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d > dist[now]) continue;

        for(auto nxt : v[now]){
            int next = nxt.first;
            int cost = d + nxt.second;

            if(cost < dist[next]){
                dist[next] = cost;
                pq.push({cost, next});
            }
        }
    }
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        
        for(int i=1;i<=n;i++) v[i].clear();

        int a,b,d;
        int gh; 

        for(int i=0;i<m;i++){
            cin >> a >> b >> d;
            v[a].push_back({b,d});
            v[b].push_back({a,d});

            if((a==g && b==h) || (a==h && b==g)){
                gh = d;
            }
        }

        vector<int> target(t);
        for(int i=0;i<t;i++) cin >> target[i];

        dijkstra(s, distS);
        dijkstra(g, distG);
        dijkstra(h, distH);

        vector<int> ans;

        for(int x : target){
            int path1 = distS[g] + gh + distH[x];
            int path2 = distS[h] + gh + distG[x];

            if(distS[x] == path1 || distS[x] == path2){
                ans.push_back(x);
            }
        }

        sort(ans.begin(), ans.end());

        for(int x : ans) cout << x << " ";
        cout << "\n";
    }
}
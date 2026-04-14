#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1e9

int V,E;
int startNode;

struct Data{
    int node;
    int weight;
};

vector<Data> v[20001]; 

void input(){
    cin >> V >> E;
    cin >> startNode;
    int a,b,c;
    for(int i=0;i<E;i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c}); 
    }
}

int main(){
    input();

    vector<int> dijk(V+1, MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dijk[startNode] = 0;
    pq.push({0, startNode});
    while(!pq.empty()){
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist > dijk[now]) continue;

        for(auto next : v[now]){
            int nextNode = next.node;
            int nextDist = dist + next.weight;

            if(nextDist < dijk[nextNode]){
                dijk[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }

    for(int i=1;i<=V;i++){
        if(dijk[i] == MAX) cout << "INF\n";
        else cout << dijk[i] << "\n";
    }
}
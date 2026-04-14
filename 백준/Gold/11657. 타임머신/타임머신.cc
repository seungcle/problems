#include <iostream>
#include <vector>

#define MAX 1e9

using namespace std;

int N, M;

struct Edge
{
    int start;
    int end;
    int cost;
};

vector<Edge> v;
long long dist[501];

void input(){
    cin >> N >> M;
    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    for(int i = 1; i <= N; i++)
        dist[i] = MAX;

    dist[1] = 0; 
}

bool bellmanFord(){
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < M; j++){
            int s = v[j].start;
            int e = v[j].end;
            int c = v[j].cost;

            if(dist[s] == MAX) continue; 

            if(dist[e] > dist[s] + c){
                dist[e] = dist[s] + c;

                if(i == N) return false;
            }
        }
    }
    return true;
}

int main(){
    input();

    if(!bellmanFord()){
        cout << -1;
    } else {
        for(int i = 2; i <= N; i++){
            if(dist[i] == MAX) cout << -1 << "\n";
            else cout << dist[i] << "\n";
        }
    }
}
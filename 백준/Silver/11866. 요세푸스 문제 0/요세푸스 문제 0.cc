#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    queue<int> q,r;
    
    for(int i=1;i<=n;i++)
        q.push(i);
    
    while(!q.empty()){
        for(int i=1;i<k;i++){
            q.push(q.front());
            q.pop();
        }
        r.push(q.front());
        q.pop();
    }
    
    cout<<"<";
    while(r.size()>1){
        cout<<r.front()<<", ";
        r.pop();
    }
    cout<<r.front()<<">";
    return 0;
}
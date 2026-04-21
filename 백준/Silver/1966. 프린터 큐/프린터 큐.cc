#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int testcase;
    cin>> testcase;
    
    for(int i=0;i<testcase;i++){
        int n=0,m=0;
        int count=0;
        queue <pair<int,int> > q;
        priority_queue<int> pq;
        
        cin>>n>>m;
        
        for(int j=0;j<n;j++){
            int val;
            cin>>val;
            
            q.push({j,val});
            pq.push(val);
        }
        
        while(!q.empty()){
            int currentIndex=q.front().first;
            int currentVal=q.front().second;
            q.pop();
            
            if(pq.top()==currentVal){
                pq.pop();
                count++;
                
                if(currentIndex==m){
                    cout<<count<<endl;
                    break;
                }
            }
            else q.push({currentIndex,currentVal});
        }
    } return 0;
}
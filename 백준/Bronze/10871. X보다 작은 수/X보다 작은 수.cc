#include<iostream>
using namespace std;
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>a;
    for(int i=0;i<n;i++){
    cin>>b;
    if(a>b)
    cout<<b<<" ";
    }
    return 0;
}
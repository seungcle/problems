#include<iostream>
using namespace std;
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++){
    for(j=1;j<=i;j++)
        cout<<"*";
    cout<<"\n";
    }
    return 0;
}
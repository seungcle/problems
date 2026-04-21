#include<iostream>
using namespace std;
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int a,k,n,i,j;
    cin>>n;
    a=1;
    for(i=n;i>0;i--){
    for(j=1;j<i;j++){
        cout<<" ";
    }
    for(k=0;k<a;k++){
        cout<<"*";
    }
    a=a+1;
    cout<<"\n";
    }
    return 0;
}
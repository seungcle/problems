#include<iostream>
using namespace std;
int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,a;
    cin>>n;
    a=1;
    for(int i=0;i<n;i++){
    cout<<a<<"\n";
    a=a+1;
    }
    return 0;
}
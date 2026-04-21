#include<iostream>
using namespace std;
int main(){
    int n,s=0; int a[42]={0};
    for(int i=0;i<10;i++){
        cin>>n;
        if(!a[n%42]++){
            s++;
        }
    }
    cout<<s;
}
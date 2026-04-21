#include<iostream>
using namespace std;
int main(){
    int n,c,d;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    c=a[0]; d=a[0];
    for(int i=0;i<n;i++)
    if(c>a[i])
    c=a[i];
    for(int i=0;i<n;i++)
    if(d<a[i])
    d=a[i];
    cout<<c<<" "<<d;
}
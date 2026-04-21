#include<iostream>
using namespace std;
int main(){
    int a[9],b,c;
    for(int i=0;i<9;i++)
        cin>>a[i];
    b=a[0]; c=0;
    for(int i=0;i<9;i++)
        if(b<a[i]){
        b=a[i];
        c=i;
        }
    cout<<b<<endl<<c+1;
}
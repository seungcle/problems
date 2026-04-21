#include<iostream>
using namespace std;
int main(void){
    int a[3],b[2],c,d;
    cin>>a[0];
    c=a[0];
    for(int i=1;i<3;i++){
        cin>>a[i];
        if(a[i]<c)
        c=a[i];
    }
    for(int i=0;i<2;i++)
        cin>>b[i];
    if(b[0]<b[1])
        d=b[0];
    else
        d=b[1];
    cout<<c+d-50;
}
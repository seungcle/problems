#include<iostream>
using namespace std;
int main(void){
    int x,y,t;
    cin>>x>>y;
    if(x>0 && y>0)
    t=1;
    else if(x<0 && y>0)
    t=2;
    else if(x<0 && y<0)
    t=3;
    else if(x>0 && y<0)
    t=4;
    cout<<t;
}
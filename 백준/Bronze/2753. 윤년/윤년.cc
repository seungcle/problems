#include<iostream>
using namespace std;
int main(void){
    int y;
    int tmp;
    cin>>y;
    if(y%4==0 && y%100!=0 || y%400==0)
    y=1;
    else
    y=0;
    cout<<y;
}
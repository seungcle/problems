#include<iostream>
using namespace std;
int main(void){
    int h,m;
    cin>>h>>m;
    if(m>44)
    m=m-45;
    else if(m<45 && h!=0){
    m=m+60-45;
    h=h-1;
    }
    else{
    m=m+60-45;
    h=23;
    }
    cout<<h<<" "<<m;
}
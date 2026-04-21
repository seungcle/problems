#include<iostream>
using namespace std;
int main(void){
    int a,b;
    cin>>a>>b;
    int c1,c2,c3;
    int tmp;
    c1=b%10;
    c2=b-c1;
    c2=c2/10;
    c2=c2%10;
    c3=b/100;
    cout<<c1*a<<endl;
    cout<<c2*a<<endl;
    cout<<c3*a<<endl;
    cout<<a*b<<endl;
}
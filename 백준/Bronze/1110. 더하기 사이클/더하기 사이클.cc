#include<iostream>
using namespace std;
int main(void){
    int a,c,i,j,k,n;
    cin>>n;
    
    if(n<10)
    n=n*10;
    
    a=n; c=0;
    
    while(1){
    i=a/10; j=a%10;
    k=i+j;     
    a=(j*10)+(k%10);
    c++;
    if(a==n)
    break;
    }
    cout<<c;
}
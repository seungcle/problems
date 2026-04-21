#include<iostream>
using namespace std;
int factorial(int n){
    if(n>2)
    n*=factorial(n-1);
    return n;
}
int main(){
    int n,result=1;
    cin>>n;
    if(n!=0)
    result=factorial(n);
    cout<<result;
}
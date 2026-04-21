#include<iostream>
using namespace std;
int main(void){
    int a[5];
    for(int i=0;i<5;i++){
        cin>>a[i];
        if(a[i]<40)
        a[i]=40;
    }
    int b=0;
    for(int i=0;i<5;i++)
        b=b+a[i];
    b=b/5;
    cout<<b;
}
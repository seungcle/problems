#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    int arr[10]={0};
    
    cin>>a>>b>>c;
    int d=a*b*c;
    while(d!=0){
        arr[d%10]+=1;
        d/=10;
    }
    for(int i=0;i<10;i++)
        cout<<arr[i]<<endl;
}
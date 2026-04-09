#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n == 0) cout << "BOJ 30000";
    if(n == 1){
        long long x=989345275647;
        while(1){
            cout<<x<<"\n";
            if(x==1)break;
            if(x%2)x=3*x+1;
            else x/=2;
        }
    }
}
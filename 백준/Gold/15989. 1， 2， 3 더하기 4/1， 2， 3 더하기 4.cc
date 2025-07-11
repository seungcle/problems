#include<iostream>

using namespace std;
int t;
int n;

void solution(){
    int ans = 0;
    if(n==1)
    {
        cout << "1" << "\n";
        return;
    }
    else if(n == 2)
    {
        cout << "2" << "\n";
        return;
    }
    ans = n/2 + ans + 1;
    //cout << "first: " << ans << '\n';
    for(int i=3;i<=n;i=i+3)
    {
        ans = ans + (n-i)/2 + 1;
        //cout << i << ": " << ans << '\n';
    }
    cout << ans << "\n";
}

int main(){
    cin >> t;
    
    for(int i=0;i<t;i++)
    {
        cin >> n;    
        solution();
    }
}
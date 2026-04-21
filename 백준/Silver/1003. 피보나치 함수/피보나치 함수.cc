#include <iostream>

using namespace std;

int arr[41]={0,1,1};
int T,N;

void solve()
{
    for(int i=3;i<41;i++)   //답 초기화
        arr[i] = arr[i-1]+arr[i-2]; 

    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> N;
        if(N == 0) cout << "1 0" << endl;
        else if(N == 1) cout << "0 1" << endl;
        else cout << arr[N-1] << " " << arr[N] << endl; 
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}
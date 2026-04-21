#include<iostream>

using namespace std;

int main()
{
    int N;
    int ans;
    cin >> N;
    ans = N/5 + N/25 + N/125;
    cout << ans;
}
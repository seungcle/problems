#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[10003];

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i+1] > arr[i+2])
        {
            int two = min(arr[i], arr[i+1] - arr[i+2]);
            arr[i] -= two;
            arr[i+1] -= two;
            cnt += two * 5;
        }

        int three = min(min(arr[i], arr[i+1]), arr[i+2]);
        arr[i] -= three;
        arr[i+1] -= three;
        arr[i+2] -= three;
        cnt += three * 7;

        cnt += arr[i] * 3;
        arr[i] = 0;
    }

    cout << cnt;
}

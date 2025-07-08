#include<iostream>
#include<algorithm>
using namespace std;

int n;
long long b,c;
int arr[1000003];

int main()
{
    cin >> n >> b >> c;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    long long cnt = 0;
    if(c>=b)
    {
        for(int i=0;i<n;i++)
        {
            cnt = cnt +  arr[i] * b;
        }
        cout << cnt;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i+1] > arr[i+2])
        {
            long long two = min(arr[i], arr[i+1] - arr[i+2]);
            arr[i] -= two;
            arr[i+1] -= two;
            cnt += two * (b+c);
        }

        long long three = min(min(arr[i], arr[i+1]), arr[i+2]);
        arr[i] -= three;
        arr[i+1] -= three;
        arr[i+2] -= three;
        cnt += three * (b+c+c);

        cnt += arr[i] * b;
        arr[i] = 0;
    }

    cout << cnt;
    return 0;
}

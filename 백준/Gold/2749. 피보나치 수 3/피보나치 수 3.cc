#include<iostream>

using namespace std;

#define MOD 1000000;

long long n;
int arr[3] ={0,1,1};
int p = 1500000;

int main()
{
    cin >> n;
    int tmp = 0;
    int k = n%p;
    if(k==0) {
        cout << "0";
        return 0;
    }
    else if(k==1 || k==2){
        cout <<"1";
        return 0;
    }
    for(int i=3;i<=k;i++)
    {
        tmp = tmp % 3;
        if(tmp == 0)
        {
            arr[0] = (arr[1] + arr[2])%MOD;
        }
        else if(tmp == 1)
        {
            arr[1] = (arr[0] + arr[2])%MOD;
        }
        else
        {
            arr[2] = (arr[0] + arr[1])%MOD;
        }
        tmp++;
    }
    cout << arr[(tmp-1)%3];
}
#include<iostream>

using namespace std;

int main()
{
    int N = 0;
    int test[1000];
    int max = 0;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> test[i];
        if(max < test[i])
            max = test[i];
    }
    float avg = 0;
    for(int i=0;i<N;i++)
    {
        avg = avg + test[i];
    }
    avg = avg * 100 / max / N;
    cout << avg;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000];
int n;

int main() {
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> lis;

    for(int i=0;i<n;i++){
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);

        if(it == lis.end()) lis.push_back(arr[i]);
        else *it = arr[i];
    }

    cout << lis.size();
}
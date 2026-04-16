#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int n;

int main() {
    int tmp;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    vector<int> lis;

    for(int i=0;i<n;i++){
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);

        if(it == lis.end()) lis.push_back(arr[i]);
        else *it = arr[i];
    }

    cout << lis.size();
}
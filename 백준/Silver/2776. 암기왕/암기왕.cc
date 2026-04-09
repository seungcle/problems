#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, N, M, num;
vector<int> note;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        note.clear();

        cin >> N;
        while (N--)
        {
            cin >> num;
            note.push_back(num);
        }

        sort(note.begin(), note.end());

        cin >> M;
        while (M--)
        {
            cin >> num;
            cout << binary_search(note.begin(), note.end(), num) << "\n"; 
        }
    }

    return 0;
}
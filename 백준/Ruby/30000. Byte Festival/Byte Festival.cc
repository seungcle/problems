#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    if (n == 0) cout << "BOJ 30000";
    
    if (n == 1) {
        long long x = 989345275647;
        while (1) {
            cout << x << "\n";
            if (x == 1) break;
            if (x % 2) x = 3 * x + 1;
            else x /= 2;
        }
    }

    if (n == 3) {
        string border = "###   " + string(1000, '#');
        vector<string> patterns = {"###", "#########", "###############", "###########################", "#######", "#"};
        cout << border << endl;
        cout << "# #   #" << string(900, ' ') << "#" << endl;
        cout << border << endl;
        for (int i = 0; i < 3; ++i) cout << endl;
        for (int row = 0; row < 20; ++row) {
            for (int col = 0; col < 15; ++col) {
                if (col % 5 == 0) cout << patterns[2] << "   ";
                else if (col % 2 == 0) cout << patterns[1] << "   ";
                else cout << patterns[0] << "   ";
            }
            cout << "\n";
            if (row % 4 == 3) cout << "###   " << patterns[3] << "   " << patterns[2] << "   " << patterns[1] << endl;
        }
    }

    if (n == 4) {
        string s = "";
        for (int i = 126; i >= 32; --i) s += (char)i;

        while (true) {
            cout << s << "\n"; 
            
            bool changed = false;
            for (int i = 0; i < s.length() - 1; ++i) {
                if (s[i] > s[i + 1]) {
                    swap(s[i], s[i + 1]);
                    changed = true;
                    break; 
                }
            }
            if (!changed) break; 
        }
    }
    return 0;
}
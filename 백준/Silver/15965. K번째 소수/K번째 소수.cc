#include <iostream>
#include <vector>
using namespace std;

#define MAX 8000000

int isPrime(int n) {
    int half = MAX / 2;

    vector<bool> prime(half, true);

    prime[0] = false; 

    for (int i = 1; (2*i+1)*(2*i+1) <= MAX; i++) {
        if (prime[i]) {
            int p = 2*i + 1;
            for (int j = (p*p)/2; j < half; j += p) {
                prime[j] = false;
            }
        }
    }

    int cnt = 1; 
    for (int i = 1; i < half; i++) {
        if (prime[i]) {
            cnt++;
            if (cnt == n) return 2*i + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    cout << isPrime(n);
}
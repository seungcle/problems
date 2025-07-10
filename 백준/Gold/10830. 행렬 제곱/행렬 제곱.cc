#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<int> > matrix;

ll N, B;
matrix A;

// 행렬 곱셈 함수
matrix multiply(const matrix& m1, const matrix& m2) {
    matrix result(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
            result[i][j] %= 1000;
        }
    }
    return result;
}

// 분할 정복을 이용한 행렬 거듭제곱 함수
matrix power(const matrix& m, ll b) {
    if (b == 1) {
        return m;
    }

    matrix half = power(m, b / 2);
    matrix result = multiply(half, half);

    if (b % 2 == 1) {
        result = multiply(result, A);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> B;

    A.assign(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
            A[i][j] %= 1000; // 초기 입력값도 1000으로 나눈 나머지를 저장
        }
    }

    matrix result = power(A, B);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

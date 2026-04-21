#include <iostream>
#include <vector>

using namespace std;

int D[2001][2001] = {};
int Output[2001][2001] = {};
int Save[2001][2001] = {};

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int M, N;
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i)
    {
        string Str;
        cin >> Str;

        for (int j = 0; j < M; ++j)
            D[i][j] = (int)Str[j] - (int)'0';
    }

    if (M == 1)
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; ++i)
    {
        Output[i][0] = D[i][0];
    }

    int Max = 0;
    
    for (int j = 1; j < M; ++j)
    {
        for (int i = 0; i < N; ++i)
        {
            Save[i][j] = Output[i][j - 1];
            if (i - 1 >= 0)
            {
                Save[i][j] = max(Output[i - 1][j - 1], Save[i][j]);
            }

            if (i + 1 < N)
            {
                Save[i][j] = max(Output[i + 1][j - 1], Save[i][j]);
            }

            Output[i][j] = Save[i][j] + D[i][j];

            Max = max(Save[i][j], Max);
        }
    }

    cout << Max;
}
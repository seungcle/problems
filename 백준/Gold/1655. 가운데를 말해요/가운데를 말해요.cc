#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

priority_queue<int> pq_max;
priority_queue<int,vector<int>,greater<int> > pq_min;
vector<int> v;
int n;

void solve()
{
    cin >> n;
    int cur;
    cin >> cur;
    pq_max.push(cur);
    v.push_back(cur);

    for(int i=1;i<n;i++)
    {
        cin >> cur;

        if(i%2 == 0)
        {
            if(cur > pq_min.top())
            {
                pq_max.push(pq_min.top());
                pq_min.pop();
                pq_min.push(cur);
                v.push_back(pq_max.top());
            }
            else
            {
                pq_max.push(cur);
                v.push_back(pq_max.top());
            }
        }
        else
        {
            if(cur < pq_max.top())
            {
                pq_min.push(pq_max.top());
                pq_max.pop();
                pq_max.push(cur);
                v.push_back(pq_max.top());
            }
            else
            {
                pq_min.push(cur);
                v.push_back(pq_max.top());
            }
        }
    }
}

void p_answer()
{
    for(int i=0;i<v.size();i++)
        cout << v[i] << '\n';
}

int main()
{
    solve();
    p_answer();
}
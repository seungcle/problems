#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

string str;
int k,ans;
queue<string> q;

bool visited[11][1000001];

int stringToInt(string s){
    int len = s.length();
    int n = 0;
    for(int i=0;i<len;i++){
        n = n * 10;
        n = n + s[i] -'0';
    }
    return n;
}

int main(){
    cin >> str >> k;
    int len = str.length();

    if(len == 1) {
        cout << "-1";
        return 0;
    }

    q.push(str);
    visited[0][stringToInt(str)] = true; 

    for(int depth = 0; depth < k; depth++){
        int qSize = q.size(); 

        while(qSize--){
            string tmp = q.front();
            q.pop();

            for(int i=0;i<len;i++){
                for(int j=i+1;j<len;j++){
                    string tmp2 = tmp;
                    swap(tmp2[i],tmp2[j]);

                    if(tmp2[0] == '0') continue;

                    int num = stringToInt(tmp2);

                    if(!visited[depth+1][num]){
                        visited[depth+1][num] = true;
                        q.push(tmp2);
                    }
                }
            }
        }
    }

    if(q.empty()){
        cout << -1;
        return 0;
    }

    while(!q.empty()){
        string tmp = q.front();
        q.pop();
        ans = max(ans,stringToInt(tmp));
    }

    cout << ans;
    return 0;
}
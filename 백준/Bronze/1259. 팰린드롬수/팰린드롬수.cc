#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string s,tmp;
    while(true)
    {
        cin >> s;
        if(s == "0") break;
        tmp = s;
        reverse(s.begin(),s.end());
        if(s == tmp)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}
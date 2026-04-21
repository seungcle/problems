#include<iostream>
#include<string>
using namespace std;
int main(){
    string text;
    getline(cin,text);
    while(text.length()>0)
    {
        cout<<text<<endl;
        getline(cin,text);
    }
return 0;
}
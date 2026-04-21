#include<iostream>
#include<string>

using namespace std;

int main(){
    int alpha[27];
    string n;
    cin>>n;
    for(int i=0;i<26;i++){
        alpha[i]=-1;
    }
    for(int i=0;i<n.length();i++){
        if(alpha[n[i]-97]==-1)
            alpha[n[i]-97]=i;
    }
    for(int i=0;i<26;i++){
        cout<<alpha[i]<<" ";
    }
    return 0;
}
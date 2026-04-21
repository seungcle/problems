#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n,a=0;
    cin>>n;
    
    stack<int> st;
    int str;
    
    for(int i=0;i<n;i++){
        cin>>str;
        if(str==0){
            st.pop();
        }else{
            st.push(str);
        }
    }
    
    while(!st.empty()){
        a+=st.top();
        st.pop();
    }
    
    cout<<a;
    return 0;
}
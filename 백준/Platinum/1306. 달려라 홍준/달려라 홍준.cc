#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int num[1000001];
int tree[4000001];

void build(int node,int st,int ed){
    if(st == ed){
        tree[node] = num[st];
        return;
    }
    int mid = (st+ed)/2;
    build(node*2,st,mid);
    build(node*2+1,mid+1,ed);
    tree[node] = max(tree[node*2],tree[node*2+1]);
}

int query(int node,int st,int ed,int left,int right){
    if(right<st || ed < left) return 0;
    if(left <= st && ed <= right) return tree[node];

    int mid = (st+ed)/2;
    int left_child = query(node*2,st,mid,left,right);
    int right_child = query(node*2+1,mid+1,ed,left,right);

    return max(left_child,right_child);
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    build(1,0,n-1);
    for(int i=m-1;i<=n-m;i++){
        int left = i - (m-1);
        int right = i + (m-1);
        cout << query(1,0,n-1,left,right) << " ";
    }
}
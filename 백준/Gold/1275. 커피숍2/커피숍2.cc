#include <iostream>
#include <algorithm>
using namespace std;

int n, q, x, y, a;
long long b;
long long arr[100000];
long long tree[400000];

void build(int index, int start, int end) {
    if (start == end) {
        tree[index] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(index * 2, start, mid);
    build(index * 2 + 1, mid + 1, end);
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}

void update_tree(int index, int start, int end, long long diff, int vi) {
    if (vi < start || vi > end) return;
    tree[index] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update_tree(index * 2, start, mid, diff, vi);
    update_tree(index * 2 + 1, mid + 1, end, diff, vi);
}

void update(int index, long long value) {
    long long diff = value - arr[index];
    arr[index] = value;
    update_tree(1, 0, n - 1, diff, index);
}

long long query(int index, int start, int end, int x, int y) {
    if (x <= start && end <= y) return tree[index];
    if (x > end || y < start) return 0;
    int mid = (start + end) / 2;
    return query(index * 2, start, mid, x, y) + query(index * 2 + 1, mid + 1, end, x, y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(1, 0, n - 1);

    for (int i = 0; i < q; i++) {
        cin >> x >> y >> a >> b;
        int l = min(x, y);
        int r = max(x, y);
        cout << query(1, 0, n - 1, l - 1, r - 1) << "\n";
        update(a - 1, b);
    }
}

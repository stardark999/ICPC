#include <iostream>
#define MAXN 100000
#define INF (1000000000ll * 1000000000ll)

using namespace std;

long long v[MAXN], d[MAXN], val[14][MAXN];

struct node {
    int l, r;
    long long ml, mr, md;
};

node tree[14][8 * MAXN], trash;

void build(int t, int x, int l, int r) {
    tree[t][x].l = l;
    tree[t][x].r = r;
    if (l == r) {
        tree[t][x].ml = tree[t][x].mr = val[t][l];
        tree[t][x].md = 0;
        return;
    }
    build(t, 2 * x, l, (l + r) / 2);
    build(t, 2 * x + 1, (l + r) / 2 + 1, r);
    tree[t][x].ml = min(tree[t][2 * x].ml, tree[t][2 * x + 1].ml);
    tree[t][x].mr = max(tree[t][2 * x].mr, tree[t][2 * x + 1].mr);
    tree[t][x].md = max(max(tree[t][2 * x].md, tree[t][2 * x + 1].md), tree[t][2 * x + 1].mr - tree[t][2 * x].ml);
}

node query(int t, int x, int ql, int qr) {
    if (ql <= tree[t][x].l && tree[t][x].r <= qr) return tree[t][x];
    if (ql > tree[t][x].r || tree[t][x].l > qr) return trash;
    node n1 = query(t, 2 * x, ql, qr), n2 = query(t, 2 * x + 1, ql, qr);
    node res;
    res.ml = min(n1.ml, n2.ml);
    res.mr = max(n1.mr, n2.mr);
    res.md = max(max(n1.md, n2.md), (n2.mr != INF && n1.ml != INF ? n2.mr - n1.ml : 0));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int cnt[7] = {0, 1, 2, 3, 2, 1, 0};
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> d[i];
        for (int j = 0; j < 7; j++) val[j][i] = v[i] + d[i] * cnt[(7 - j + i) % 7];
        for (int j = 0; j < 7; j++) val[j + 7][n - 1 - i] = v[i] + d[i] * cnt[(7 - j + n - 1 - i) % 7];
    }
    trash.ml = INF;
    trash.mr = 0;
    trash.md = 0;
    for (int i = 0; i < 14; i++) build(i, 1, 0, n - 1);
    int q; cin >> q;
    while (q--) {
        int s, t; cin >> s >> t;
        s--; t--;
        if (s < t) cout << max(query(s % 7, 1, s, t).md, 0ll) << endl;
        else cout << max(query(7 + (n - 1 - s) % 7, 1, n - 1 - s, n - 1 - t).md, 0ll) << endl;
    }
    return 0;
}

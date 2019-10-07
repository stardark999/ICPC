#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int mxv = 0;
    for (int i = 0; i < n; i++) mxv = max(mxv, a[i]);
    set<int> st;
    for (int i = 0; i < n; i++) st.insert(a[i]);
    if (st.size() == mxv) {
        cout << "good job";
        return 0;
    }
    for (int i = 1; i <= mxv; i++) if (st.find(i) == st.end()) cout << i << endl;
    return 0;
}

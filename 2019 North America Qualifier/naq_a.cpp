#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    bool vr[n];
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        vr[i] = (c == 'T');
    }
    char c;
    stack<bool> st;
    while (cin >> c) {
        if (c == '*') {
            bool b1 = st.top();
            st.pop();
            bool b2 = st.top();
            st.pop();
            st.push(b1 && b2);
        } else if (c == '+') {
            bool b1 = st.top();
            st.pop();
            bool b2 = st.top();
            st.pop();
            st.push(b1 || b2);
        } else if (c == '-') {
            bool b1 = st.top();
            st.pop();
            st.push(!b1);
        } else {
            st.push(vr[c - 'A']);
        }
    }
    cout << (st.top() ? 'T' : 'F');
    return 0;
}

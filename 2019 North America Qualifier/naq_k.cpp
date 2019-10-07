#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    int n = s.length();
    vector<int> v[26];
    for (int i = 0; i < 26; i++) v[i].push_back(-1);
    for (int i = 0; i < n; i++) v[s[i] - 'a'].push_back(i);
    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < v[i].size() - 1; j++) {
            set<char> st;
            for (int k = v[i][j] + 1; k < v[i][j + 1]; k++) st.insert(s[k]);
            ans += st.size();
        }
    }
    cout << ans;
    return 0;
}

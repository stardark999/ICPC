#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    bool adj[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> adj[i][j];
    int dp[n + 1][n]; // len, start
    for (int i = 0; i <= n; i++) for (int j = 0; j < n; j++) dp[i][j] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = dp[i - 1][(j + 1) % n];
            for (int k = 1; k < i; k++) {
                int ki = (j + k) % n;
                if (adj[j][ki]) {
                    dp[i][j] = max(dp[i][j], 1 + dp[k - 1][(j + 1) % n] + dp[i - k - 1][(ki + 1) % n]);
                }
            }
        }
    }
    cout << dp[n][0];
    return 0;
}

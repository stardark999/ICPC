#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    double p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] /= 100;
    }
    sort(p, p + n);
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        double dp[i + 1][i + 1];
        for (int j = 0; j < i + 1; j++) for (int k = 0; k < i + 1; k++) dp[j][k] = 0;
        dp[0][0] = 1;
        for (int j = 0; j < i; j++) {
            double pb = p[n - j - 1];
            for (int k = 0; k < i; k++) dp[j + 1][k + 1] += pb * dp[j][k];
            for (int k = 0; k < i; k++) dp[j + 1][k] += (1.0 - pb) * dp[j][k];
        }
        double expv = 0;
        for (int k = 1; k < i + 1; k++) expv += dp[i][k] * pow(k, 1.0 * k / i);
        ans = max(ans, expv);
    }
    cout << fixed << setprecision(7) << ans;
    return 0;
}

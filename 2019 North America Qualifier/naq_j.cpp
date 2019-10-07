#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    double ans = 0;
    for (int t = 0; t < 2; t++) {
        long long pfx = 0;
        for (int i = 0; i < n; i++) {
            pfx += a[i];
            ans = max(ans, 1.0 * pfx / (i + 1));
        }
        for (int i = 0; i < n; i++) {
            int j = n - 1 - i;
            if (i >= j) break;
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
        }
    }
    cout << fixed << setprecision(7) << ans;
    return 0;
}

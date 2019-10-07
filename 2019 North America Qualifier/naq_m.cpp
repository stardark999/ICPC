#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    while (n--) {
        double w, g, h, r; cin >> w >> g >> h >> r;
        cout << fixed << setprecision(7) << sqrt((h - g) * (h - g) + w * w) << " ";
        double l = 0, rr = w;
        while (abs(rr - l) > 1e-9) {
            double m1 = l + (rr - l) / 3;
            double m2 = rr - (rr - l) / 3;
            double f1 = sqrt((g - r) * (g - r) + m1 * m1) + sqrt((h - r) * (h - r) + (w - m1) * (w - m1));
            double f2 = sqrt((g - r) * (g - r) + m2 * m2) + sqrt((h - r) * (h - r) + (w - m2) * (w - m2));
            if (f1 < f2) rr = m2;
            else l = m1;
        }
        cout << fixed << setprecision(7) << sqrt((g - r) * (g - r) + l * l) + sqrt((h - r) * (h - r) + (w - l) * (w - l)) << endl;
    }
    return 0;
}

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int p, d; cin >> p >> d;
    long long v = 0, wa = 0, wb = 0;
    int aav[d], bbv[d];
    for (int i = 0; i < d; i++) aav[i] = bbv[i] = 0;
    while (p--) {
        int di, av, bv; cin >> di >> av >> bv;
        di--;
        aav[di] += av;
        bbv[di] += bv;
    }
    for (int i = 0; i < d; i++) {
        int av = aav[i], bv = bbv[i];
        int tot = av + bv;
        tot = (tot / 2) + 1;
        if (av > bv) {
            cout << "A ";
            cout << av - tot << " " << bv << endl;
            wa += av - tot;
            wb += bv;
        } else {
            cout << "B ";
            cout << av << " " << bv - tot << endl;
            wa += av;
            wb += bv - tot;
        }
        v += av + bv;
    }
    cout << fixed << setprecision(7) << 1.0 * abs(wa - wb) / v;
    return 0;
}

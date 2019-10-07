#include <iostream>

using namespace std;

long long gcd(long long n1, long long n2) {
    return (n2 == 0) ? n1 : gcd (n2, n1 % n2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long a, b; cin >> a >> b;
    long long g = gcd(a, b);
    cout << ((a / g & 1) && (b / g & 1) ? g : 0);
    return 0;
}

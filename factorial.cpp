#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    if(!(cin >> n)) return 0;
    if (n < 0) { cout << "Undefined for negative\n"; return 0; }
    unsigned long long fact = 1;
    for (int i = 2; i <= n; ++i) fact *= i;
    cout << fact << '\n';
    return 0;
}

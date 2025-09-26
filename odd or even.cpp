#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    if(!(cin >> n)) return 0;
    cout << (n % 2 == 0 ? "Even" : "Odd") << '\n';
    return 0;
}
#include <iostream>
#include <conio.h>
using namespace std;
#include <cstdlib>

void main() {
    clrscr();
    int n;
    cout << "How many numbers? ";
    cin >> n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        double x; cin >> x;
        sum += x;
    }
    if (n > 0)
        cout << "\nAverage = " << (sum / n) << "\n";
    else
        cout << "\nNo numbers entered.\n";
    cout << "\nPress any key...";
    getch();
}

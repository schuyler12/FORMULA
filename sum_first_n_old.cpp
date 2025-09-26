#include <iostream.h>
#include <conio.h>

int main() {
    clrscr();
    int n;
    cout << "Enter N: ";
    cin >> n;
    long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;   
    }
    cout << "\nSum of first " << n << " natural numbers = " << sum << "\n";
    cout << "\nPress any key...";
    getch();
}
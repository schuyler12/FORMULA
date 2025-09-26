#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main() {
    system("cls");                    
    long n;
    cout << "Enter an integer: ";
    cin >> n;
    if (n % 2 == 0)
        cout << "\nEven\n";
    else
        cout << "\nOdd\n";
    cout << "\nPress any key to exit...";
    cin.ignore();
    cin.get();
    return 0;
    getch();
}

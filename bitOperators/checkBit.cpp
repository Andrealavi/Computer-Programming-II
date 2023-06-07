#include <iostream>

using namespace std;

bool checkBit(int x, int n)
{
    return (x & (1 << n)) != 0;
}

int main()
{

    int x, n;

    cout << "Insert a number: ";
    cin >> x;
    cout << endl;

    cout << "Insert the position of the bit you want to check (0-based): ";
    cin >> n;
    cout << endl;

    cout << checkBit(x, n) << endl;

    return 0;
}
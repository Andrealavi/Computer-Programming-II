#include <iostream>

using namespace std;

int setBit(int x, int n)
{
    return (x ^ (1 << n));
}

int main()
{

    int x, n;

    cout << "Insert a number: ";
    cin >> x;
    cout << endl;

    cout << "Insert the position of the bit you want to reset (0-based): ";
    cin >> n;
    cout << endl;

    cout << "The new number is: " << setBit(x, n) << endl;

    return 0;
}
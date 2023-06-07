/*
Write a function sum(n, f), which computes f(1)+f(2)+ ... + f(n).
f() is a function passed as a function argument.
Use as f two function: square and cube
*/
#include <iostream>

using namespace std;

int sum(int n, int (*funPnt)(int))
{
    int summation = 0;

    for (int i = 1; i <= n; i++)
    {
        summation += funPnt(i);
    }

    return summation;
}

int square(int n)
{
    return n * n;
}

int cube(int n)
{
    return n * n * n;
}

int main()
{

    int n;

    cout << "Insert a number: ";
    cin >> n;
    cout << endl;

    cout << sum(n, square);
    cout << endl;
    cout << sum(n, cube);
    cout << endl;

    return 0;
}
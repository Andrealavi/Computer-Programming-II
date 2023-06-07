#include <iostream>

using namespace std;

int ex1(int n)
{
    return (n << 1);
}

int ex2(int n)
{
    return (n & 1);
}

int ex3(int n, int i)
{
    return (n << i);
}

int ex4(int n, int i)
{
    return (n >> i);
}

int ex5(int i, int j)
{
    return i >> (32 - j);
}

int ex6(int i, int j)
{
    return i << (32 - j);
}

int ex7(int k, int j)
{
    return ((k >> j) | (k << 32 - j));
}

int ex8(int k, int j)
{
    return ((k << j) | (k >> 32 - j));
}

int ex9(int n)
{
    return (n ^ 1);
}

int ex10(int n)
{
    return (n ^ 0);
}

int main()
{

    cout << ex1(3) << endl;
    cout << ex2(5) << endl;
    cout << ex3(3, 3) << endl;
    cout << ex4(24, 3) << endl;
    cout << ex5(6, 31) << endl;
    cout << ex6(5, 7) << endl;
    cout << ex7(1, 1) << endl;
    cout << ex8(2147483648, 1) << endl;
    cout << ex9(110) << endl;
    cout << ex10(5) << endl;

    return 0;
}
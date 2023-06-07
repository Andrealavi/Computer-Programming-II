/*Write a program which allows to choose among sum, sub, mul and div,
without using if or switch for selecting the operation to do*/
#include <iostream>

using namespace std;

int sum(int n1, int n2)
{
    return n1 + n2;
}

int sub(int n1, int n2)
{
    return n1 - n2;
}

int mul(int n1, int n2)
{
    return n1 * n2;
}

int division(int n1, int n2)
{
    return n1 / n2;
}

int main()
{

    int (*funPnt[4])(int, int) = {sum, sub, mul, division};
    int choice;

    do
    {
        cout << "1)\t Sum\n";
        cout << "2)\t Sub\n";
        cout << "3)\t Mul\n";
        cout << "4)\t Div\n";
        cout << "5)\t Exit\n";

        cout << "Decide which operation do you want to do: ";
        cin >> choice;

        if (choice != 5)
        {
            int n1, n2;

            cout << "Insert the first number: ";
            cin >> n1;

            cout << endl;

            cout << "Insert the second number: ";
            cin >> n2;

            cout << endl;

            cout << "The result is: " << (*funPnt[choice - 1])(n1, n2) << endl;
        }
    } while (choice != 5);

    return 0;
}
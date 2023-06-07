/*Print array values until you find a -1.
You have to print them without using index
 or any global/local variable in the function printArr
*/

#include <iostream>

using namespace std;

void printArr(int *p)
{
    for (; *p != -1; p++)
    {
        cout << *p << endl;
    }
}

int main()
{

    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1};

    printArr(v);

    return 0;
}
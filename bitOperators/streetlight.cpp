/*
Create a program which manages a group of streetlights, saved as a vector of bit.
The program should include these functions:
- Signal a broken streetlight
- Repair a streetlight
- Print streetlights state
- Check for energy saving mode
*/
#include <iostream>

using namespace std;

void flipStreetlight(unsigned int &streetlights, int n)
{
    streetlights = (streetlights ^ (1 << n - 1));
}

void printStreetlightState(unsigned int streetlights)
{
    for (unsigned int i = ~0, j = 0; i != 0; i = i >> 1, j++)
    {
        if ((streetlights & (1 << j)) != 0)
        {
            cout << "Streetlight n. " << j + 1 << ": Running" << endl;
        }
        else
        {
            cout << "Streetlight n. " << j + 1 << ": Broken" << endl;
        }
    }
}

bool checkEnergySavingMode(unsigned int streetlights)
{
    for (unsigned int i = ~0, j = 0; i != 0; i = i >> 1, j++)
    {
        if (((streetlights & (1 << j)) != 0) && (j % 2 != 0))
        {
            return false;
        }
        else if (((streetlights & (1 << j)) == 0) && (j % 2 == 0))
        {
            return false;
        }
    }

    return true;
}

int main()
{

    int choice, n;
    unsigned int streetlights = ~0;

    do
    {
        cout << "1)\t Signal a broken streetlight\n";
        cout << "2)\t Repair a streetlight\n";
        cout << "3)\t Print operating streetlights\n";
        cout << "4)\t Check for energy saving mode\n";
        cout << "5)\t Exit\n";

        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Insert the streetlight you want to signal as broken: ";
            cin >> n;
            cout << endl;

            if ((streetlights & (1 << n)) == 0)
            {
                cout << "The streetlight is already signaled as broken" << endl;
            }
            else
            {
                flipStreetlight(streetlights, n);
            }

            break;
        case 2:
            cout << "Insert the streetlight you want to repair as broken: ";
            cin >> n;
            cout << endl;

            if ((streetlights & (1 << n)) != 0)
            {
                cout << "The streetlight is already repaired" << endl;
            }
            else
            {
                flipStreetlight(streetlights, n);
            }
            break;
        case 3:
            printStreetlightState(streetlights);
            cout << endl;
            break;
        case 4:
            cout << checkEnergySavingMode(streetlights) << endl;
            break;
        case 5:
            return 0;
        default:
            break;
        }
    } while (true);

    return 0;
}
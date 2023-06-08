/*
Write a program in which is defined a two element list (firstElem: 3, secondElem: 7).
Print list's content.
*/
#include <iostream>

using namespace std;

struct elem
{
    int inf;
    elem *pnt;
};

typedef elem *list;

int head(list l)
{
    return l->inf;
}

list tail(list l)
{
    return l->pnt;
}

void printList(list l)
{
    while (l != NULL)
    {
        cout << head(l) << endl;

        l = tail(l);
    }
}

int main()
{

    list l = new elem;
    elem *e = new elem;

    l->inf = 3;
    l->pnt = e;

    e->inf = 7;
    e->pnt = NULL;

    printList(l);

    return 0;
}
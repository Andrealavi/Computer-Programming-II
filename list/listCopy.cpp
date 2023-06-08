/*
Write a program in which is defined a createList(n), function that takes an integer n as input
and create a n-element list. Each element is given by the user, thank to inserElem(list, elem) function.
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

list insertElem(list l, elem *e)
{
    e->pnt = l;
    return e;
}

list createList(int n)
{
    if (n <= 0)
    {
        return NULL;
    }

    list l = new elem;
    int inf;

    cout << "Insert information: ";
    cin >> inf;
    cout << endl;

    l->inf = inf;
    l->pnt = NULL;

    for (int i = 1; i < n; i++)
    {
        elem *e = new elem;

        cout << "Insert information: ";
        cin >> inf;
        cout << endl;

        e->inf = inf;
        e->pnt = NULL;

        l = insertElem(l, e);
    }

    return l;
}

list deleteElem(list l, elem *e)
{
    if (l == NULL)
    {
        return l;
    }
    else if (l == e)
    {
        l = tail(l);
        delete e;
        return l;
    }
    else
    {
        list l1 = l;

        while (l1 != NULL && head(l1) != head(e))
        {
            l1 = tail(l1);
        }

        l1->pnt = e->pnt;

        delete e;

        return l1;
    }
}

void deleteList(list &l)
{
    while (l != NULL)
    {
        l = deleteElem(l, l);
    }
}

list copyList(list l)
{
    list copy = new elem;

    copy->inf = head(l);
    copy->pnt = NULL;

    l = tail(l);

    while (l != NULL)
    {
        elem *e = new elem;

        e->inf = head(l);
        e->pnt = NULL;

        copy = insertElem(copy, e);

        l = tail(l);
    }

    return copy;
}

int main()
{
    int n;

    cout << "Insert list dimension: ";
    cin >> n;
    cout << endl;

    list l = createList(n);

    printList(l);

    list copy = copyList(l);

    printList(copy);

    return 0;
}
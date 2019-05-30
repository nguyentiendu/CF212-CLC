#include <bits/stdc++.h>
#include "Vector.h"
using namespace std;
int main()
{
    Vector<int> x;
    x.addFront(3);
    x.addFront(2);
    x.addFront(1);
    x.addFront(0);
    x.print();
    x.removeFront();
    x.print();
    return 0;
}
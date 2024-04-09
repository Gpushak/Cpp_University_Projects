#include "List.h"
#include <iostream>
using namespace std;

void main()
{
    List a, b;
    
    int c;
    cout << "a:" << endl;
    for (int i = 0; i < 3; i++) {
        cin >> c ;
        a.push_back(c);
    }
    cout << "b:" << endl;
    for (int i = 0; i < 3; i++) {
        cin >> c;
        b.push_back(c);
    }
    List sum = a + b;
    for (int i = 0; i < int(sum); i++) {
        cout << sum[i] << " ";
    }
    cout << endl;
    List::Iterator it = a.first();
    --it;
}

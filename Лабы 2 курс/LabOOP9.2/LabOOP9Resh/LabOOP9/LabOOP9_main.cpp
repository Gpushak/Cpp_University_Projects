#include "List.h"
#include "error.h"
#include <iostream>
using namespace std;

void main()
{
    List a, b;

    int c;
    try {
        cout << "a:" << endl;
        for (int i = 0; i < 3; i++) {
            cin >> c;
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
        int wha;
        cout << "What number? ";
        cin >> wha;
        cout << sum[wha];
    }
    catch (error e)
    {
        e.what();
    }

    
}

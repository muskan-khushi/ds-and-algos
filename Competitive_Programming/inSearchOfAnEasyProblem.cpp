#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> opinion(n);
    for (int i = 0; i < n; i++)
    {
        cin >> opinion[i];
        if (opinion[i] == 1)
        {
            cout << "HARD" << endl;
            return 0;
        }
    }

    cout << "EASY" << endl;

    return 0;
}
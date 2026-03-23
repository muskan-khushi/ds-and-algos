#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<char> color(n);

    for (int i=0; i<n; i++){
        cin >> color[i];
    }

    int count = 0;
    
    for (int i=0; i<n-1; i++){
        if (color[i] == color[i+1]) count++;
    }

    cout << count << endl;


    return 0;
}
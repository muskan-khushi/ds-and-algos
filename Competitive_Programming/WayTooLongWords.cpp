#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<string> str(n);
    for (int i=0; i<n; i++){
       cin >> str[i];
    }

    vector<string> ans;
    for (int i=0; i<n; i++){
        if (str[i].size() >10 ){
            cout << str[i][0] << str[i].size()-2 << str[i][str[i].size()-1] << endl;
        }
        else cout << str[i] << endl;
    }

    return 0;
}

//Optimised Approach
// int n;
// cin >> n;

// while (n--) {
//     string s;
//     cin >> s;

//     if (s.size() > 10)
//         cout << s[0] << s.size()-2 << s.back() << "\n";
//     else
//         cout << s << "\n";
// }
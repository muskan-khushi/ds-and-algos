#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while (t--){
        string keyboard;
        cin >> keyboard;

        string s;
        cin >> s;

        vector<int> pos(26);
        for (int i=0; i<26; i++){
            pos[keyboard[i] - 'a'] = i;
        } 
        
        int time = 0;
        for (int i=1; i<s.size(); i++){
            time += abs(pos[s[i] - 'a'] - pos[s[i-1] - 'a']);
        }

        cout << time << endl;
    }

    return 0;
}
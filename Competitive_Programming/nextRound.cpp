#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    int count = 0;

    vector<int> score(n);
    for (int i=0; i<n; i++){
        cin >> score[i];
        if (score[i] > 0 && score[i] >= score[k-1]) count++;
    }

    cout << count << endl;
    return 0;
}
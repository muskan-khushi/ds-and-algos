#include <bits/stdc++.h>
using namespace std;

int main(){

    int d, sumTime;
    cin >> d >> sumTime;

    vector<int> minTime(d);
    vector<int> maxTime(d);

    int minSum = 0;
    int maxSum = 0;

    for (int i=0; i<d; i++){
        cin >> minTime[i] >> maxTime[i];
        minSum += minTime[i];
        maxSum += maxTime[i];
    }

    if (sumTime < minSum || sumTime > maxSum){
         cout << "NO" << endl;
         return 0;
    }
    else cout << "YES" << endl;

    vector<int> schedule = minTime;
    int remaining = sumTime - minSum;

    for (int i=0; i<d; i++){
        int extra = maxTime[i] - minTime[i];
        int add = min(remaining, extra);
        schedule[i] += add;
        remaining -= add;
    }

    for (int x : schedule){
        cout << x << " ";
    }
    cout << endl;



    return 0;
}
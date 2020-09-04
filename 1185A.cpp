#include <bits/stdc++.h>

using namespace std;

int main() {
    
    vector<int> v;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());

    int d1 = abs(v[0] - v[1]);
    int d2 = abs(v[2] - v[1]);
    int dif1 = max(0, d - d1);
    int dif2 = max(0, d - d2);
    cout << dif1 + dif2 << "\n";
    return 0;
}


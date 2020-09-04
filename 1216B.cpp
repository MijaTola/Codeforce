#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > v;
int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back({x,i});
    }
    
    sort(v.rbegin(), v.rend());
    int sum = 0;
    for (int i = 0; i < n; ++i) 
        sum += (v[i].first * i + 1);
    cout << sum << "\n";
    for (auto x: v)
        cout << x.second + 1 << " ";
    cout << "\n";
    return 0;
}


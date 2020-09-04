#include <bits/stdc++.h>

using namespace std;

int v[200010];
vector<int> a,b;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v[x]++;
    }
    
    for (int i = 0; i < 200010; ++i) {
        if(v[i] > 2) return cout << "NO\n",0;
        if(v[i] == 2) {
            a.push_back(i);
            b.push_back(i);
        } else if(v[i] == 1){
            a.push_back(i);
        }
    }
    
    cout << "YES\n";
    
    sort(a.begin(), a.end());
    cout << a.size() << "\n";
    for (int x: a)
        cout << x << " ";
    cout << "\n";

    sort(b.rbegin(), b.rend());
    cout << b.size() << "\n";
    for (int x: b)
        cout << x << " ";
    cout << "\n";
    return 0;
}


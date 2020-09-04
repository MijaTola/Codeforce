#include <bits/stdc++.h>

using namespace std;

int n;
string v[110];
bool cmp(string a, string b) {
    return a.size() < b.size();
}

int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v, v + n, cmp);

    for (int i = 0; i < n - 1; ++i) 
        if(v[i + 1].find(v[i]) == string::npos) return cout << "NO\n",0;
    
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << v[i] << "\n";
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int v[10010];
int n;
set<int> s;

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; ++i)
            cin >> v[i], s.insert(v[i]);

    sort(v, v + 2 * n);
    
    if(s.size() == 1) return cout << "-1\n",0;

    for (int i = 0; i < 2 * n; ++i)
        cout << v[i] << " ";
    cout << "\n";
    
    return 0;
}



#include <bits/stdc++.h>

using namespace std;

int n;
int v[110];
int main() {
    
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    
    int mn = sum / 2 + 1;

    int cur = v[0];
    
    vector<int> ans;
    ans.push_back(0);
    for (int i = 1; i < n; ++i) {
        if(v[i] * 2 <= v[0]) {
            cur += v[i];
            ans.push_back(i);
        }
    }
    if(cur >= mn) {
        cout << ans.size() << "\n";
        for (int x: ans)
            cout << x + 1 << " ";
        cout << "\n";
    } else cout << "0\n";



    return 0;
}


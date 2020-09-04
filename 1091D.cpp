#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> b;
int main() {

    int n;

    cin >> n;
    for (int i = 1; i <= n; ++i)
        v.push_back(i);
    
    do {
        for (int i = 0; i < n; ++i)
            b.push_back(v[i]);
    }while(next_permutation(v.begin(),v.end()));
    
    int ans = 0;
    for (int i = 0; i < (int)b.size() - n + 1; ++i) {
        int s = 0;
        for (int j = i; j < i + n and j < (int)b.size(); ++j)
            s += b[j];
        if(s == (n * (n + 1) / 2)) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}


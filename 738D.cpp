#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,a,b,k;
    string s;

    cin >> n >> a >> b >> k >> s;
    
    vector<int> ans;

    int cnt = 1;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '1') cnt = 0;
        else if(cnt == b) ans.push_back(i), cnt = 0;;
        cnt++;
    }
    
    cout << ans.size() - a + 1<< "\n";
    for (int i = 0; i < (int)ans.size() - a + 1; ++i)
        cout << ans[i] + 1 << " ";
    cout << "\n";
    return 0;
}


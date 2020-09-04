#include <bits/stdc++.h>

using namespace std;

int n,m;
string s,t;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> s >> t;
    int ans = 1e9;
    int cur = 0;
    for (int i = 0; i < (int)t.size() - s.size() + 1; ++i){
        int c = 0;
        for (int j = 0; j < (int)s.size(); ++j)
            if(t[i + j] != s[j]) c++;
        if(c < ans){
            cur = i;
            ans = c;
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < (int)s.size(); ++i){
        if(s[i] != t[i + cur]) cout << i + 1 << " ";
    }
    cout << "\n";
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

string s[1010];
int v[1010];
int main() {
    
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) 
        cin >> s[i];
        
    for (int i = 0; i < m; ++i)
        cin >> v[i];

    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        int a = 0,b = 0, c = 0, d = 0, e = 0;
        for (int j = 0; j < n; ++j) {
            if(s[j][i] == 'A') a++;   
            if(s[j][i] == 'B') b++;   
            if(s[j][i] == 'C') c++;   
            if(s[j][i] == 'D') d++;   
            if(s[j][i] == 'E') e++;   
        }
        ans += max(a,max(b,max(c,max(d,e)))) * v[i];
    }
    cout << ans << "\n";
    
    return 0;
}


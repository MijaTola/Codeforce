#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string s; cin >> s;
    
    int c = 0;
    int mx = 0;
    char last = 'a';
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] != last) c++;
        else {
            mx = max(mx,c);
            c = 1;
        }
        last = s[i];
    }
    int a = 0, b = s.size() - 1;
    int p = s.size() - 2;
    while(s[a] != s[b] and a < b) a++,b--;
    a--,b++;
    int l = 1;
    while(s[l] != s[l - 1] and l < b) l++;
    l--;
    int r = s.size() - 2;
    while(s[r] != s[r + 1] and a < r) r--;
    r++;
    a = min(l,a);
    b = min(r,b);
    int t1 = (a + 1) + (l + 1);
    int t2 = (a + 1) + (s.size() - r);
    cout << max(max(t1,t2),mx) << "\n";
    return 0;
}

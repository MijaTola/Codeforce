#include <bits/stdc++.h>

using namespace std;

string t,p;
bool vis[200010];
int a[200010];
bool ver(int k) {
    memset(vis, 0, sizeof vis);
    for (int i = 0; i <= k; ++i) 
        vis[a[i] - 1] = 1;
    string s = "";
    for (int i = 0; i < (int)t.size(); ++i)
        if(!vis[i]) s += t[i];
    int pos = 0;
    for (int i = 0; i < (int) s.size() and pos < (int)p.size(); ++i) 
        if(p[pos] == s[i]) pos++;
    return pos == (int)p.size();
}

int main(){
    cin >> t >> p;
    for (int i = 0; i < (int)t.size(); ++i) 
        cin >> a[i];
    
    int a = -1, b = t.size();
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) a = mid;
        else b = mid;
    }
    cout << a + 1 << "\n";
    return 0;
}


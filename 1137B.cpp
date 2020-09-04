#include <bits/stdc++.h>

using namespace std;

string s,t;
int ds = 0,dz = 0;;
string dt = "";
int v[2 * 500010];
int vis[2 * 500010];
bool ver(int ini, int fin) {
    int total = fin - ini + 1;
    int curU = v[fin];
    if(ini) curU -= v[ini - 1];
    int curZ = total - curU;
    return curZ <= dz and curU <= ds and total <= (int)s.size();
}

int main() {
    
    cin >> s >> t;
    for (int i = 0; i < (int)s.size(); i++) 
        ds += s[i] == '1';
    dz = s.size() - ds;
    int c = 1;
    int pos = 0;
    while((int)dt.size() < 2 * (int)s.size()) {
        vis[pos] = c;
        dt += t;
        c++;
        pos += t.size();
    }

    for (int i = 0; i < (int)dt.size(); ++i) {
        v[i] = dt[i] == '1';
        if(vis[i] == 0) vis[i] = vis[i - 1];
    }
    
    for (int i = 1; i < (int)dt.size(); ++i)
        v[i] += v[i - 1];
    
    int mx = 0;
    int ini = -1;
    int fin = s.size();
    for (int i = 0; i < (int)dt.size(); ++i) {
        int a = i - 1;
        int b = (int)dt.size();
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(!ver(i, mid)) b = mid;
            else a = mid;
        }
        if(b == (int)dt.size()) continue;
        int cur = vis[b] - vis[i] + 1;
        if(i and vis[i - 1] == vis[i]) cur--;
        if(vis[b] == vis[b + 1]) cur--;
        
        if(cur > mx) {
            mx = cur;
            ini = i;
            fin = b;
        }
    }
    if(ini != -1) {
        for (int i = ini; i < fin; i++)
            cout << dt[i];
        int curU = v[fin];
        if(ini) curU -= v[ini - 1];
        int curZ = (fin - ini + 1) - curU;
        while(curU < ds) cout << "1", curU++;
        while(curZ < dz) cout << "0", curZ++;
        cout << "\n";
    } else cout << s << "\n";
    return 0;
}


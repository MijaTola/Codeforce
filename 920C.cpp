#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
int b[200010];

int p[200010];

void init() {
    for (int i = 0; i < 200010; ++i)
        p[i] = i;
}

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    p[px] = py;
}
int main() {
    init();
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cin >> s;
    
    for (int i = 0; i < n; ++i) 
        if(s[i] == '1') 
            merge(i, i + 1);

    for (int i = 0; i < n; ++i) {
        if(v[i] - 1 != i) {
            if(find(v[i] - 1) != find(i)) 
                return cout << "NO\n",0;
        }
    }
        
    cout << "YES\n";
    return 0;
}


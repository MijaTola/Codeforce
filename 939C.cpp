#include <bits/stdc++.h>

using namespace std;

int v[100010];
int b[100010];
int n;

int main(){
    
    int s,f; 
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        b[i] = v[i];
    }
    cin >> s >> f;

    for (int i = 1; i < n; ++i) 
        b[i] += b[i - 1];
    
    s--, f-=2;
    int ans = 0, id;
    int t = 0;
    for (int i = 0; i < n; ++i) {
        int ini = (s - i + n) % n;
        int fin = (f - i + n) % n;
        int cur = -1;
        if(ini <= fin) {
            cur = b[fin];
            if(ini) cur -= b[ini - 1];
        } else {
            cur = b[fin] + b[n - 1];
            if(ini) cur -= b[ini - 1];
        }
        if(cur > ans) {
            ans = cur;
            id = i;
        }
    }
    cout << id + 1 << "\n";
  
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int v[100010];
int b[100010];
int av[100010];
int ab[100010];

int main() {
    int n;
    string s;
    cin >> n >> s;

    v[0] = (s[0] == 'G');
    for (int i = 1; i < n; ++i) {   
        if(s[i] == s[i - 1] and s[i] == 'G') 
            v[i] += v[i - 1] + 1; 
        else v[i] = (s[i] == 'G');
        av[i] = s[i] == 'G';
    }
    av[0] = v[0];
    for (int i = 1; i < n; ++i) 
        av[i] += av[i - 1];

    b[n - 1] = (s[n - 1] == 'G');
    for (int i = n - 2; i >= 0; i--) {
        if(s[i] == s[i + 1] and s[i] == 'G') {
            b[i] += b[i + 1] + 1;
        } else b[i] = (s[i] == 'G');
        ab[i] = s[i] == 'G';
    }
    
    ab[0] = b[0];
    
    for (int i = n - 2; i >= 0; i--) 
        ab[i] += ab[i + 1];
    
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'G') continue;
        int r = 0;
        if(s[i + 1] == 'G') 
            r = b[i + 1];
        int l = 0;
        if(s[i - 1] == 'G') 
            l = v[i - 1];
        
        if(r + l < av[n - 1]) {
            mx = max(mx, r + l + 1);
        } else {
            if(r or l) {
                mx = max(mx, r + l);
            }
        }
    }
    for (int i = 0; i < n; ++i)
        mx = max(v[i], mx);
    cout << mx << "\n";
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int n;
char s[300010];
int l[300010];
int r[300010];
bool dl[300010];
bool dr[300010];

int main() {
    scanf("%d %s", &n, s);
    
    for (int i = 0; i < n; ++i) {
        if(s[i] == '?') {
            l[i] = 1;
            r[i] = 1;
        }
        if(s[i] == '(') {
            l[i] = 1;
            r[i] = -1;
        }
        if(s[i] == ')') {
            l[i] = -1;
            r[i] = 1;
        }
    }

    for (int i = 1; i < n; ++i) 
        l[i] += l[i - 1];

    for (int i = n - 2; i >= 0; i--)
        r[i] += r[i + 1];
    
    for (int i = n - 1; i >= 0; i--) 
        dr[i] |= (r[i] <= 0 or dr[i + 1]);

    for (int i = 0; i < n; ++i) {
        dl[i] |= (l[i] <= 0 );
        if(i) dl[i] |= dl[i - 1];
    }
    int id = -1;
    for (int i = 0; i < n; ++i) {
        if(l[i] == 0) return cout << ":(\n",0;
        if(l[i] - r[i + 1] == 0 and !dr[i + 1] and !dl[i]) {
            id = i;
            break;
        }
    }
    
    if(id == -1) return cout << ":(\n",0;
    
    for (int i = 0; i <= id; ++i)
        if(s[i] == '?')cout << "(";
        else cout << s[i];
    
    for (int i = id + 1; i < n; ++i) 
        if(s[i] == '?')cout << ")";
        else cout << s[i];
    cout << "\n";
    return 0;
}


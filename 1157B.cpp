#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int v[10];
int main() {
    cin >> n >> s;
    for (int i = 1; i < 10; ++i)
        cin >> v[i];
    
    int id = -1;
    for (int i = 0; i < n; ++i) {
        int f = s[i] - '0';
        int f1 = v[f];
        if(f1 > f) {
            id = i;
            break;
        }
    }
    if(id == -1) return cout << s << "\n",0;
    while(id < n) {
        int f = s[id] - '0';
        int f1 = v[f];
        if(f1 >= f) 
            s[id] = (char) (f1 + '0');
        else break;
        id++;
    }
    cout << s << "\n";
    return 0;
}


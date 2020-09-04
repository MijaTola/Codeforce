#include <bits/stdc++.h>

using namespace std;

int a[10];
int main() {
    int n,k;
    string s;
    cin >> n >> k >> s;
    
    for (int i = 0; i < n; ++i)
        a[s[i] - '0']++;
    
     
    if(n == 1 and k) {
        cout << 0 << "\n";
        return 0;
    }
    if(s[0] != '1' and k)  {
        s[0] = '1';
        k--;
    }
    int pos = 1;
    while(k and pos < n) {
        if(s[pos] == '0') {
            pos++;
            continue;
        }
        s[pos] = '0';
        pos++;
        k--;
    }
    cout << s << "\n";

    return 0;
}

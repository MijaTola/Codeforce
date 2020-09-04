#include <bits/stdc++.h>

using namespace std;

string s;
int n;

int main() {
    cin >> s;
    n = s.size();
    int flag = 0;
    int ans = 0;
    int id = -1, id2 = -1;
    for (int i = 0; i < n; ++i) {
        if(flag == 0 and s[i] == '[') ans++, flag++;
        if(flag == 1 and s[i] == ':') {
            id = i + 1;
            ans++, flag++;
        }
    }
    flag = 0;
    for (int i = n - 1; i >= 0 and i >= id; i--) {
        if(flag == 0 and s[i] == ']') ans++, flag++;
        if(flag == 1 and s[i] == ':') {
            id2 = i - 1;
            ans++, flag++;
        }
    }
    
    if(ans < 4) return cout << "-1\n",0;
    for (int i = id; i <= id2; i++) {
        if(s[i] == '|') ans++;   
    }
    cout << ans << "\n";
    return 0;
}


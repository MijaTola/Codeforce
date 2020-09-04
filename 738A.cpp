#include <bits/stdc++.h>

using namespace std;

bool vis[110];

int main() {

    int n;
    string s;
    cin >> n >> s;

    string ans = "";
    
    int p = 0;

    while(p < n) {
        bool flag = 0;

        while(s[p] == 'o' and s[p + 1] == 'g' and s[p + 2] == 'o') {
            flag = 1;
            p += 2;
        }

        if(flag) cout << "***";
        else {
            cout << s[p];
        }
        p++;
    }

    cout << "\n";
    


    
    return 0;
}


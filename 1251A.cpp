#include <bits/stdc++.h>

using namespace std;

int a[26];
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        memset(a, 0, sizeof a);
        string  s;
        cin >> s;
        
        int p = 0;

        while(p < (int)s.size()) {
            if(s[p] != s[p + 1]) 
                a[s[p] - 'a'] |= 1, p++;
            else p += 2;
        }


        for (int i = 0; i < 26; ++i)
            if(a[i])
                cout << (char)(i + 'a');
        cout << "\n";

    }
    return 0;
}


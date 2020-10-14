#include <bits/stdc++.h>

using namespace std;

int a[300010];

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        string s;
        cin >> n >> k >> s;

        
        bool flag = 1;
        vector<int> cnt(2,0);
        for (int i = 0; i < k; ++i) {
            set<char> st;

            for (int j = i; j < n; j += k) {
                if(s[j] != '?') st.insert(s[j]);
            }

            if(st.size() == 1) {
                char x = *st.begin();
                for (int j = i; j < n; j += k) 
                    if(s[j] != '?') flag &= x == s[j];

                cnt[x - '0']++;
            } 
            if((int)st.size() > 1) flag = 0;

        }
        
        flag &= cnt[0] <= k / 2 and cnt[1] <= k / 2;
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


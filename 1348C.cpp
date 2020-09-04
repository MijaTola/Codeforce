#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        string s;
        cin >> n >> k >> s;
        sort(s.begin(), s.end());
        set<int> st;

        for (int i = 0; i < k; ++i) {
            st.insert(s[i]);
        }
        
        if((int)st.size() != 1) {
            cout << s[k - 1] << "\n";
            continue;
        }
        
        vector<int> cnt(26, 0);

        for (int i = k; i < n; ++i) 
            cnt[s[i] - 'a']++;
        

        int cur = 0;
        int sum = 0;
        int id = -1;
        for (int i = 0; i < 26; ++i) {
            cur += !!cnt[i];
            if(cnt[i]) id = i;
            sum += cnt[i];
        }
    
        cout << s[0];

        if(cur == 1) {
            int dv = sum / k;
            if(sum % k) dv++;
            for (int i = 0; i < dv; ++i)
                cout << (char) (id + 'a');
            cout << "\n";
            continue;
        }

        for (int i = k; i < n; ++i)
            cout << s[i];
        cout << "\n";

    }
    return 0;
}


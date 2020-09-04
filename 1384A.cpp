#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) 
            cin >> v[i];

        string s = "";
        vector<string> ans;

        for (int i = 0; i < 200; ++i)
            s += "a";
      
        ans.push_back(s);
        
        for (int i = 0; i < n; ++i) {
            int last = 0;
            while((int)s.size() > v[i]) {
                last = s.back() - 'a';
                s.pop_back();
            }
            
            last = (last + 1) % 26;
            while((int)s.size() < 200) s += (char)(last + 'a');
            ans.push_back(s);
        }

        for (auto x: ans)
            cout << x << "\n";
    }
    return 0;
}


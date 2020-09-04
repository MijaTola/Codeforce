#include <bits/stdc++.h>

using namespace std;

vector<int> a[27];
int main() {
    
    string s;
    cin >> s;
    
    for (int i = 0; i < (int)s.size(); ++i) 
        a[s[i] - 'a'].push_back(i);
    

    for (int i = 0; i < (int)s.size(); ++i) {
        bool flag = 0;
        for (int j = 0; j < s[i] - 'a'; ++j) {
            if(!a[j].size()) continue;
            int pos = lower_bound(a[j].begin(), a[j].end(), i) - a[j].begin();
            pos--;
            flag |= (pos < (int)a[j].size() and pos >= 0);
        }

        if(flag) cout << "Ann\n";
        else cout << "Mike\n";
    }
    return 0;
}


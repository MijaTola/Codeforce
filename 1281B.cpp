# include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a[30];
string s,t;
int main() {

    cin >> n;

    while(n--) {

        for (int i = 0; i < 30; ++i) a[i].clear();
        cin >> s >> t;

        for (int i = 0; i < (int)s.size(); ++i) 
            a[s[i] - 'A'].push_back(i);

        bool flag = 0;
        for (int i = 0; i < (int)s.size() and !flag; ++i) {
            for (int j = 0; j < s[i] - 'A' and !flag; ++j) {
                if(s[i] < j + 'A') {
                    int pos = lower_bound(a[j].begin(), a[j].end(), i) - a[j].begin();
                    if(pos >= 0 and pos < (int)a[j].size()) {
                        swap(s[i], s[a[j][pos]]);
                        flag = 1;
                        break;
                    }
                } else {
                    if(a[j].size() and a[j].back() > i) {
                        swap(s[i], s[a[j].back()]);
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(s < t) cout << s << "\n";
        else cout << "---\n";
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        int n;
        cin >> n;

        vector<pair<int,int> > v;
        vector<int> a(27,0);

        string ans(s.size(), '.');

        for (auto x: s)
            a[x - 'a']++;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v.push_back({x,i});
        }

        sort(v.rbegin(), v.rend());

        while(v.back().first == 0) {
            int pos = 27;
            while(!a[pos]) pos--;
            a[pos]--;
            ans[v.back().second] = (char)(pos + 'a');
            v.pop_back();
        }

        int dk = 3;
        for (int i = v.size() - 1; i >= 0 and dk; --i, dk--) {
            int id = -1;
            int pos = 27;
            while(!a[pos] and pos >= 0) pos--;
            char aa = pos + 'a';
            for (int j = 0; j < n; ++j) {
                if(ans[j] != '.') continue;
                int cnt = 0;
                for (int k = 0; k < n; ++k) {
                    if(ans[k] == '.' or j == k) continue;

                    if(aa < ans[k]) {
                        if(dk == 1 and j == 1) {
                            //cout << j << " " << k << "\n";
                            //cout << ans[k] << " poasdflkasdf\n";
                        }
                        cnt += abs(j - k);
                    }
                }

                //if(dk == 1 and j == 1)
                    //cout << cnt << " lelellele\n";
                if(cnt == v[i].first) {
                    id = j;
                    break;
                }
            }


            cout << id << " " << (char)(pos + 'a') << "\n";
            cout << v[i].first << "\n";
            //exit(0);
            a[pos]--;
            ans[id] = (char)(pos + 'a');
        }

        cout << ans << "\n";
    }
    return 0;
}


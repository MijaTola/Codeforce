#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v[10000];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {

        for (int i = 0; i < 10000; ++i)
            v[i].clear();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v[x].push_back(i);
        }
        
        int cnt = 0;
        map<int, string> ans;
        for (int i = 0; i < 10000; ++i) {
            if(v[i].size() == 0) continue;
            string x = to_string(i);
            while((int)x.size() < 4) 
                x = "0" + x;
        
            while(v[i].size() > 1) {
                cnt++;
                for (char c = '0'; c <= '9'; c++) {
                    string y = x;
                    y[0] = c;
                    int val = 0;

                    for (char z: y) 
                        val = val * 10 + (int)(z - '0');

                    if(v[val].size() == 0) {
                        //cout << y << " " << v[i].back()<< " carajo\n";
                        v[val].push_back(v[i].back());
                        ans[v[i].back()] = y;
                        break;
                    }
                }
                v[i].pop_back();
            }

            //cout << x << "\n";
            ans[v[i].back()] = x;;
            
        }

        cout << cnt << "\n";
       
        for (auto p: ans)
            cout << p.second << "\n";

              
    }
    return 0;
}


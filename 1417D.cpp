#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        long long sum = 0;

        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
            sum += v[i];
        }

        if(sum % n != 0) {
            cout << "-1\n";
            continue;
        }

        vector<tuple<int,int,int> > ans;
        int meta = sum / n;

        for (int i = 2; i <= n; ++i) {

            if(v[i] % i != 0) {
                int val = i - v[i] % i;
                ans.push_back({1,i,val});
                v[1] -= val;
                v[i] += val;
            }

            int dv = v[i] / i;
            if(dv > 0) {
                ans.push_back({i,1,dv});
                v[1] += dv * i;
                v[i] -= dv * i;
            }

        }

        for (int i = 2; i <= n; ++i) {
            int df = meta - v[i];
            if(df > 0) {
                ans.push_back({1, i, df});
                v[1] -= df;
                v[i] += df;
            }
        }


        cout << ans.size() << "\n";

        for (auto e: ans) {
            int a,b,c;
            tie(a,b,c) = e;
            cout << a << " " << b << " " << c << "\n";
        }
    }
    return 0;
}


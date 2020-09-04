#include <bits/stdc++.h>

using namespace std;

int n;
pair<int,int> v[50010];
int main() {

    cin >> n;
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
        ans += v[i].first;
    }
    int sum = ans;
    sort(v, v + n);

    for (int i = 1; i <= 100; ++i) {
        for (int j = 0; j < n; ++j) {
            if(v[j].first % i == 0) {
                int ai = v[j].first / i;
                int id = 0;
                if(j == 0) id = 1;
                int aj = v[id].first * i;
                int cur = sum - v[j].first - v[id].first + ai + aj;
                ans = min(ans, cur);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}


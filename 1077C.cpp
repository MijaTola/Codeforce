#include <bits/stdc++.h>

using namespace std;

int n;
pair<int,int> v[200010];
int main() {
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v[i].first = x;
        v[i].second = i;
        sum += x;
    }
    
    sort(v, v + n);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        long long cursum = sum - v[i].first;
        int id = n - 1;
        if(i == n - 1) id--;
        if(cursum - v[id].first == v[id].first) ans.push_back(v[i].second + 1);
    }
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int id: ans)
        cout << id << " ";
    cout << "\n";
    return 0;
}


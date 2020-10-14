#include <bits/stdc++.h>

using namespace std;


void task1() {
    int n,p;

    cin >> n >> p;

    vector<int> v(n);

    for(int &x: v) {
        cin >> x;
    }
 
    sort(v.begin(), v.end());
    vector<int> ans;

    for (int i = 1; i <= 2000; ++i) {
        long long cur = 1;
        for (int j = 0; j < n; ++j) {
            int pos = upper_bound(v.begin(), v.end(), j + i) - v.begin();
            cur *= (pos - j);
            cur %= p;
        }
        if(cur) ans.push_back(i);
    }

    cout << ans.size() << "\n";
    for (int x: ans)
        cout << x << " ";
    cout << "\n";

}
int main() {
    
    task1();

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int main() {
    
    int n,x;
    cin >> n >> x;

    if(n == 1) return cout << "YES\n" << x << "\n",0;
    if(n == 3 and x == 0) return cout << "YES\n1 2 3\n",0;
    if(n == 2 and x == 0) return cout << "NO\n",0;
    if(n == 2) return cout << "YES\n" << x << " " << 0 << "\n", 0;
    int cur = 0;
    for (int i = 1; i <= n - 3; ++i) {
        cur ^= i;
        ans.push_back(i);
    }

    if(cur == x) {
        ans.push_back((1 << 17) + (1 << 18));
        ans.push_back(1 << 18);
        ans.push_back(1 << 17);
    } else {
        int goal = (1 << 17) ^ x;
        ans.push_back(goal ^ cur);
        ans.push_back(goal ^ x);
        ans.push_back(0);
    }
    cout << "YES\n";
    for (int x: ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}


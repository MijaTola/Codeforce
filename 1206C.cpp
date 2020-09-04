#include <bits/stdc++.h>

using namespace std;

vector<int> v,a,b;
int main() {

    int n;
    cin >> n;
    
    if(n % 2 == 0) return cout << "NO\n",0;
    int cur = 2 * n;
    bool flag = 1;
    while(cur > 0) {
        if(flag) {
            a.push_back(cur);
            b.push_back(cur - 1);
        } else {
            a.push_back(cur - 1);
            b.push_back(cur);
        }
        cur-=2;
        flag = !flag;
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int x: b)
        v.push_back(x);

    for (int x: a)
        v.push_back(x);
    
    cout << "YES\n";
    for (int i = 0; i < 2 * n; ++i)
        cout << v[i] << " ";
    cout << "\n";
    return 0;
}


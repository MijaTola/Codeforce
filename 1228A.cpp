#include <bits/stdc++.h>

using namespace std;

bool check(int x) {
    int sz = log10(x) + 1;
    set<int> s;
    while(x) {
        s.insert(x % 10);
        x/=10;
    }
    return sz == (int)s.size();
}
int main() {
    int l,r;
    cin >> l >> r;

    for (int i = l ; i <=r ; ++i)
        if(check(i)) return cout << i << "\n",0;
    cout << "-1\n";
    return 0;
}


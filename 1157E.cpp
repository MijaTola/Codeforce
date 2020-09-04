#include <bits/stdc++.h>

using namespace std;

int n;
int a[200010];
multiset<int> st;
int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        st.insert(x % n);
    }

    for (int i = 0; i < n; ++i) {
        int ma = a[i] % n;
        auto p = st.lower_bound(((n - ma) + n) % n);
        if(p == st.end()) {
            cout << (ma + *st.begin()) % n << " ";
            st.erase(st.begin());
        } else {
            cout << (ma + *p) % n << " ";
            st.erase(p);
        }
    }
    cout << "\n";
    return 0;
}


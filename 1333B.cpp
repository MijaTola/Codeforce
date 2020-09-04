#include <bits/stdc++.h>

using namespace std;

int n,t;

int main() {

    cin >> t;

    while(t--) {
        cin >> n;
        vector<int> a(n),b(n);

        for (int &x: a)
            cin >> x;

        for (int &x: b)
            cin >> x;

        map<int,int> mp;

        for (int i = 0; i < n; ++i)
            mp[a[i]]++;

        bool flag = 1;
        for (int i = n - 1; i >= 0; i--) {
            mp[a[i]]--;
            if(a[i] > b[i]) 
                flag &= mp[-1] > 0;
            else if(a[i] < b[i]) 
                flag &= mp[1] > 0;
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}


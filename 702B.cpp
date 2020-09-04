#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;
vector<long long> v;
int b[100010];

int main(){

    long long p = 1;

    while(p <= INT_MAX) {
        v.push_back(p);
        p <<= 1;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        b[i] = x;
        mp[x]++;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (auto x: v) {
            int dif = x - b[i];
            ans += mp[dif];
            if(dif == b[i]) ans--;
        }
    }
    cout << ans / 2 << "\n";
    return 0;
}


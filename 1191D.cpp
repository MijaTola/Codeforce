#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    map<int,int> mp,mp2;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }
    
    bool flag = 0;
    int cnt = 0;
    for (auto &p: mp) {
        if(p.second == 1) {
            mp2[p.first]++;
            continue;
        }
        
        if(p.second >= 2) {
            if(p.first == 0) return puts("cslnb"),0;
            cnt++;
            flag = 1;
            p.second--;
            mp2[p.first - 1]++;
            mp2[p.first] = p.second;
        }
    }
    
    if(cnt > 1) return puts("cslnb"), 0;

    long long sum = 0;
    for (auto &p: mp2) {
        if(p.second >= 2) return puts("cslnb"), 0;
        sum += p.first;
    }
    n--;
    long long x = (n * (n + 1)) / 2;
    long long dif = sum - x;

    if(!flag) {
        if(dif & 1) cout << "sjfnb\n";
        else cout << "cslnb\n";
    } else {
        if(!(dif & 1)) cout << "sjfnb\n";
        else cout << "cslnb\n";
    }

    return 0;
}


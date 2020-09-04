#include <bits/stdc++.h>

using namespace std;

int n,m;

vector<long long> v[100010];

long long ac[100010];

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        int s,r;
        scanf("%d %d", &s, &r);
        if(r) v[s].push_back(r);
    }
    
    
    long long mx = 0;
    memset(ac, 0, sizeof ac);
    for (int i = 0; i < 100010; ++i) {
        if(v[i].size() == 0) continue;
        sort(v[i].rbegin(), v[i].rend());

        long long sum = 0;
        for (int j = 0; j < (int)v[i].size(); ++j) {
            sum += v[i][j];
            if(v[i][j] >= 0)ac[j] += sum;
        }
    }
    

    for (int i = 0; i < 100010; ++i) {
        if(ac[i]) mx = max(ac[i],mx);
    }
    cout << mx << "\n";
    
    return 0;
}


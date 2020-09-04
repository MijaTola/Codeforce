#include <bits/stdc++.h>

using namespace std;

int n;
long long cnt[25][25];
long long dp[(1 << 20) + 10];
vector<int> v[25];

void build() {
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if(i == j or !v[i].size() or !v[j].size()) continue;
            int pos2 = 0;
            for (int pos1 = 0; pos1 < (int)v[i].size(); ++pos1) {
                while(pos2 < (int)v[j].size() - 1 and v[j][pos2 + 1] < v[i][pos1])
                    pos2++;

                if(v[i][pos1] > v[j][pos2])
                    cnt[i][j] += pos2 + 1;
            }
        }
    }
}   

long long f(int mask) {
    if(mask == (1 << 20) -1) return 0;
    long long &ans = dp[mask];
    if(ans != -1) return ans;
    ans = 1e18;
    for (int i = 0; i < 20; ++i) {
        if(!(mask & (1 << i))) {
            long long sum = 0;
            for (int j = 0; j < 20; ++j) {
                if(i == j) continue;
                if(mask & (1 << j)) 
                    sum += cnt[i][j];
            }
            ans = min(ans, f(mask | (1 << i)) + sum);
        }
    }
    return ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x--;
        v[x].push_back(i);
    }

    build();
    cout << f(0) << "\n";
    
    return 0;
}


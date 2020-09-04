#include <bits/stdc++.h>

using namespace std;

int v[200010];
long long c[200010];
vector<pair<int,long long> > neg;
int main() {
    
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i] < 0) 
            neg.push_back({i, 0});
        else ans++;
    }
       
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if(v[i] > 0) cnt++;
        else cnt = 0;
        c[i] = cnt;
    }
    

    for (int i = neg.size() - 1; i >= 0; i -= 2) {
        neg[i].second += c[neg[i].first + 1];
        if(i + 2 < (int)neg.size())neg[i].second += neg[i + 2].second;
        neg[i].second++;
    }

    for (int i = neg.size() - 2; i >= 0; i -= 2) {
        neg[i].second += c[neg[i].first + 1];
        if(i + 2 < (int)neg.size())neg[i].second += neg[i + 2].second;
        neg[i].second++;
    }


    for (int i = 0; i < n; ++i) {
        if(v[i] > 0)ans += c[i + 1];
        int a = -1, b = neg.size() - 1;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(neg[mid].first >= i) b = mid;
            else a = mid;
        }
        ans += neg[b + 1].second;
    }

    long long total = ((long long)n * (long long)(n + 1) / 2);
    cout << total - ans << " " << ans << "\n";
    return 0;
}


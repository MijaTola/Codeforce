#include <bits/stdc++.h>

using namespace std;

vector<pair<double, int> > a,b;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        if(x > 0) a.push_back({x,i});
        else b.push_back({abs(x),i});
    }

    int ca = 0, cb = 0;
    long long sa = 0, sb = 0;
    for (auto p : a) {
        double x = p.first;
        if(x != (int)x) ca++;
        sa += (int)x;
    }

    for (auto p: b) {
        double x = p.first;
        if(x != (int)x) cb++;
        sb += (int)x;
    }
    vector<pair<int,int> > ans;
    if(sb == sa) {
        for (auto p: a)
            ans.push_back({p.second, (int)p.first});
        for (auto p: b)
            ans.push_back({p.second, -(int)p.first});
    } else {
        int dif = abs(sa - sb);
        if(sa > sb and cb >= dif) {
            for (int i = 0; i < (int)b.size() and dif; ++i) {
                if(b[i].first != (int)b[i].first) {
                    b[i].first = (int) (b[i].first + 1);
                    dif--;
                }
            }
        } else  if(sa < sb and ca >= dif){
            for (int i = 0; i < (int)a.size() and dif; ++i) {
                if(a[i].first != (int)a[i].first) {
                    a[i].first = (int) (a[i].first + 1);
                    dif--;
                }
            }
        }
        for (auto p: a)
            ans.push_back({p.second, (int)p.first});
        for (auto p: b)
            ans.push_back({p.second, -(int)p.first});
    }

    sort(ans.begin(), ans.end());

    for (auto x: ans) 
        cout << x.second << "\n";
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int n;
int st[1000010];
int v[200010];

void update(int pos,int value){
    for (st[pos+=n]= value; pos > 1; pos>>=1)
        st[pos>>1] = min(st[pos], st[pos^1]);
}

// interval[l,r)
int query(int l,int r){
    int ans = INT_MAX;
    r++;
    for (l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) ans = min(ans, st[l++]);
        if(r&1) ans = min(ans, st[--r]);
    }
    return ans;
}

int main() {
    
    for (int i = 0; i < 1000010; ++i)
        st[i] = INT_MAX;

    scanf("%d", &n);
    
    int mn = 1e9;
    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
        update(i, v[i]);
        mn = min(mn,v[i]);
    }

    priority_queue<pair<int,int> > q;

    for (int i = 0; i < n; ++i) {
        int a = i, b = n;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(query(i, mid) == v[i]) a = mid;
            else b = mid;
        }
        int r = a;
        a = -1, b = i;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(query(mid, i) == v[i]) b = mid;
            else a = mid;
        }
        int l = b;
        q.push({(r - l + 1), v[i]});
    }
    
    vector<int> a;
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        while(!q.empty() and q.top().first >= i) {
            ans = max(ans, q.top().second);
            q.pop();
        }
        a.push_back(ans);
    }
    
    reverse(a.begin(), a.end());
    for (int x: a)
        printf("%d ", x);
    puts("");
    return 0;
}


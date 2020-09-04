#include <bits/stdc++.h>

using namespace std;

int n;
long long v[500010];
long long l[500010];
long long r[500010];
long long ml[500010];
long long mr[500010];
long long a[500010];
long long st[1000010];

void update(int pos,int value){
	for (st[pos+=n]= value; pos > 1; pos>>=1)
		st[pos>>1] = min(st[pos], st[pos^1]);
}

// interval[l,r)
long long query(int l,int r){
	long long ans = 1e9;
	r++;
	for (l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) ans = min(ans,st[l++]);
		if(r&1) ans = min(ans,st[--r]);
	}
	return ans;
}

int main() {
    
    for (int i = 0; i < 1000010; ++i)
        st[i] = 1e9;

    cin >> n;

    for (int i = 1; i <= n; ++i)  {
        cin >> v[i];
        update(i, v[i]);
        ml[i] = mr[i] = 1e9;
    }
    ml[0] = mr[n + 1] = 1e9;
    for (int i = 1; i <= n; ++i) {
        if(v[i] >= v[i - 1]) l[i] = l[i - 1] + 1;
        else l[i] = 1;
        a[i] = v[i] + a[i - 1];
        ml[i] = min(ml[i - 1], v[i]);
    }
    
    for (int i = n; i >= 1; i--) {
        if(v[i] >= v[i + 1]) r[i] = r[i + 1] + 1;
        else r[i] = 1;
        mr[i] = min(mr[i + 1], v[i]);
    }

    long long ans = 0;
    long long L = -1, R = -1;
    for (int i = 1; i <= n; ++i) {
        int dl = i - (l[i] - 1);
        int dr = i + (r[i] - 1);
        long long cur = a[dr] - a[dl - 1];
        cout << dl << " " << i << " " << dr << " " << cur << " xd\n";
        cout << query(1, dl) << " " << query(dr,n) << " rmq\n";
        long long l = dl - 1;
        long long r = n - dr;
        cur += l * query(1, dl);
        cur += r * query(dr, n);
        if(cur > ans) {
            ans = cur;
            L = dl;
            R = dr;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if(i < L) cout << query(1, L) << " ";
        else if(i > R) cout << query(R, n) << " ";
        else cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}


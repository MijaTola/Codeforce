#include <bits/stdc++.h>

using namespace std;

int v[200010];
int l[200010];
int r[200010];
int st[1000010];
int n,q;

void update(int pos,int value){
	for (st[pos+=n]= value; pos > 1; pos>>=1)
		st[pos>>1] = min(st[pos],st[pos^1]);
}

int query(int l,int r){
	int ans = 1e9;
	r++;
	for (l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) ans = min(ans,st[l++]);
		if(r&1) ans = min(ans,st[--r]);
	}
	return ans;
}

int main() {
    
    for (int i = 0; i < 200010; ++i)
        l[i] = 1e9, r[i] = - 1;

    for (int i = 0; i < 1000010; ++i)
        st[i] = 1e9;

    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        l[v[i]] = min(l[v[i]], i);
        r[v[i]] = max(r[v[i]], i);
        if(v[i]) update(i, v[i]);
        else update(i, 1e9);
    }
    bool flag = 0;
    for (int i = 1; i <= q; ++i) {
        if(r[i] == -1) continue;
        flag |= (i == q);
        int dl = l[i];
        int dr = r[i];
        if(query(dl, dr) < i) return puts("NO"),0;
    }
    
    if(!flag) {
        flag = 0;
        for (int i = 0; i < n; ++i)
            if(v[i] == 0) {
                v[i] = q;
                flag = 1;
                break;
            }
        if (!flag) return puts("NO"), 0;
    }

    for (int i = 1; i < n; ++i)
        if(v[i] == 0) v[i] = v[i - 1];

    for (int i = n - 1; i >= 0; --i)
        if(!v[i]) v[i] = v[i + 1];

    puts("YES");

    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << "\n";
    return 0;
}

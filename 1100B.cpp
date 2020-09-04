#include <bits/stdc++.h>

using namespace std;

int n,m;
int cnt[100010];
int st[4*100010];

void update(int pos,int value){
	for (st[pos+=n]= value; pos > 1; pos>>=1)
		st[pos>>1] = min(st[pos],st[pos^1]); 
}

// interval[l,r)
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
    ios::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 4*100010; ++i)
        st[i] = 1e9;

    cin >> n >> m;
    
    int mn = 1;

    for (int i = 0; i < n; ++i)
        update(i,0);

    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        cnt[x]++;
        update(x, cnt[x]);
        if(query(0, n) == mn) {
            cout << "1";
            mn++;
        }else cout << "0";
    }
    cout << "\n";
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int n,q;
int st[1000010];
int v[3][100010];

void update(int pos,int value){
	for (st[pos+=n]= value; pos > 1; pos>>=1)
		st[pos>>1] = st[pos] + st[pos^1]; 
}

int query(int l,int r){
	int ans = 0;
	r++;
	for (l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) ans += st[l++];
		if(r&1) ans += st[--r];
	}
	return ans;
}

bool check(int x) {
    if(v[0][x] == 0 and v[0][x - 1] == 0) return 0;
    if(v[1][x] == 0 and v[1][x - 1] == 0) return 0;
    return 1;
}

int main() {

    cin >> n >> q;

    while(q--) {
        int x,y;
        cin >> x >> y;
        x--;
        v[x][y] = 1 - v[x][y];

        update(y, check(y));
        update(y + 1, check(y + 1));
        if(query(1, n)) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}


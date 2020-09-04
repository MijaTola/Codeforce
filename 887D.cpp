#include <bits/stdc++.h>

using namespace std;


const int NEUTRO = 0;
int st[10000010];
int n;
void build(){
	for (int i = n-1;i > 0; --i)
		st[i] = st[i<<1] + st[i<<1|1];
}

void update(int pos,int value){
	for (st[pos+=n]= value; pos > 1; pos>>=1)
		st[pos>>1] = st[pos] + st[pos^1]; 
}
// interval[l,r)
int query(int l,int r){
	int ans = NEUTRO;
	r++;
	for (l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) ans += st[l++];
		if(r&1) ans += st[--r];
	}
	return ans;
}


int main(){
 
    int n,a,b,c,d,s,l;
    cin >> n >> a >> b >> c >> d >> s >> l;


    return 0;
}


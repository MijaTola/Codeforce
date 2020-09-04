#include <bits/stdc++.h>
 
using namespace std;
 
int st[2000100];
int n,m,p;

void update(int pos,int value){
	for (st[pos+=n]= value; pos > 1; pos>>=1)
		st[pos>>1] = st[pos] + st[pos^1]; 
}
// interval[l,r)
int query(int l,int r){
	int ans = 0;
	r++;
	for (l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) ans = __gcd(ans,st[l++]);
		if(r&1) ans = __gcd(ans,st[--r]);
	}
	return ans;
}
vector<int> A,B;
int main(){
    
    scanf("%d %d %d", &n, &m, &p);

    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        A.push_back(x);
    }

    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        B.push_back(x);
    }
    if(n < m) {
        swap(n,m);
        swap(A,B);
    }

    for (int i = 0; i < n; ++i) {
        update(i, A[i]);
    }
        
    int g1 = 0, g2 = 0;
    for (int i = 0; i < m; ++i) {
        g1 = __gcd(g1, A[i]);
        g2 = __gcd(g2, B[i]);
        if((g1 * g2) % p != 0) return printf("%d\n", i), 0;
    }
    int cnt = m;
    for (int i = m; i < n; ++i) {
        g1 = query(i - m, i);
        if((g1 * g2) % p != 0) return printf("%d\n", cnt), 0;
        cnt++;
    }
    
    g1 = 0, g2 = 0;
    cnt = 0;
    for (int i = m - 1, j = n - 1; i >= 0; --i, j--) {
        g1 = __gcd(g1, A[j]);
        g2 = __gcd(g2, B[i]);
        if((g1 * g2) % p != 0) return printf("%d\n", n + m - 2 - cnt + 1), 0;
        cnt--;
    }


   

    return 0;
}

#include <bits/stdc++.h>

using namespace std;


bool prime[10000010];
int cnt[10000010];
vector<int> primes;

void criba(){
    memset(prime,false,sizeof prime);
    for (int i = 2; i*i < 10000010; ++i){
        int c = i + i;
        while(c < 10000010){
            prime[c] = true;
            c += i;
        }
    }
    for (int i = 2;  i < 10000010; ++i)
        if(!prime[i]) primes.push_back(i);
}
void factor(int n){
	int index = 0;
	int pf = primes[0];
	while(pf*pf <= n){
        bool flag = false;
		while(n%pf==0){
            if(!flag){cnt[pf]++; flag = true;}
			n /= pf;
		}
		pf = primes[++index];
	}
	if(n != 1) cnt[n]++;
}
int main(){
    criba();
    int n; scanf("%d",&n);
    for (int i = 0; i < n; ++i){
        int x; scanf("%d",&x);
        factor(x);
    }
    for (int i = 1; i < 10000010; ++i)
        cnt[i] += cnt[i-1];
    int m; scanf("%d",&m);
    while(m--){
        int l,r;
        scanf("%d %d",&l,&r);
        l = min(10000010-1,l);
        r = min(10000010-1,r);
        printf("%d\n",cnt[r] - cnt[l-1]);
    }
    return 0;
}


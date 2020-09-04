#include <bits/stdc++.h>

using namespace std;

vector<int> dv;
vector<pair<int,int> > fact,b;
pair<int,int> ans[110];
const int mod = 998244353;

void factors(int x) {
    for (int i = 0; i < (int)dv.size(); ++i) {
        int c = 0;
        while(x % dv[i] == 0) {
            c++;
            x /= dv[i];
        }
        if(c) fact.push_back(make_pair(dv[i], c));
    }
}

void divisors(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if(x % i == 0){
            dv.push_back(i);
            if(x / i != i) dv.push_back(x / i);
        }
    }
    sort(dv.begin(), dv.end());
    factors(x);
}

int modpow(int x, unsigned int y) { 
    int res = 1;
  
    x = x % mod;  
  
    while (y > 0) { 
        if (y & 1)  res = (res*x) % mod; 
        y = y>>1; 
        x = (x*x) % mod;   
    } 
    return res; 
} 
int main() {
    int k,n,m;
    scanf("%d", &k);

    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        b.push_back(make_pair(x,i));
    }
    
    scanf("%d %d", &n, &m);
    
    divisors(m);
    int rpos = k - k;
    int id = -1;
    for (int i = 0; i < (int)fact.size(); ++i) {
        cout << fact[i].first << " " << fact[i].second << " test\n";
        if(fact[i].second >= b[rpos].first) {
            id = i;
            break;
        }
    }

    if(id == -1) return puts("-1"),0;

    printf("%d\n", modpow(fact[id].first, b[rpos].first));
    return 0;
}


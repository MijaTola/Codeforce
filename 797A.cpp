#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool sieve[100010];
vector<int> primes;
void criba(){
    memset(sieve,false,sizeof sieve);
    for (int i = 2; i*i < 100010; ++i){
        int c = i+i;
        while(c < 100010){
            sieve[c] = 1;
            c += i;
        }
    }
    for (int i = 2; i < 100010; ++i){
        if(!sieve[i]) primes.push_back(i);
    }
}

vector<int> f;
void factor(int n){
    int pos = 0; int pf = primes[pos];

    while(pf*pf <= n){
        while(n%pf == 0){
            f.push_back(pf);
            n/=pf;
        }
        pf = primes[++pos];
    }
    if(n != 1) f.push_back(n);
}

int main(){
    int n,k; cin >> n >> k;
    criba();
    factor(n);
    if((int)f.size() < k) return cout << "-1\n",0;
    if((int)f.size() == 1 and k == 1) return cout << n << "\n",0;
    while((int)f.size() > k){
        int p = f[f.size()-1];
        f.pop_back();
        f[f.size()-1] *= p;
    }
    for (int i = 0; i < (int)f.size(); ++i)
        cout<< f[i] << " ";
    return 0;
}


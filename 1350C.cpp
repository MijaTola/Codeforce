#include <bits/stdc++.h>

using namespace std;

int v[100010];
bool p[200010];
int sz[200010];
multiset<int> s[200010];
vector<int> pr;

void factor(int n){
	int index = 0;
	int pf = pr[0];
	while(pf*pf <= n){
        long long cur = 1;
		while(n%pf==0){
			n /= pf;
            cur *= pf;
		}
        if(cur > 1) {
            s[pf].insert(cur);
            sz[pf]++;
        }
		pf = pr[++index];
	}

    if(n != 1) {
        s[n].insert(n);
        sz[n]++;
    }
    while(s[n].size() > 10) s[n].erase(*s[n].rbegin());
}

int main() {
 

    for (int i = 2; i < 200010; ++i) 
        for (int j = i + i; j < 200010; j += i)
            p[j] = 1;

    for (int i = 2; i < 200010; ++i)
        if(!p[i]) pr.push_back(i);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        factor(x);
    }

    long long ans = 1;

    for (int i = 2; i < 200010; ++i) {
        if(sz[i] < n) s[i].insert(1), sz[i]++;
        if(sz[i] < n) s[i].insert(1);
        s[i].erase(s[i].begin());
        ans *= *s[i].begin();
        s[i].clear();
    }

    cout << ans << "\n";
    return 0;
}


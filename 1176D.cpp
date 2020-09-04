#include <bits/stdc++.h>

using namespace std;

bool is[40000010];
int in[40000010];
int v[200010];
vector<int> p;

int factor(int n){
	int index = 0;
	int pf = p[0];
    bool first = 0;
    int ans = 1;
	while(pf*pf <= n){
		while(n%pf==0){
            if(!first) first = 1;
            else ans *= pf;
			n /= pf;
		}
		pf = p[++index];
    }
    if(n) ans *= n;
    return ans;
}

bool ver(int x) {
    if(!is[x] and x < 40000010 and in[p[x - 1]]) {
        in[x]--;
        in[p[x - 1]]--;
        return 1;
    } else if(is[x]) {
        int last = factor(x);
        if(in[last]) {
            in[x]--;
            in[last]--;
            return 1;
        }
    }
    return 0;
}
int main() {
    for (int i = 2; i * i < 40000010; ++i)
        for (int j = i + i; j < 40000010; j += i)
            is[j] = 1;
    is[0] = is[1] = 1;
    for (int i = 2; i < 40000010; ++i)
        if(!is[i]) p.push_back(i);
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        cin >> v[i];
        in[v[i]]++;
    }
    
    sort(v, v + 2 * n);
    vector<int> ans;
    for (int i = 2 * n - 1; i >= 0; --i) {
        if(!in[v[i]]) continue;
        if(ver(v[i])) ans.push_back(v[i]);
    }
    cout << "\n";
    for (auto x: ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}


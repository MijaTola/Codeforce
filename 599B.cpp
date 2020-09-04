#include <bits/stdc++.h>

using namespace std;

//b[i] = f[a[i]]

int n,m,x;
int f[100010];
int vf[100010];
int b[100010];
int ans[100010];

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        f[x]++;
        vf[x] = i;
    }

    for (int i = 0; i < m; ++i) 
        cin >> b[i];
    
    bool is = 0;
    for (int i = 0; i < m; ++i) {
        if(f[b[i]] == 0) return cout << "Impossible\n",0;
        if(f[b[i]] > 1) is = 1;
        ans[i] = vf[b[i]] + 1;
    }
    if(is) return cout << "Ambiguity\n",0;

    cout << "Possible\n";
    for (int i = 0; i < m; ++i) 
        cout << ans[i] << " ";
    cout << "\n";
    
    
	return 0;
}

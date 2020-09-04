#include <bits/stdc++.h>

using namespace std;

int in[200010];
int out[200010];
int ans[200010];

int main() {
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if(!x) continue;
        in[x]++;
        out[i]++;
        ans[i] = x;
    }
    
    vector<int> no,a,b;

    for (int i = 1; i <= n; ++i) {
        if(!in[i] and !out[i]) no.push_back(i);
        else if(in[i] and !out[i]) b.push_back(i);
        else if(out[i] and !in[i]) a.push_back(i);
    }
    
    for (int i = 0; i < (int)no.size(); ++i) 
        ans[no[i]] = no[(i + 1) % no.size()];
        
    
    bool first = 1;
    for (int x: a) {
        int p = x;
        while(ans[p]) {
            cout << " gg\n";
            p = ans[p];
        }
        if((int)no.size() == 1 and first) {
            ans[p] = no[0];
            ans[no[0]] = x;
            first = 0;
            continue;
        }
        ans[p] = x;
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}


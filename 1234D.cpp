#include <bits/stdc++.h>

using namespace std;

struct stg {
    const int NEUTRO = 0;
    int st[300010];
    int n;

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
};

stg seg[27];

int main() {
     
    string s;
    cin >> s;

    for (int i = 0; i < 27; ++i) 
        seg[i].n = s.size();
    
    for (int i = 0; i < (int)s.size(); ++i) {
        int val = s[i] - 'a';
        seg[val].update(i, 1);
    }

    int q;
    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        if(k == 1) {
            int pos;
            char x;
            cin >> pos >> x;
            pos--;
            char last = s[pos];
            seg[last - 'a'].update(pos, 0);
            seg[x - 'a'].update(pos, 1);
            s[pos] = x;
        } else {
            int l, r;
            cin >> l >> r;
            l--,r--;
            int ans = 0;

            for (int i = 0; i < 27; ++i) {
                ans += (seg[i].query(l,r) != 0);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}


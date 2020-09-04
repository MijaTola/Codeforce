#include <bits/stdc++.h>
using namespace std;

const int NEUTRO = 0;
int st[2000000];
int n;

void update(int pos,int value){
	for (st[pos+=n] += value; pos > 1; pos>>=1)
		st[pos>>1] = st[pos] + st[pos^1]; 
}
// interval[l,r)
int query(int l,int r){
	int ans = NEUTRO;
	r++;
	for (l += n,r += n;l < r;l >>= 1,r >>= 1){
		if(l&1) ans += st[l++];
		if(r&1) ans += st[--r];
	}
	return ans;
}


struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
  
int main() {
    unordered_set<pair<int, int>, bool, hash_pair> um; 
  
   
    ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int m,k;
        cin >> m >> k;
        n = 3 * k;

        for (int i = 0; i < 2 * n; ++i)
            st[i] = 0;
    
        vector<int> v(m);

        for (int &x: v)
            cin >> x;
        

        vector<tuple<int,int,int> > b;
        map<int,int> mp,ans;

        int l = 0, r = m - 1;

        while(l < r) {
            int sum = v[l] + v[r];
            b.push_back({sum,v[l],v[r]});
            mp[sum]++;
            l++,r--;
        }
        if((int)mp.size() == 1) {
            cout << "0\n";
            continue;
        }
        sort(b.begin(), b.end());
        int pos = 0;
        int cnt = 0;
        for (int i = 2; i <= 2 * k; ++i) {
            while(pos < (int)b.size()) {
                int a,x,c;
                tie(a,x,c) = b[pos];
                if(pos < (int)b.size() and a < i) {
                    update(max(x,c), 1);
                    cnt++;
                } else break;
                pos++;
            }
            int a = i;
            if(a <= k) {
                ans[a] += cnt;
            } else {
                int cur = query(a - k, k);
                ans[a] += cur;
                int left = query(1, a - k - 1);
                ans[a] += 2 * left;
            }

        }
        
        for (int i = 0; i < 2 * n; ++i) st[i] = 0;
        pos = b.size() - 1;
        cnt = 0;
        for (int i = 2 * k; i >= 2; i--) {
            while(pos >= 0) {
                int a,x,c;
                tie(a,x,c) = b[pos];
                if(pos >= 0 and i < a) {
                    update(min(x,c), 1);
                    cnt++;
                } else break;
                pos--;
            }
            int a = i;
            if(a > k) {
                ans[a] += cnt;
            } else {
                int cur = query(1, a - 1);
                ans[a] += cur;
                int left = query(a, 2 * k);

                ans[a] += 2 * left;
            }
        }


        int res = 1e9;
        for (auto p: ans) {
            res = min(res, p.second);
        }
        cout << res << "\n";

    }

    return 0;
}

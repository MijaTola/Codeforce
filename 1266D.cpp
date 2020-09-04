#include <bits/stdc++.h>

using namespace std;

long long lend[300010];
long long borrow[300010];

int main() {

    long long n,m;

    cin>>n>>m;

    for(int i = 1; i <= m; i++) {
        long long a,b,c;
        cin>>a>>b>>c;
        lend[a] += c;
        borrow[b] += c;
    }

    vector<pair<long long, long long> > vp;
    for(int i = 1; i <= n; i++) {

        long long d=min(lend[i],borrow[i]);

        lend[i] -= d;
        borrow[i] -= d;

        if(borrow[i]>0)
            vp.push_back(make_pair(borrow[i],i));

    }

    long long k=0;
    
    vector<pair<pair<int,int>, long long> > ans;
    for(int i = 1; i <= n; i++) {
        while(lend[i] > 0) {
            long long d = min(lend[i],vp[k].first);
            lend[i] -= d;
            vp[k].first -= d;
            ans.push_back(make_pair(make_pair(i, vp[k].second), d));
            if(vp[k].first==0)
                k++;
        }

    }

    cout<<ans.size()<<endl;

    for(int i =0; i < (int)ans.size(); i++) 
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;

    return 0;

}

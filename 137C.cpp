#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;

int st[400010];
int n;
void update(int pos, int value){
    for (st[pos+=n] = value; pos > 1; pos>>=1)
        st[pos>>1] = max(st[pos],st[pos^1]);
}

int query(int l, int r){
    int ans = 0;
    r++;
    for (l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) ans = max(ans,st[l++]);
        if(r&1) ans = max(ans,st[--r]);
    }
    return ans;
}
int main(){
    
    scanf("%d",&n);

    for (int i = 0; i < n; ++i){
        int x,y;
        scanf("%d %d",&x,&y);
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());

    for (int i = 0; i < (int)v.size(); ++i)
        update(i,v[i].second);
    int ans = 0;

    for (int i = 0; i < (int)v.size(); ++i){
        if(i <= 0) continue;
        int finish = v[i].second;
        int f = query(0,i-1);
        if(f > finish) ans++;
    }

    printf("%d\n",ans);
    return 0;
}
/*

1          100
  50              150
      120              200
            180             220

*/
//aj ai  bi bj



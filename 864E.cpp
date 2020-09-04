#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<pair<int,int>, pair<int,int> > > v;

bool cmp(const pair<pair<int,int>, pair<int,int> > &a, const pair< pair<int,int>,pair<int,int> > &b){
    if(a.first.second == b.first.second) return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}
int dp[110][5000];
int f(int pos, int time){
    if(pos == n) return 0;
    if(dp[pos][time] != -1) return dp[pos][time];
    int ans =  0;
    ans = max(ans,f(pos + 1, time));
    if(time + v[pos].first.first < v[pos].first.second)
        ans = max(ans,f(pos + 1, time + v[pos].first.first) + v[pos].second.second);
    return dp[pos][time] = ans;
}

vector<int> ans;
void r(int pos, int time){
    if(pos == n) return;
    
    int ans1 = f(pos + 1, time);
    int ans2 = -1;
    if(time + v[pos].first.first < v[pos].first.second) ans2 = f(pos + 1, time + v[pos].first.first) + v[pos].second.second;

    if(ans1 > ans2) r(pos + 1, time);
    else{
        r(pos + 1, time + v[pos].first.first);
        ans.push_back(v[pos].second.first);
    }

}
int main(){
    memset(dp,-1,sizeof dp);
    scanf("%d",&n);

    for (int i = 0; i < n; ++i){
        int t,d,p;
        scanf("%d %d %d",&t,&d,&p);
        v.push_back(make_pair(make_pair(t,d),make_pair(i,p)));
    }

    sort(v.begin(),v.end(),cmp);

    printf("%d\n",f(0,0));
    r(0,0);
    reverse(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i)
        printf("%d ",ans[i] + 1);
    puts("");
    return 0;
}


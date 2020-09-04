#include <bits/stdc++.h>

using namespace std;

int v[300010];
vector<int> G[300010];

int main(){
    int n;
    scanf("%d",&n);
    int mx = INT_MIN;
    int mini = INT_MAX;
    for (int i = 1; i <= n; ++i){
        scanf("%d",&v[i]);
        mx = max(mx,v[i]);
    }
    
    int maxi = 0;
    int mxi = 0;
    for (int i = 1; i <= n; ++i){
        if(v[i] == mx) maxi++;
        else if(v[i] == mx - 1) mxi++;
    }

    for (int i = 0; i < n-1; ++i){
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    int ans = mx + 2;
    for (int i = 1; i <= n; ++i){
        if(v[i] == mx) maxi--;
        else if(v[i] == mx - 1) mxi--;
        
        for (int j = 0; j < (int)G[i].size(); ++j){
            int cur = G[i][j];
            if(v[cur] == mx) maxi--, mxi++;
            else if(v[cur] == mx - 1) mxi--;
        }
        if(!maxi){
            ans = mx + 1;
            if(!mxi){ ans = mx; break;}
        }

        if(v[i] == mx) maxi++;
        else if(v[i] == mx - 1) mxi++;
        
        for (int j = 0; j < (int)G[i].size(); ++j){
            int cur = G[i][j];
            if(v[cur] == mx) maxi++, mxi--;
            else if(v[cur] == mx - 1) mxi++;
        }
    }

    printf("%d\n",ans);
    
    return 0;
}


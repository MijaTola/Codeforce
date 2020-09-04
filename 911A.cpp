#include <bits/stdc++.h>

using namespace std;

int v[100010];
vector<int> b;
int main(){
    int n;
    scanf("%d", &n);
    int mn = INT_MAX; 
    for (int i = 0; i < n; ++i) {
        scanf("%d",v + i);
        mn = min(mn,v[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        if(mn == v[i]) b.push_back(i);
    }
    
    int ans = 1e9;
    for (int i = 1; i < (int)b.size(); ++i){
        ans = min(ans,abs(b[i] - b[i - 1]));
    }
    printf("%d\n",ans);
    return 0;
}


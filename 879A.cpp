#include <bits/stdc++.h>

using namespace std;

int s[1010], d[1010];
vector<pair<int,int> > v;
int main(){
    int n;
    scanf("%d", &n);   

    for (int i = 0; i < n; ++i)
        scanf("%d %d", s + i, d + i);
    
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= 10000; ++j)
            v.push_back({s[i] + d[i] * j, i});

    sort(v.begin(),v.end());
    int cur = 0;
    int day = -1;
    for (int i = 0; i < (int)v.size(); ++i){
        if(v[i].second == cur and v[i].first > day){
            cur++;
            day = v[i].first;
        }
        if(cur == n) break;
    }
    printf("%d\n",day);
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[100010];
int b[100010];
int mn[100010];
int mn2[100010];

vector<int> l[100010], r[100010];
vector<pair<int,int> > p;

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
        mn[i] = mn2[i] = 1e9;
    }
    
    for (int i = 0; i < m; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--,y--;
        l[y].push_back(x);
        r[x].push_back(y);
        p.push_back(make_pair(x,y));
    }
    
    if(n == 1) return puts("0\n0"),0;
    for (int i = 0; i < n; ++i) {
        for (int x: l[i]) {
            for (int j = x; j <= i; ++j) {
                b[j]--;
                mn[i] = min(mn[i], v[j] + b[j]);
            }
        }
    }
    
    memset(b, 0, sizeof b);

    for (int i = n - 1; i >= 0; i--) {
        for (int x: r[i]) {
            for (int j = i; j <= x; ++j) {
                b[j]--;
                mn2[i] = min(mn2[i], v[j] + b[j]);
            }
        }
    }
    
    for (int i = 1; i < n; ++i)
        mn[i] = min(mn[i], mn[i - 1]);

    for (int i = n - 2; i >= 0; i--)
        mn2[i] = min(mn2[i], mn2[i + 1]);

    int ans = -1e9;
    int id = -1;
    int a1 = v[n - 1] - mn[n - 2];
    int a2 = v[0] - mn2[1];

    if(a1 > a2 and mn[n - 1] != 1e9) {
        ans = v[n - 1] - mn[n - 2];
        id = n - 1;
    } else if (mn2[1] != 1e9){
        ans = a2;
        id = 0;
    }

    for (int i = 1; i < n - 2; i++) {
        int curmn = min(mn[i - 1], mn2[i + 1]);
        if(curmn == 1e9) continue;
        //cout << i << " " << mn[i - 1] << " " << mn[i + 1] << "test\n";
        //cout << v[i] <<" " << curmn << " by case\n";
        int val = v[i] - curmn;
        if(val > ans) {
            ans = val;
            id = i;
        }
    }

    int MX = -1e9;
    int MN = 1e9;
    for (int i = 0; i < n; ++i) {
        MX = max(MX,v[i]);
        MN = min(MN,v[i]);
    }
    
    int ans2 = MX - MN;
    if(ans2 > ans) {
        printf("%d\n0\n", ans2);
        return 0;
    }
    vector<int> as;
    for (int i = 0; i < m; ++i) {
        int x = p[i].first;
        int y = p[i].second;
        if(!(x <= id and id <= y)) 
            as.push_back(i);
    }
    printf("%d\n%d\n",ans, (int)as.size());
    for (int x: as)
        printf("%d ", x + 1);
    puts("");
    return 0;
}


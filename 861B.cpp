#include <bits/stdc++.h>

using namespace std;

pair<int,int> v[110];
set<int> s;
int main(){

    for (int i = 0; i < 110; ++i){
        v[i].first = 1e9;
        v[i].second = 0;
    }
    int n,m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i){
        int x,y;
        scanf("%d %d", &x, &y);
        v[y].first = min(v[y].first,x);
        v[y].second = max(v[y].second,x);
    }

    int val = 0;
    int id = 0;
    for (int i = 1; i <= 100; ++i){
        int f1 = i;
        int f2 = 1;
        bool flag = 1;
        int cur = 0;
        for (int j = 1; j <= 100; ++j){
            if(v[j].first == 1e9 and v[j].second == 0){
                if(f2 <= n and n <= f1) cur = j;
                f2 = f1 + 1;
                f1 += i;
                continue;
            }
            int mn = v[j].first;
            int mx = v[j].second;
            if(f2 <= mn and mx <= f1){
                if(f2 <= n and n <= f1) cur = j;
                f2 += i;
                f1 += i;
                continue;
            }
            flag = 0;
            break;
        }
        val += flag;
        if(flag){
            id = cur;
            s.insert(id);
        }
    }
    if(s.size() == 1){
        printf("%d\n",id);
        return 0;
    }
    puts("-1");
    return 0;
}


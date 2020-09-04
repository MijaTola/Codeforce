#include <bits/stdc++.h>

using namespace std;

pair<int,int> v[110];
int cur[110];
int main(){
    int n,w;
    scanf("%d %d",&n,&w);

    for (int i = 0; i < n; ++i){
        scanf("%d",&v[i].first);
        v[i].second = i;
    }
    sort(v,v+n); reverse(v,v+n);

    for (int i = 0; i < n; ++i){
        w -= (v[i].first + 1) / 2;
        if(w < 0) return puts("-1"),0;
        cur[i] = (v[i].first + 1) / 2;
    }
    
    for (int i = 0; i < n-1; ++i){
        if(cur[i] < cur[i+1]){
            int dif = cur[i+1] - cur[i];
            if(cur[i] == cur[i+1]) dif++;
            if(w >= dif){
                cur[i] += dif;
                w -= dif;
            }
            else if(cur[i+1] >= dif){
                cur[i+1] -= dif;
                cur[i] += dif;
            }else return puts("-1");
        }
    }
    for (int i = 0; i < n; ++i){
        if(w){
            int dif = v[i].first - cur[i];
            if(w >= dif){
                cur[i] += dif;
                w -= dif;
            }else if(dif >= w){
                cur[i] += w;
                w = 0;
            }
        }else break;
    }

    for (int i = 0; i < n; ++i)
        v[v[i].second].first = cur[i];
    for (int i = 0; i < n; ++i)
        printf("%d ",v[i].first);
    
    puts("");
    return 0;
}


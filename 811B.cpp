#include <bits/stdc++.h>

using namespace std;

int v[10010];
int b[10010];
int main(){
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    

    while(m--){
        int x,y,c;
        cin >> x >> y >> c;
        x--,y--,c--;
        int cur = 0;
        for (int i = x; i <= y; ++i)
            if(v[i] < v[c]) cur++;
        if(x + cur == c) puts("Yes");
        else puts("No");
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main(){
    int l,r,x,y; double k;
    cin >> l >> r >> x >> y;
    cin >> k;
    for (int i = x; i <= y; ++i){
        long long t = i * k;
        if(l <= t and t <= r) return puts("YES"),0;
    }
    puts("NO");
    return 0;
}


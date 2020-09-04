#include <bits/stdc++.h>

using namespace std;

int t,n,x;

int main(){

    scanf("%d", &t);
    while(t--) {
        map<int,int> mp;

        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            mp[x]++;
        }

        int last = -1;
        for (auto p: mp) {
            if (p.second >= 4) {
                printf("%d %d %d %d\n", p.first, p.first , p.first, p.first);
                break;
            }

            if (mp[last] >= 2 and p.second >= 2) {
                printf("%d %d %d %d\n", last, last, p.first, p.first);
                break;
            }

            last = p.first;
        }


    }
    return 0;
}


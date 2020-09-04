#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<int,int> mp;
    set<int> s;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        mp[x]++;
    }
    if(mp.size() == 2){
        for (pair<int,int> x: mp){
            s.insert(x.second);
        }
        if(s.size() == 1){
            puts("YES");
            for (pair<int,int> t: mp)
                cout << t.first << " ";
        }
        else puts("NO");
    }else puts("NO");
    return 0;
}


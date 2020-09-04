#include <bits/stdc++.h>

using namespace std;

int v[100010];
vector<int> t;
priority_queue<pair<int,int> > q;
int main(){
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v[x]++;
    }
    
    int a = 0, b = 0;
    int mx = 0;
    for (int i = 0; i < 100010; ++i) {
        if(v[i]) {
            if(v[i] % 2 == 0) a++;
            else b++;
            mx = max(mx,i);
        }
    }
    
    if(v[mx] & 1) puts("Conan");
    else {
        if(b) puts("Conan");
        else puts("Agasa");
    }
    return 0;
}


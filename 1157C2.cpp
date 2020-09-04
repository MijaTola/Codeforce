#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
int c[200010];
int dc[200010];
bool vis[200010];

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int cnt = 0;
    int last = 1e9;
    for (int i = 0; i < n; ++i) {
        if(v[i] < last) cnt++;
        else cnt = 1;
        dc[i] = cnt;
        last = v[i];
    }
    cnt = 0;
    last = -1;
    for (int i = n - 1; i >= 0; i--) {
        if(v[i] < last) cnt++;
        else cnt = 1;
        c[i] = cnt;
        last = v[i];
    }

    
    int a = 0;
    int b = n - 1;
    vector<char>  ans;
    last= 0;
    while(a < b) {
        if(v[a] < v[b]) {
            if(v[a] <= last) {
                if(v[b] <= last) break;
                goto b1;
            }
            a1:
            vis[a] = 1;
            last = v[a++];
            ans.push_back('L');
        } else if(v[b] < v[a]){
            if(v[b] <= last) {
                if(v[a] <= last) break;
                goto a1;
            }
            b1:
            vis[b] = 1;
            last = v[b--];
            ans.push_back('R');
        } else if(v[b] == v[a]) {
            if(v[b] <= last) break;
            if(dc[b] > c[a]) goto b1;
            else goto a1;
        }
    }
    if(!vis[a] and a == b) {
        if(v[a] > last) ans.push_back('L');

    }
    cout << ans.size() << "\n";
    for (char x: ans)
        cout << x ;
    cout << "\n";
    return 0;
}


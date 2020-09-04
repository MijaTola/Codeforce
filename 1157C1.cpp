#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
bool vis[200010];
int main() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int a = 0;
    int b = n - 1;
    vector<char>  ans;
    int last= 0;
    while(a < b) {
        if(v[a] < v[b]) {
            if(v[a] < last) {
                if(v[b] < last) break;
                goto b1;
            }
            a1:
            vis[a] = 1;
            last = v[a++];
            ans.push_back('L');
        } else {
            if(v[b] < last) {
                if(v[a] < last) break;
                goto a1;
            }
            b1:
            vis[b] = 1;
            last = v[b--];
            ans.push_back('R');
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


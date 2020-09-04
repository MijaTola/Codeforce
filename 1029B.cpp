#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int ans = 1;
    int c = 0;
    for (int i = 1; i < n; ++i) {
        if(v[i - 1] * 2 >= v[i]) ans++;
        else {
            c = max(c,ans);
            ans = 1;   
        }
    }
    c = max(ans,c);
    cout << c << "\n";
    return 0;
}


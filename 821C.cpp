#include <bits/stdc++.h>

using namespace std;

int v[300010];
int main(){
       
    int n;
    cin >> n;
    int cur = 1;
    int pos = 0;
    int ans = 0;
    for (int i = 0; i < 2*n; ++i){
        string c; int x;
        cin >> c;
        if(c == "add"){ 
            cin >> x;
            v[pos] = x; 
            pos++;
        }else{
            if(v[pos-1] == cur or pos == 0) pos = max(0, pos - 1);
            else{
                ans++;
                pos = 0;
            }
            cur++;
        }
    }
    cout << ans << "\n";
    return 0;
}


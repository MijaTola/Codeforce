#include <bits/stdc++.h>

using namespace std;


int main(){
    int q;
    cin >> q;
    while(q--) {
        long long x,y,k;
        cin >> x >> y >> k;
        
        x = abs(x), y = abs(y);

        int mn = min(x,y);

        int cnt = mn;
        x -= mn;
        y -= mn;

        cnt += x + y;

        if(cnt > k) {
            cout <<"-1\n";
            continue;
        }
        
        int left = k - cnt;

        cout << left << "wtf\n";
        cout << mn + left << "\n";
    }
    return 0;
}


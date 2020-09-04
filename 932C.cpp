#include <bits/stdc++.h>

using namespace std;

int ans[1000100];
int main(){
    
    int n,a,b;
    cin >> n >> a >> b;
    
    int da = n / a;
    int db = n / b;
    
    int ca = -1;
    int cb = -1;
    for (int i = 0; i <= da; ++i) {
        int cur = i * a;
        int rest = n - cur;
        if(rest % b == 0) {
            ca = i;
            cb = rest / b;
            goto answer;
        }
    }
    
    for (int i = 0; i <= db; ++i) {
        int cur = i * b;
        int rest = n - cur;
        if(rest % a == 0) {
            ca = i;
            cb = rest / b;
            goto answer;
        }
    }

    return cout << "-1\n",0;
    
    answer:
    int pos = 1;
    while(ca--) {
        for (int i = pos; i < pos + a - 1; ++i) {
            cout << i + 1 << " ";
            ans[i] = i + 1;
        }
        cout << pos << " ";
        ans[pos + a] = pos;
        pos += a;
    }

    while(cb--) {
        for (int i = pos; i < pos + b - 1; i++) {
            cout << i + 1 << " ";
            ans[i] = i + 1;
        }
        cout << pos << " ";
        ans[pos + ca - 1] = pos;
        pos += b;
    }
    cout << "\n";

    return 0;
}


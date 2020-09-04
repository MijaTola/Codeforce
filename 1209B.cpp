#include <bits/stdc++.h>

using namespace std;

int a[110];
int b[110];
string x;
int n;
int v[1100][11000];
int main() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];

    
    for (int i = 0; i < n; ++i) {
        bool flag = (x[i] == '1');
        int j;
        for (j = 0; j < b[i]; ++j)
            v[i][j] = flag;

        flag = !flag;
        int cnt = 0;
        while(j < 11000) {
            v[i][j] = flag;
            cnt++;
            j++;
            if(cnt == a[i]) {
                flag = !flag;
                cnt = 0;
            }
        }
    }


   
    int ans = 0;
    for (int i = 0; i < 11000; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            cur += v[j][i];
        }
        ans = max(ans,cur);
    }
    cout << ans << "\n";
    return 0;
}


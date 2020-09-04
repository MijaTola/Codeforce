#include <bits/stdc++.h>

using namespace std;

int n;
long long a[1010];
long long c[1010];
long long x[1010];
vector<int> ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 1; i <= n; ++i) 
        cin >> a[i];


    for (int i = 1; i <= 3; ++i) {
        x[i - 1] = a[i] - a[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            x[j - 1] = a[j] - a[j - 1];       
        }

        for (int j = 0; j <= n; ++j) {
            c[j + 1] = x[j % i] + c[j];   
        }
        bool flag = 1;
        for (int j = 0; j <= n; ++j) {
            flag &= c[j] == a[j];
        }
        if(flag) ans.push_back(i);
    }
    cout << ans.size() << "\n";
    for (int p: ans)
        cout << p << " ";
    cout << "\n";
    return 0;
}


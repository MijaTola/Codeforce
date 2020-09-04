#include <bits/stdc++.h>

using namespace std;

vector<int> v[110],a,b;
char ans[110];
int main () {
    int n; 
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ans[i] = 'X';
        v[x].push_back(i);
    }
    vector<int> one;
    for (int i = 1; i <= 100; ++i) 
        if(v[i].size() == 1) one.push_back(v[i][0]);

    for (int i = 0; i < (int)one.size(); ++i) 
        if(i & 1) b.push_back(one[i]);
        else a.push_back(one[i]);

    if((int)one.size() % 2 == 0) {
        for (int i = 0; i <= 100; ++i) {
            if(v[i].size() != 1) {
                for (int x: v[i])
                    a.push_back(x);
            }
        }
    } else {
        bool flag = 0;
        int id = 0;
        for (int i = 1; i <= 100; ++i) {
            if(v[i].size() > 2) {
                id = 0;
                flag = 1;
                b.push_back(v[i][0]);
                for (int j = 1; j < (int)v[i].size(); ++j) 
                    a.push_back(v[i][j]);
                break;
            }
        }

        if(!flag) {
            cout << "NO\n";
            return 0;
        }
        for (int i = 0; i <= 100; ++i) {
            if(i != id) {
                for (int x: v[i])
                    a.push_back(x);
            }
        }
    }
    cout << "YES\n";
    for (int x: a) ans[x] = 'A';
    for (int x: b) ans[x] = 'B';
    
    for (int i = 0; i < n; ++i)
        cout << ans[i];
    cout << "\n";
    return 0;
}

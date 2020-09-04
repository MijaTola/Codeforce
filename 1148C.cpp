#include <bits/stdc++.h>

using namespace std;

int n,m;
int p[300010];
int v[300010];
vector<pair<int,int> > ans;

void sw(int i, int j) {
    int vali = v[i];
    int valj = v[j];
    p[vali] = j;
    p[valj] = i;
    swap(v[i], v[j]);
    ans.push_back({i,j});
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        p[v[i]] = i;
    }
    m = n / 2;
    for (int i = 1, j = n / 2 + 1; i <= n / 2; ++i, ++j) {
        int p1 = p[i];
        if(abs(p1 - i) < m and p1 != i) {
            if(abs(1 - p1) >= m) {
                sw(1, p1);
                if(abs(1 - i) >= m) {
                    sw(1, i);
                    sw(1, p1);
                } else {
                    sw(1, n);
                    sw(n, i);
                    sw(1, n);
                }
            } else {
                sw(n, p1);
                if(abs(n - i) >= m) {
                    sw(n, i);
                    sw(n, p1);
                } else {
                    sw(n, 1);
                    sw(1, i);
                    sw(n, 1);
                }
            }

        } else {
            if(p1 != i) sw(p1, i);
        }

        
        int p2 = p[j];
        if(abs(p2 - j) < m and p2 != j) {
            if(abs(1 - p2) >= m ) {
                sw(1, p2);
                if(abs(1 - j) >= m) {
                    sw(1, j);
                    sw(1, p2);
                } else {
                    sw(1, n);
                    sw(n, j);
                    sw(1, n);
                }

            } else {
                sw(n, p2);
                if(abs(n - j) >= m) {
                    sw(n, j);
                    sw(n, p2);
                } else {
                    sw(1, n);
                    sw(1, j);
                    sw(1, n);
                }
            }
        } else {
            if(p2 != j) {
                sw(p2, j);
            }
        }
       

    }
    
    cout << ans.size() << "\n";
    for (auto p: ans)
        cout << p.first << " " << p.second << "\n";
    return 0;
}




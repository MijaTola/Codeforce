#include <bits/stdc++.h>

using namespace std;

int c[110][110];

int get(vector<int> A, int n)  { 
    int cost = 0; 
    sort(A.begin(), A.end());
    int K = A[n / 2]; 
    for (int i = 0; i < n; ++i) 
        cost += abs(A[i] - K); 
    if (n % 2 == 0) { 
        int tempCost = 0; 
        K = A[(n / 2) - 1]; 
        for (int i = 0; i < n; ++i) 
            tempCost += abs(A[i] - K); 
        cost = min(cost, tempCost); 
    } 
    return cost; 
} 

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        
        int n,m;
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> c[i][j];

        long long ans = 0;
        for (int i = 0; i < (n + 1) / 2; ++i) {
            for (int j = 0; j < (m + 1) / 2; ++j) {
                
                set<pair<int,int> > s;
                s.insert({i,j});
                s.insert({i, m - j - 1});
                s.insert({n - i - 1, j});
                s.insert({n - i - 1, m - j - 1});

                vector<int> v;
                for (auto p: s) {
                    int x = p.first;
                    int y = p.second;
                    v.push_back(c[x][y]);
                }
                
              
                ans += get(v, v.size());
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int n;
char c[110][110];

int main() {
        
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) 
        scanf("%s", c[i]);
    
    vector<pair<int,int> > ans, ans2;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(c[i][j] == '.') {
                ans.emplace_back(i + 1, j + 1);   
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(c[j][i] == '.') {
                ans2.emplace_back(j + 1, i + 1);
                break;
            }
        }
    }
    
    auto print = [] (auto &ans) {
        for (auto p: ans) 
            printf("%d %d\n", p.first, p.second);
    };

    if((int)ans.size() == n) return print(ans), 0;
    if((int)ans2.size() == n) return print(ans2), 0;
    puts("-1");
    
    return 0;
}


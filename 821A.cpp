#include <bits/stdc++.h>

using namespace std;

int m[55][55];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> m[i][j];

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if(m[i][j] == 1) continue;
            bool sw = false;
            for (int k = 0; k < n; ++k){
                for (int l = 0; l < n; ++l){
                    if(k == i) continue;
                    if(j == l) continue;
                    if(m[i][j] == m[i][l] + m[k][j])
                        sw = true;
                }
            }
            if(!sw) return puts("No"),0;
        }
    }
    puts("Yes");
    return 0;
}


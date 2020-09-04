#include <bits/stdc++.h>

using namespace std;

int n;
int mx[3];
string v[3];
int c[3][256];
string sans[] = {"Kuro", "Shiro", "Katie", "Draw"};

int main() {

    cin >> n;

    for (int i = 0; i < 3; ++i)
        cin >> v[i];
    
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < (int)v[0].size(); ++j) 
            c[i][(int)v[i][j]]++;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 256; ++j) 
            mx[i] = max(mx[i], c[i][j]);
        
    
    for (int i = 0; i < 3; ++i) 
        mx[i] = min((int)v[0].size(), mx[i] + n);
    
    
    int id = 3, ans = 0, cnt = 0;

    for (int i = 0; i < 3; ++i) {
        if(mx[i] > ans) {
            ans = mx[i];
            id = i;
        } 
    }


    for (int i = 0; i < 3; ++i)
        if(mx[i] == ans) cnt++;

    if(cnt != 1) id = 3;

    cout << sans[id] << "\n";
    return 0;
}


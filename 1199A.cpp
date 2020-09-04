#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main() {
    
    int n,x,y;
    cin >> n >> x >> y;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    for (int i = 0; i < n; ++i) {
        bool flag = 1;
        for (int j = i - 1; j >= max(i - x, 0); --j) 
            flag &= v[j] > v[i];
        for (int j = i + 1; j <= min(i + y, n - 1); ++j) 
            flag &= v[j] > v[i];

        if(flag) return cout << i + 1 << "\n",0;
        
    }
    return 0;
}


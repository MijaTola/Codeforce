#include <bits/stdc++.h>

using namespace std;

int v[110];
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    int mid = (n + 1) / 2;
    for (int i = -1000; i <= 1000; ++i) {
        int c = 0;
        if(i == 0) continue;
        for (int j = 0; j < n; ++j) {
            if((double)(v[j]) / (double)i > 0) c++;
        }
        if(c >= mid) return cout << i << "\n",0;
    }
    cout << "0\n";
    return 0;
}


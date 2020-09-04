#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010][3];
int a[100010];

//1 2 3 4 5 6

int main() {


    cin >> n;

    for (int i = 0; i < n - 2; ++i) 
        for (int j = 0; j < 3; ++j) {
            cin >> v[i][j];
            a[v[i][j]]++;
        }

        
    auto find = [] () {
        for (int i = 1; i <= n; ++i)
            if(a[i] == 1) return i;
        return -1;
    };

    int x = find();
    cout << x << "\n";
    return 0;
}


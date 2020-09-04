#include <bits/stdc++.h>

using namespace std;

int a[100010];
int v[100010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    sort(v, v + n);
    
    int cur = v[0];
    
    for (int i = 0; i < n; ++i) {
        if(cur == v[i]) a[i] = cur;
        else if(cur + 1 == v[i]) a[i] = ++cur;
        else return cout << "Impossible\n",0;
    }

    cout << "Possible\n";
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
    
    return 0;
}


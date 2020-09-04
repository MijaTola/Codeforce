#include <bits/stdc++.h>

using namespace std;

int n;
int pr[100010];

int main() {
    int p = 1;
    for (int i = 2; i * i < 100010; ++i, p++) {
        if(pr[i] != 0) {p--; continue;}
        for (int j = i; j < 100010; j += i) 
            if(!pr[j]) pr[j] = p;           
    }
    for (int i = 2; i < 100010; ++i)
        if(!pr[i]) pr[i] = p++;
    int n; cin >> n;
    for (int i = 2; i <= n; ++i) 
        cout << pr[i] << " ";
      
    
    cout << "\n";
    return 0;
}


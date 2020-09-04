#include <bits/stdc++.h>

using namespace std;

int a[30];
int main(){
    
    int n,k;
    cin >> n >> k;
    string s; 
    cin >> s;
    
    for (int i = 0; i < (int)s.size(); ++i)
        a[s[i] - 'A']++;
    
    
    int mn = 1e9; 
    int c = 0;
    for (int i = 0; i < 30; ++i) {
        if(a[i]) {
            mn = min(a[i],mn);
            c++;
        }

    }
    
    if(c >= k) c = k;
    else c= 0;

    cout << mn * c<< "\n";
    return 0;
}


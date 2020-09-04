#include <bits/stdc++.h>

using namespace std;

int v[510];
int main(){
    int n;
    long long k;
    cin >> n >> k;
    
    int mx = 0;
    int id = -1;
    for (int i = 0; i < n; ++i){
        cin >> v[i];
        if(v[i] > mx){
            mx = v[i];
            id = i;
        }
    }
    
    if(k > n) return cout << mx << "\n",0;

    for (int i = 0; i < n; ++i){
        int c = 0;
        for (int j = i + 1; j < n; ++j){
            if(v[i] > v[j]) c++;
            else break;
        }
        
        if(i > 0 and v[i] > v[i - 1])c++;
        if(c >= k) return cout << v[i] << "\n",0;
    }
    cout << mx << "\n";
    return 0;
}


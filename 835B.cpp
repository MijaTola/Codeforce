#include <bits/stdc++.h>

using namespace std;

int k;
string n;
int main(){
    cin >> k >> n;
    
    sort(n.begin(),n.end());
    int cur = 0;
    for (int i = 0; i < (int)n.size(); ++i){
        cur += (n[i] - '0');   
    }
    
    int ans = 0;
    for (int i = 0; i < (int)n.size() and cur < k; ++i){
        cur += 9;
        cur -= (n[i] - '0');
        ans++;
    }
    

    cout << ans << "\n";
    return 0;
}


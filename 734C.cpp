#include <bits/stdc++.h>
 
using namespace std;
 
int n,s;
long long x;
int m,k;
 
struct spell{
    int cost,mana;
    spell(){}
    spell(int c,int mn){
        cost = c, mana = mn;
    }
};
 
spell A[200010];
spell B[200010];
 
int main(){
    cin >> n >> m >> k >> x >> s;

    for (int i = 1; i <= m; ++i) 
        cin >> A[i].cost;
    for (int i = 1; i <= m; ++i) 
        cin >> A[i].mana;
    for (int i = 1; i <= k; ++i) 
        cin >> B[i].cost;
    for (int i = 1; i <= k; ++i) 
        cin >> B[i].mana;

    A[0] = spell(x,0);
    B[0].cost = 0;
    B[0].mana = 0;
    m++,k++;
    long long ans = LLONG_MAX;   
    for (int i = 0; i < m; ++i){
        if(A[i].mana <= s){
            int a = -1; int b = k;
            int r = s-A[i].mana;
            while(b-a > 1){
                int mid = (a+b)>>1;
                if(B[mid].mana > r) b = mid;
                else a = mid;
            }
            b--;
            
            long long tm = max((long long)n-B[a].cost,0LL);
            ans = min(ans,(long long) tm*A[i].cost);
        }
    }
    cout << ans << "\n";
    
    return 0;
}



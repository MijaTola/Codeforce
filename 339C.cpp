#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string x;
int m,dp[1010][11][20];
int f(int pos, int last, int sum){
    if(pos == m) return 1;
    if(dp[pos][last][sum] != -1) return dp[pos][last][sum];
    int flag = 0;
    for (int i = 0; i < 10; ++i){
        if(x[i] == '1' and i+1 != last and i+1 > sum)
            flag |= f(pos+1,i+1,i-sum+1);
    }
    return dp[pos][last][sum] = flag;
}
void r(int pos, int last, int sum){
    if(pos == m) return;
    for (int i = 0; i < 10; ++i){
        if(x[i] == '1' and i+1 != last  and i+1> sum){
            if(dp[pos+1][i+1][i-sum+1]){
                cout << i+1 << " ";
                r(pos+1,i+1,i-sum+1);
                break;
            }
        }
    }
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> x >> m;
    if(!f(0,0,0)) return cout << "NO\n",0;
    else{ cout << "YES\n";r(0,0,0);}
    return 0;
}

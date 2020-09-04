#include <bits/stdc++.h>

using namespace std;

int m[2][300010];
int main(){
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
        cin >> m[0][i];

    for (int i = 0; i < n; ++i)
        cin >> m[1][i];


    long long ans1 = 0;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        ans1 += c * m[0][i];
        c++;
    }
    
    for (int i = n - 1; i >= 0; --i) {
        ans1 += c * m[1][i];
        c++;
    }

    long long ans2 = 0;
    c = 1;
    for (int i = 0; i < n; ++i) 
        ans2 += c * m[1][i];

    for (int i = n - 1; i >= 1; --i)
        ans2 += c * m[0][i];

    long long ans3 = 0;
    c = 0;
    for (int i = 0; i < n; ++i) {
        if(i & 1) {
            ans3 += c * m[1][i];
            c++;
            ans3 += c * m[0][i];
            c++;
        
        } else {
            ans3 += c * m[0][i];
            c++;
            ans3 += c * m[1][i];
            c++;
            
        }
    }
    cout << max(ans1,max(ans2,ans3)) << "\n";
    return 0;
}


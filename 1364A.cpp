#include <bits/stdc++.h> 

using namespace std; 

int mod[100010];
int v[100010];

int main()  { 

    int t;
    cin >> t;
    while(t--) {
        memset(mod, -1, sizeof mod);
        int n, k;
        cin >> n >> k;

        for (int i = 0; i < n; ++i)
            cin >> v[i];
        
        int ans = -1; 
        int sum = 0; 
        int id = -1;

        for (int i = 0; i < n; i++) { 
            sum += v[i]; 
            if(sum % k == 0) {
                if(id != -1)
                    ans = max(ans, i - id);

            } else {
                if(id == -1) id = i;
                ans = max(ans, i + 1);
            }
        }	 

        cout << ans << "\n";


       
    }

    return 0;	 
} 


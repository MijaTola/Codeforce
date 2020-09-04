#include <bits/stdc++.h>

using namespace std;

int main(){
    string x; cin >> x;
    
    for (int i = 0; i < (int)x.size(); ++i){
        int a = x[i]-'0';
        if(a%8 == 0) return cout << "YES\n" << a,0;
        for (int j = i+1; j < (int)x.size(); ++j){
            int b = x[j]-'0';
            if((a*10+b)%8 == 0) return cout << "YES\n" <<a<< b,0;
            for (int k = j+1; k < (int)x.size(); ++k){
                int c = x[k]-'0';
                if((a*100+b*10+c)%8==0)
                    return cout << "YES\n" << a<<b<< c,0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}


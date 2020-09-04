#include <bits/stdc++.h>

using namespace std;

int da[1000100];
int db[1000100];
int main(){
    
    int n; cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> da[i];
    for (int i = 0; i < n; ++i)
        cin >> db[i];

    sort(da, da + n);
    sort(db, db + n);
    
    int a = n - 1, b = n - 1;
    
    long long ca = 0, cb = 0;
    bool flag = 1;
    while(a >= 0 or b >= 0) {
        //cout << a << " " << b << " lala\n";
        if(flag) {
            //cout << " AAAAAA\n";
            if(a >= 0 and b >= 0) {
                //cout << da[a] << " " << db[b] << " a\n";
                if(da[a] > db[b]) 
                    ca += da[a--];
                else b--;
            } else {
                if(a >= 0) ca += da[a--];
                else b--;
            }
        } else {
            //cout << " BBBBBB\n";
            if(a >= 0 and b >= 0) {
                //cout << da[a] << " " << db[b] << " b\n";
                if(db[b] > da[a])
                    cb += db[b--];
                else a--;
            } else {
                //cout << " come here\n";
                if(b >= 0) cb += db[b--];
                else a--;
                
            }
        }
        //cout << ca << " " << cb << " test\n";
        flag = !flag;
    }
    cout << ca - cb << "\n";
    return 0;
}


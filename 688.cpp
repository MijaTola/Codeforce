#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    bool flag = false;
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x%k == k%x) flag=  true;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

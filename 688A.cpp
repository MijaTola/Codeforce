#include <iostream>

using namespace std;

int main(){
    int n,d;
    cin >> n >> d;

    int ans = 0;
    int c = 0;
    bool flag = true;
    for (int i = 0; i < d; ++i){
        flag = true;
        for (int j = 0; j < n; ++j){
            char x; cin >> x;
            if(x -'0' == 0) flag = false;
        }
        if(!flag) c++;
        else{
            ans = max(ans,c);
            c = 0;
            flag = true;
        }
    }
    if(!flag) ans = max(ans,c);
    cout << ans << endl;
    return 0;
}

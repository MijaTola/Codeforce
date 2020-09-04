#include <bits/stdc++.h>

using namespace std;

int m[4][4];
int main(){
    
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            scanf("%d",&m[i][j]);
    
    bool flag = false;
    if(m[0][2] and m[1][3]) flag = true;//right
    if(m[0][1] and m[2][3]) flag = true;//s
    if(m[0][0] and m[3][3]) flag= true;//left
    
    if(m[1][2] and m[2][3]) flag = true;//right
    if(m[1][1] and m[3][3]) flag = true;//s
    if(m[1][0] and m[0][3]) flag= true;//left
    
    if(m[2][2] and m[3][3]) flag = true;//right
    if(m[2][1] and m[0][3]) flag = true;//s
    if(m[2][0] and m[1][3]) flag= true;//left
    
    if(m[3][2] and m[0][3]) flag = true;//right
    if(m[3][1] and m[1][3]) flag = true;//s
    if(m[3][0] and m[2][3]) flag= true;//left
    
    for (int i = 0; i < 4; ++i){
        if(!m[i][3]) continue;
        for (int j = 0; j < 3; ++j){
            if(m[i][j]) return puts("YES");
        }
    }

    if(flag) puts("YES");
    else puts("NO");
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    
    int cur = 1;
    while(true){
        if(x  < cur) return puts("Vladik"),0;
        x -= cur;
        cur ++;
        if(y < cur) return puts("Valera"),0;
        y -= cur;
        cur++;
    }

    return 0;
}


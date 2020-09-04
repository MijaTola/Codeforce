#include <bits/stdc++.h>

using namespace std;

double distance(int x,int y, int a,int b){
    return sqrt((x - a)*(x - a)+(y - b)*(y - b));
}
int n,m;
int v[1000010];
int main(){
 
    scanf("%d%d",&n,&m);
    
    for (int i = 0; i < n; ++i)
        scanf("%d",v + i);

    int a = -1, b = 1e9 + 7;
    
    int ans = 0;
    while(b - a > 1){
        int mid = (a + b) / 2;
        if(f(mid) < ans)
    }
    return 0;
}


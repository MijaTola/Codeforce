#include <bits/stdc++.h>

using namespace std;

long long v[100010];
long long ac[100010];
int n,k;

bool ver(int mid, int pos){
    long long dis = pos - mid + 1;
    long long total = dis * v[pos];
    long long cur = ac[pos] - ac[mid - 1];
    long long needed = total - cur;
    return needed <= k;
}
int bs(int pos){
    int a = 0;
    int b = pos;
    while(b - a > 1){
        int mid = (a + b) / 2;
        if(ver(mid,pos)) b = mid;
        else a = mid;
    }
    return pos - b + 1;
}
int main(){
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", v + i);

    sort(v + 1, v + n + 1);
    
    for (int i = 1; i <= n; ++i)
        ac[i] = v[i] + ac[i - 1];
    
    int mx = 0;
    int id = -1;
    for (int i = 1; i <= n; ++i){
        int num = v[i];
        int cur = bs(i);
        if(cur > mx){
            mx = cur;
            id = num;
        }
    }

    printf("%d %d\n",mx,id);

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int n; 
long long a[510][510];

int main() {
    int n;
    scanf("%d",&n);
    if(n==1){cout << 1<<endl; return 0;}
    int x,y;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int v;
            scanf("%d",&v);
            a[i][j] = v;
            if(a[i][j]==0) {x=i;y=j;}
        }

    int z = 0;
    if(x==0) z++;
    long long s = 0;
    for(int j=0;j<n;j++)
        s+=a[z][j];
    long long t = s;
    for(int j=0;j<n;j++)
        t-=a[x][j];

    a[x][y] = t;
    bool ok = true;
    if(t<=0) ok  = false;
    for(int i=0;i<n;i++){
        long long s1 = 0;
        long long s2 = 0;
        for(int j=0;j<n;j++){
            s1 += a[i][j];
            s2 += a[j][i];
        }
        if(s2!=s) ok = false;
        if(s1!=s) ok = false;
    }
    long long s1 = 0;
    long long s2 = 0;
    for(int i=0;i<n;i++){
        s1 += a[i][i];
        s2 += a[n-i-1][i];
    }
    if(s2!=s) ok = false;
    if(s1!=s) ok = false;
    if(!ok) cout << -1<<"\n"; 
    else cout << t <<"\n";
}



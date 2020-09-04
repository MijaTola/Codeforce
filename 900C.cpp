#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010];
int cnt[100010];
int a[100010];
int mx[100010];
int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    int c = 0; 
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if(i)mx[i] = max(mx[i - 1], v[i]);
        else mx[i] = v[i];
        ans += mx[i] == v[i];
        if(v[i] == mx[i]) a[i] = 1;
        if(i and v[i] >= v[i - 1]) c++;
        else c = 1;
        cnt[i] = c;
    }
    for (int i = 1; i < n; ++i) 
        a[i] += a[i - 1];

    int pos = 0;
    int curmx = 0;
    int id = -1;
    while(pos < n) {
        if(v[pos] > mx[pos - 1]) {
            int lastmx = v[pos];
            int curid = pos;
            int left = a[pos - 1];
            int last = 0;
            if(pos) last = mx[pos - 1];
            pos++;
            int cur = 0;
            while(pos < n and v[pos] < lastmx) {
                curmx = max(v[pos], curmx);
                if(curmx > last and curmx == v[pos]) 
                    cur++;
                pos++;
            }
            int right = a[n - 1] - a[pos - 1];
            int total = left + cur + right;
            if(total > ans) {
                id = curid;
                ans = total;
            } else if(total == ans and v[curid] < v[id]) id = curid;
        } else pos++;
    }

    if(id != -1) return cout << v[id] << "\n",0;
    int mn = 1e9;
    for (int i = 0; i < n; ++i)
        if(v[i] != mx[i]) mn = min(mn, v[i]);
    if(mn == 1e9) return cout << "1\n",0;
    cout << mn << "\n";
    return 0;
}



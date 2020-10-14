#include <bits/stdc++.h>

using namespace std;

long long dp[300100][3];

void subtask1() {
    int n,q;
    cin >> n >> q;

    for (int i = 0; i < n + 10; ++i) {
        dp[i][0] = dp[i][1] = 0;
    }

    vector<int> v(n);
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2; ++j) {
            if(j) dp[i][j] = max(dp[i][j], dp[i + 1][1 - j] + v[i]);
            else dp[i][j] = max(dp[i][j], dp[i + 1][1 - j] - v[i]);
            dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }

    cout << dp[0][1] << "\n";
}

int v[300010];
void subtask2() {

    int n,q;
    cin >> n >> q;

    v[0] = v[n + 1] = -1e9;

    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    
    long long ans = 0;
    
    auto maxi = [&] (int i) {
        return (v[i - 1] < v[i] and v[i] > v[i + 1]);
    };
    
    auto mini = [&] (int i) {
        return (v[i - 1] > v[i] and v[i] < v[i + 1]);
    };

    auto del = [&] (int i) {
        if(maxi(i)) ans -= v[i];
        if(mini(i)) ans += v[i];
    };

    auto add = [&] (int i) {
        if(maxi(i)) ans += v[i];
        if(mini(i)) ans -= v[i];
    };

    for (int i = 1; i <= n; ++i) 
        add(i);
    
    cout << ans << "\n";
    while(q--) {
        int l, r;
        cin >> l >> r;
        del(l);
        if(l - 1 >= 1 and l - 1 != r and l - 1 != r + 1) del(l - 1);
        if(l + 1 <= n and l + 1 != r and l + 1 != r - 1) del(l + 1);

        if(l != r) {
            del(r);
            if(r - 1 >= 1 and r - 1 != l and r - 1 != l + 1) del(r - 1);
            if(r + 1 <= n and r + 1 != l and r + 1 != l - 1) del(r + 1);
        }

        swap(v[l],v[r]);
        add(l);
        if(l - 1 >= 1 and l - 1 != r and l - 1 != r + 1) add(l - 1);
        if(l + 1 <= n and l + 1 != r and l + 1 != r - 1) add(l + 1);

        if(l != r) {
            add(r);
            if(r - 1 >= 1 and r - 1 != l and r - 1 != l + 1) add(r - 1);
            if(r + 1 <= n and r + 1 != l and r + 1 != l - 1) add(r + 1);
        }
        cout << ans << "\n";
    }

}


struct values {
    long long pp,pn,np,nn;
    values () {}
};

struct node {
    node *left, *right;
    values value;
    node(){};
    node(node *l, node *r, long long a, long long b, long long c, long long d) {
        left = l, right = r;
        value.pp = a;
        value.pn = b;
        value.np = c;
        value.nn = d;
    }
};


values maxi(values a, values b) {
    values current;
    current.pp = -0;
    current.pn = -0;
    current.np = -0;
    current.nn = -0;

    current.pp = max({a.pn + b.pp, a.pp + b.np});
    current.pn = max({a.pp + b.nn, a.pn + b.pn});
    current.np = max({a.np + b.np, a.nn + b.pp});
    current.nn = max({a.np + b.nn, a.nn + b.pn});
    
    return current;
}

void build(node *cur, int l, int r) {
    if(l == r) {
        cur->value.pp = v[l];
        cur->value.pn = -0;
        cur->value.np = -0;
        cur->value.nn = -v[l];
        return;
    }

    int mid = (l + r) / 2;
    
    cur->left = new node(NULL, NULL, -0,-0,-0,-0);
    cur->right = new node(NULL, NULL, -0, -0, -0, -0);
    

    build(cur->left, l, mid);
    build(cur->right, mid + 1, r);

    cur->value = maxi(cur->left->value, cur->right->value);
}

void update(node *cur, int l, int r, int pos) {
    if(l == r) {
        cur->value.pp = v[l];
        cur->value.pn = 0;
        cur->value.np = 0;
        cur->value.nn = -v[l];
        return;
    }

    int mid = (l + r) / 2;

    if(pos <= mid) {
        update(cur->left, l, mid, pos);
    } else {
        update(cur->right, mid + 1, r, pos);
    }
    cur->value = maxi(cur->left->value, cur->right->value);
}

void sol3() {

    int n,q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    node *root = new node(NULL, NULL, 0, 0, 0, 0);

    build(root, 0, n - 1);

    long long a = root->value.pp;
    
    cout << a << "\n";

    while(q--) {
        int l,r;
        cin >> l >> r;
        l--, r--;
        swap(v[l],v[r]);
        update(root, 0, n - 1, l);
        if(l != r) update(root, 0, n - 1, r);
        cout << root->value.pp << "\n";
    }
    
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        sol3();
    }
    return 0;
}

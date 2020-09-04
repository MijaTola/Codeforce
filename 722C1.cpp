#include <bits/stdc++.h> 
using namespace std; 

struct node { 
    long long sum, prefixsum, suffixsum, maxsum; 
}; 

node tree[400010]; 
int arr[400010];
void build(int low, int high, int index) { 
    if (low == high) { 
        tree[index].sum = arr[low]; 
        tree[index].prefixsum = arr[low]; 
        tree[index].suffixsum = arr[low]; 
        tree[index].maxsum = arr[low]; 
    } 
    else { 
        int mid = (low + high) / 2; 

        build(low, mid, 2 * index + 1); 

        build(mid + 1, high, 2 * index + 2); 

        tree[index].sum = tree[2 * index + 1].sum +  
            tree[2 * index + 2].sum; 

        tree[index].prefixsum =  
            max(tree[2 * index + 1].prefixsum, 
                    tree[2 * index + 1].sum +  
                    tree[2 * index + 2].prefixsum); 

        tree[index].suffixsum =  
            max(tree[2 * index + 2].suffixsum, 
                    tree[2 * index + 2].sum +  
                    tree[2 * index + 1].suffixsum); 

        tree[index].maxsum =  
            max(tree[index].prefixsum, 
                    max(tree[index].suffixsum, 
                        max(tree[2 * index + 1].maxsum, 
                            max(tree[2 * index + 2].maxsum, 
                                tree[2 * index + 1].suffixsum +  
                                tree[2 * index + 2].prefixsum)))); 
    } 
} 

void update(int index, int low, int high,  
        int idx, long long value) { 
    if (low == high) { 
        tree[index].sum = value; 
        tree[index].prefixsum = value; 
        tree[index].suffixsum = value; 
        tree[index].maxsum = value; 
    } 
    else { 

        int mid = (low + high) / 2; 

        if (idx <= mid) 
            update(2 * index + 1, low, mid, idx, value); 

        else
            update(2 * index + 2, mid + 1,  
                    high, idx, value); 

        tree[index].sum = tree[2 * index + 1].sum +  
            tree[2 * index + 2].sum; 

        tree[index].prefixsum =  
            max(tree[2 * index + 1].prefixsum, 
                    tree[2 * index + 1].sum +  
                    tree[2 * index + 2].prefixsum); 

        tree[index].suffixsum =  
            max(tree[2 * index + 2].suffixsum, 
                    tree[2 * index + 2].sum +  
                    tree[2 * index + 1].suffixsum); 

        tree[index].maxsum =  
            max(tree[index].prefixsum, 
                    max(tree[index].suffixsum, 
                        max(tree[2 * index + 1].maxsum, 
                            max(tree[2 * index + 2].maxsum, 
                                tree[2 * index + 1].suffixsum +  
                                tree[2 * index + 2].prefixsum)))); 
    } 
} 

node query(int index, int low,  
        int high, int l, int r) { 
    node result; 
    result.sum = result.prefixsum =  
        result.suffixsum =  
        result.maxsum = -1e14; 

    if (r < low || high < l) 
        return result; 

    if (l <= low && high <= r) 
        return tree[index]; 

    int mid = (low + high) / 2; 

    if (l > mid) 
        return query(2 * index + 2,  
                mid + 1, high, l, r); 

    if (r <= mid) 
        return query(2 * index + 1,  
                low, mid, l, r); 

    node left = query(2 * index + 1,  
            low, mid, l, r); 
    node right = query(2 * index + 2,  
            mid + 1, high, l, r); 

    result.sum = left.sum + right.sum; 
    result.prefixsum = max(left.prefixsum, left.sum +  
            right.prefixsum); 

    result.suffixsum = max(right.suffixsum, 
            right.sum + left.suffixsum); 
    result.maxsum = max(result.prefixsum, 
            max(result.suffixsum, 
                max(left.maxsum, 
                    max(right.maxsum, 
                        left.suffixsum + right.prefixsum)))); 

    return result; 
} 

int main() { 
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> arr[i];
    
    build(0, n - 1, 0); 

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        update(0, 0, n - 1, x - 1, -1e14);
        cout << max(query(0, 0, n - 1, 0, n - 1).maxsum, 0LL) << "\n";
    }


    return 0; 
}

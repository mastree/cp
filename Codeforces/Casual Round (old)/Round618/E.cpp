#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e6 + 10;

int n;
int A[N];
double ar[N];

double t[N * 4], lazy[N * 4];
void push(int v, ll range){
    t[v * 2] += lazy[v] * (double)((range + 1) / 2);
    lazy[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v] * (double)(range / 2);
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, double add){
    if (l > r){
        return;
    } else if (tl == l && tr == r){
        t[v] += add * (double)(r - l + 1);
        lazy[v] += add;
        return;
    } 
    push(v, (ll)(tr - tl + 1));
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(tm, r), add);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

double query(int v, int tl, int tr, int l, int r){
    if (l > r){
        return 0;
    } else if (l <= tl && tr <= r){
        return t[v];
    } 
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> A[i];
    }
    for (int i=1;i<=n;i++){
        ar[i] = (double)A[i];
        update(1, 1, n, i, i, ar[i]);
    }

    for (int i=1;i<n;i++){
        int low = i, high = n;
        while (low, high){
            
        }
    }

    return 0;
}
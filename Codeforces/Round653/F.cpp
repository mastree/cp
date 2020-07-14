#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;
const int N = 2e5 + 10;

int n, q;
long long ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    long long pre[MAXN];
    fill(pre, pre + N, 0);
    while (q--){
        int l, r;
        long long val;
        cin >> l >> r >> val;
        pre[l] += val;
        pre[r + 1] -= val;
    }
    long long cur = 0;
    for (int i=1;i<=n;i++){
        cur += pre[i];
        ar[i] += cur;
        cout << ar[i] << " ";
    }
    cout << endl;

    return 0;
}
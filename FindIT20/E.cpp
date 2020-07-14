#include <bits/stdc++.h>

// UJIAN PENYIHIR

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

const int N = 1e6 + 10;

int n, x, m;
int mn = MOD;
int ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        mn = min(mn, b - a + 1);
    }

    mn = min(mn, x);
    cout << mn+1 << el;
    for (int i=1;i<=n;i++){
        ans[i] = (i - 1) % mn + 1;
        cout << x - ans[i] << " ";
    }
    cout << el;

    return 0;
}
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

int tc;
int n, x, m;
int l, r;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--){
        cin >> n >> x >> m;
        int a = x, b = x;
        for (int i=1;i<=m;i++){
            cin >> l >> r;
            if ((l <= a && a <= r) || (l <= b && b <= r)){
                a = min(l, a);
                b = max(b, r);
            }
        }
        cout << b - a + 1 << el;
    }

    return 0;
}
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

const int N = 100;

int q, n;
string s;

int ar[N], pre[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> s;
        s = "*" + s;
        fill(pre, pre + n + 2, 0);
        for (int i=1;i<=n;i++){
            if (s[i] == '(') ar[i] = 1;
            else ar[i] = -1;
        }
        for (int i=1;i<=n;i++){
            pre[i] = pre[i - 1] + ar[i];
        }
        int mn = 0;
        for (int i=1;i<=n;i++){
            mn = min(mn, pre[i]);
        }
        cout << abs(mn) << el;
    }

    return 0;
}
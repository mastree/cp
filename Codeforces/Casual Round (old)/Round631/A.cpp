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

const int N = 2e5 + 10;

int n, m;
int ar[N], col[N];
int ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> ar[i];
    }

    bool bisa = 1;
    for (int i=1;i<=m;i++){
        int leftest = i + ar[i] - 1;
        if (leftest > n){
            cout << -1 << el;
            return 0;
        }
        ans[i] = i;
    }

    int le = n + 1;
    for (int i=m;i>=1;i--){
        int cur = ans[i] + ar[i] - 1;
        if (cur < le - 1){
            ans[i] = le - ar[i];
        }
        le = ans[i];
    }

    for (int i=1;i<=m;i++){
        col[ans[i]]++;
        col[ans[i] + ar[i]]--;
    }

    int cur = 0;
    for (int i=1;i<=n;i++){
        cur += col[i];
        col[i] = cur;
        if (col[i] == 0){
            cout << -1 << el;
            return 0;
        }
    }

    for (int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    cout << el;

    return 0;
}
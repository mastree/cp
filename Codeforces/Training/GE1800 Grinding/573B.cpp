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

const int N = 1e5 + 10;

int n;
int ar[N];
int le[N], ri[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }

    int cur = 0;
    for (int i=1;i<=n;i++){
        cur++;
        cur = min(cur, ar[i]);
        le[i] = cur;
    }
    cur = 0;
    for (int i=n;i>=1;i--){
        cur++;
        cur = min(cur, ar[i]);
        ri[i] = cur;
    }

    int ans = 0;
    for (int i=1;i<=n;i++){
        ans = max(ans, min(le[i], ri[i]));
    }
    cout << ans << el;

    return 0;
}
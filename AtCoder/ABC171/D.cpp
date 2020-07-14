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
ll ar[N], cnt[N];
int q;
ll tot = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cnt[ar[i]]++;
        tot += ar[i];
    }
    cin >> q;
    while (q--){
        ll a, b;
        cin >> a >> b;
        tot += (b - a) * cnt[a];
        cnt[b] += cnt[a];
        cnt[a] = 0;
        cout << tot << el;
    }

    return 0;
}
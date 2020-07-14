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

int n, k;
int ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=k;i++){
        int ton[n + 2];
        fill(ton, ton + n + 2, 0);

        for (int j=1;j<=n;j++){
            int l = max(1, j - ar[j]);
            int r = min(n, j + ar[j]);
            ton[l]++;
            ton[r + 1]--;
        }
        int cur = 0;
        int cnt = 0;
        for (int i=1;i<=n;i++){
            cur += ton[i];
            ar[i] = cur;
            if (cur == n) cnt++;
        }
        if (cnt == n) break;
    }
    for (int i=1;i<=n;i++){
        cout << ar[i] << " ";
    }
    cout << el;

    return 0;
}
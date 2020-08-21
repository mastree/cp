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
const int M = 1e6 + 10;

int n;
int ar[N];
int cnt[M];
int cek[M];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        cnt[ar[i]]++;
    }
    for (int i=1;i<M;i++){
        if (!cnt[i]) continue;
        for (int j=i;j<M;j+=i){
            cek[j] += cnt[j];
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (cek[ar[i]] == 1) ans++;
    }
    cout << ans << el;

    return 0;
}
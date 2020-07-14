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

const int N = 3e5 + 10;

int n, m;
ll ar[N], br[N];
ll pca[N], pcb[N];

ll geta(ll a, ll b){
    return pca[b] - pca[a - 1];
}
ll getb(ll a, ll b){
    return pcb[b] - pcb[a - 1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        pca[i] = pca[i - 1] + ar[i];
    }
    cin >> m;
    for (int i=1;i<=m;i++){
        cin >> br[i];
        pcb[i] = pcb[i - 1] + br[i];
    }
    if (pca[n] != pcb[m]){
        cout << -1 << el;
        return 0;
    }
    ll ansa = n, ansb = m;
    int pta = 1, ptb = 1;
    while (pta <= n && ptb <= m){
        int na = pta, nb = ptb;
        while (geta(pta, na) != getb(ptb, nb)){
            if (geta(pta, na) > getb(ptb, nb)){
                nb++;
            } else{
                na++;
            }
        }
        ansa -= na - pta;
        ansb -= nb - ptb;
        pta = na + 1;
        ptb = nb + 1;
    }
    cout << min(ansa, ansb) << el;

    return 0;
}
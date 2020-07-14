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
const int INF = 1e8;

int n, d;
vector <int> in[N], out[N];

int deg[N];
int taken = 0;

set <int> setdah;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    for (int i=1;i<=n;i++){
        int len;
        cin >> len;
        for (int j=0;j<len;j++){
            int x;
            cin >> x;
            in[i].pb(x);
            out[x].pb(i);
            deg[i]++;
        }
    }

    for (int i=1;i<=n;i++){
        if (deg[i] == 0){
            setdah.insert(i - 1);
        }
    }
    int now = 0;
    vector <int> ans;
    while (taken < n){
        auto it = setdah.lower_bound(n - now);
        if (it == setdah.end()) it = setdah.begin();

        int ambil = (*it) + 1;
        int struk = ((*it) + now) % n;
        ans.pb(struk);

        taken++;
        setdah.erase(it);
        for (auto child : out[ambil]){
            if (--deg[child] == 0){
                setdah.insert(child - 1);
            }
        }

        now = (now + d) % n;
    }

    for (int i=0;i<n;i++){
        cout << ans[i];
        if (i != n-1) cout << " ";
    }
    cout << el;

    return 0;
}
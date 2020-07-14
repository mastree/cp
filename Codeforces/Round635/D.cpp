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
const ll INF = 4e18;

int q;
// int ar[3][N];

ll hitung(ll r, ll g, ll b){
    // cout << r << " " << g << " " << b << el;
    ll x = r - g;
    ll y = r - b;
    ll z = g - b;
    return x * x + y * y + z * z;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        int n[3];
        ll ans = INF;
        set <ll> setdah[3];
        cin >> n[0] >> n[1] >> n[2];
        for (int i=0;i<3;i++){
            for (int j=1;j<=n[i];j++){
                ll a;
                cin >> a;
                setdah[i].insert(a);
            }
        }
        for (auto r : setdah[0]){
            for (int i=1;i<=2;i++){
                int j = i % 2 + 1; 
                // cout << r << el;
                auto itb1 = setdah[i].lower_bound(r);
                auto ita1 = itb1;
                if (ita1 != setdah[i].begin()) ita1--;
                if (itb1 == setdah[i].end()) itb1--;

                auto b2 = setdah[j].lower_bound(((*ita1) + r) / 2);
                auto b1 = b2;
                if (b1 != setdah[j].begin()) b1--;
                auto b4 = setdah[j].lower_bound(((*itb1) + r) / 2);
                auto b3 = b4;
                if (b3 != setdah[j].begin()) b3--; 
                if (b2 == setdah[j].end()) b2--;
                if (b4 == setdah[j].end()) b4--;

                // pilih ita1
                ll temp;
                temp = min(hitung(r, (*ita1), (*b1)), hitung(r, (*ita1), (*b2)));
                ans = min(ans, temp);
                temp = min(hitung(r, (*itb1), (*b3)), hitung(r, (*itb1), (*b4)));
                ans = min(ans, temp);
            }
        }
        cout << ans << el;
    }

    return 0;
}
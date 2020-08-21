#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
// #define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 1e5 + 10;
const ll INF = 1e18;
const long double PI = acos(-1);

int n;
ll ar[N];

ll last[N];

set<pair<ll, ll>> setdah;
map<ll, ll> cek;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        ll r, h;
        cin >> r >> h;
        ar[i] = r * r * h;
    }

    setdah.insert(mp(INF, 0));
    for (int i=n;i>=1;i--){
        auto temp = setdah.upper_bound(mp(ar[i], INF));
        pair<ll, ll> baru = mp(ar[i], ar[i] + temp->se);
        ll sim = cek[baru.fi];

        vector <pair<ll, ll>> apus;
        if (sim != 0){
            if (sim < baru.se){
                while (temp != setdah.begin()){
                    temp--;
                    if (temp -> se <= baru.se){
                        apus.pb(*temp);
                    } else{
                        break;
                    }
                }
                setdah.insert(baru);
                cek[baru.fi] = baru.se;
            }
        } else{
            while (temp != setdah.begin()){
                temp--;
                if (temp -> se <= baru.se){
                    apus.pb(*temp);
                } else{
                    break;
                }
            }
            setdah.insert(baru);
            cek[baru.fi] = baru.se;
        }
        for (auto x : apus){
            setdah.erase(x);
        }
    }

    ll ans = 0;
    for (auto x : setdah){
        if (x.se > ans) ans = x.se;
    }

    cout << fixed << setprecision(10) << (long double)ans * PI << el;

    return 0;
}
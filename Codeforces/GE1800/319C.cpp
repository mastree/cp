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

const double B = 1e9 + 2;
const int N = 1e5 + 10;

int n;
ll ar[N], br[N];
ll dp[N];

set<pair<pair<ll, ll>, int>> setdah; // -a, c, id
set<pair<double, int>> setid;
double awal[N];

double intersect(pair<ll, ll> a, pair<ll, ll> b){
    return ((double)(b.se - a.se)) / ((double)(b.fi - a.fi));
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    for (int i=1;i<=n;i++){
        cin >> br[i];
    }
    dp[n] = 0LL;
    int last = n;
    setdah.insert(mp(mp(-(ar[n]), dp[n]), n));
    awal[n] = -B;
    setid.insert(mp(awal[n], n));
    for (int i=n - 1;i>=1;i--){
        auto ittt = setid.upper_bound(mp((double)br[i], 0));
        ittt--;
        int id = ittt->se;
        dp[i] = (ar[id]) * br[i] + dp[id];
        // cout << i << " " << id << " => " << dp[i] << el;

        pair<pair<ll, ll>, int> temp = mp(mp(-(ar[i]), dp[i]), i);
        auto ita = setdah.lower_bound(temp);
        auto itb = ita;
        vector<pair<pair<ll, ll>, int>> pus;
        awal[i] = -B;
        if (ita != setdah.begin()){
            ita--;
            awal[i] = intersect(ita->fi, temp.fi);
            while (awal[i] <= awal[ita->se]){// !is_ledu(ita->fi, temp.fi)){
                pus.pb(*ita);
                if (ita == setdah.begin()){
                    awal[i] = -B;
                    break;
                }
                ita--;
                awal[i] = intersect(ita->fi, temp.fi);
            }
        }
        if (itb != setdah.end()){
            auto nx = itb;
            nx++;
            while (nx != setdah.end()){
                if (intersect(itb->fi, temp.fi) <= awal[i]){
                    pus.pb(*itb);
                } else{
                    break;
                }
                nx++;
                itb++;
            }
            setid.erase(mp(awal[itb->se], itb->se));
            awal[itb->se] = intersect(itb->fi, temp.fi);
            setid.insert(mp(awal[itb->se], itb->se));
        }
        setdah.insert(temp);
        setid.insert(mp(awal[i], i));
        for (auto x : pus){
            setid.erase(mp(awal[x.se], x.se));
            setdah.erase(x);
        }
    }
    cout << dp[1] << el;

    return 0;
}
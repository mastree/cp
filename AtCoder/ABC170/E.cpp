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

int n, q;
pii ar[N]; // val, kind

set<pii> kin[N], alkin;

void addalkin(set<pii>& setdah, int val){
    auto it = setdah.lower_bound(mp(val, 0));
    if (it == setdah.end() || it->fi != val){
        setdah.insert(mp(val, 1));
    } else{
        setdah.insert(mp(it->fi, it->se + 1));
        setdah.erase(*it);
    }
}
void minusalkin(set<pii>& setdah, int val){
    auto it = setdah.lower_bound(mp(val, 0));
    if (it == setdah.end() || it->fi != val){
        return;
    } else{
        if (it->se == 1){
            setdah.erase(*it);
        } else{
            setdah.insert(mp(it->fi, it->se - 1));
            setdah.erase(*it);
        }
    }
}

void addset(set<pii>& setdah, int val){
    if (setdah.empty()){
        setdah.insert(mp(val, 1));
        addalkin(alkin, val);
        return;
    }
    auto it = setdah.lower_bound(mp(val, 0));
    auto last = *setdah.rbegin();
    if (it == setdah.end() || it->fi != val){
        setdah.insert(mp(val, 1));
    } else{
        setdah.insert(mp(it->fi, it->se + 1));
        setdah.erase(*it);
    }
    auto nlast = *setdah.rbegin();
    if (last.fi != nlast.fi){
        minusalkin(alkin, last.fi);
        addalkin(alkin, nlast.fi);
    }
}
void minusset(set<pii>& setdah, int val){
    auto it = setdah.lower_bound(mp(val, 0));
    auto last = *setdah.rbegin();
    if (it == setdah.end() || it->fi != val){
        return;
    } else{
        if (it->se == 1){
            setdah.erase(*it);
        } else{
            setdah.insert(mp(it->fi, it->se - 1));
            setdah.erase(*it);
        }
    }
    if (setdah.empty()){
        minusalkin(alkin, last.fi);
        return;
    }
    auto nlast = *setdah.rbegin();
    if (last.fi != nlast.fi){
        minusalkin(alkin, last.fi);
        addalkin(alkin, nlast.fi);
    }
}
int ask(){
    auto it = alkin.begin();
    return it->fi;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
        addset(kin[ar[i].se], ar[i].fi);
    }

    while (q--){
        int c, d;
        cin >> c >> d;

        if (ar[c].se == d){
            cout << ask() << el;
            continue;
        }
        minusset(kin[ar[c].se], ar[c].fi);
        ar[c].se = d;
        addset(kin[ar[c].se], ar[c].fi);
        cout << ask() << el;
    }

    return 0;
}
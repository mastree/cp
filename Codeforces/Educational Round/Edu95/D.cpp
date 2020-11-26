#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 2e5 + 10;

int n, q;
set<int> setdah;
multiset<int> mset;

void tambah(int a){
    if (setdah.empty()){
        setdah.insert(a);
        return;
    }
    auto ita = setdah.lower_bound(a);
    auto itb = ita;
    if (ita == setdah.begin()){
        setdah.insert(a);
        mset.insert(*itb - a);
        return;
    }
    ita--;
    if (itb == setdah.end()){
        setdah.insert(a);
        mset.insert(a - *ita);
    } else{
        mset.erase(mset.find(*itb - *ita));
        mset.insert(*itb - a);
        mset.insert(a - *ita);
        setdah.insert(a);
    }
}
void hapus(int a){
    if (setdah.size() == 1){
        setdah.erase(a);
        return;
    }
    auto ita = setdah.lower_bound(a);
    auto itb = ita;
    itb++;
    if (ita == setdah.begin()){
        setdah.erase(a);
        mset.erase(mset.find(*itb - a));
        return;
    }
    ita--;
    if (itb == setdah.end()){
        setdah.erase(a);
        mset.erase(mset.find(a - *ita));
    } else{
        mset.erase(mset.find(*itb - a));
        mset.erase(mset.find(a - *ita));
        mset.insert(*itb - *ita);
        setdah.erase(a);
    }
}
int solve(){
    if (setdah.empty()) return 0;
    int mx = *setdah.rbegin();
    int mn = *setdah.begin();
    return mx - mn - *mset.rbegin();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    mset.insert(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        int a;
        cin >> a;
        tambah(a);
    }
    cout << solve() << el;
    while (q--){
        int tipe, val;
        cin >> tipe >> val;
        if (tipe == 0){
            hapus(val);
        } else{
            tambah(val);
        }
        cout << solve() << el;
    }

    return 0;
}
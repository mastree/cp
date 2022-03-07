#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n;

struct Adj {
    ll pdif;
    ll vdif;
    int l;
    int r;

    Adj() {}
    Adj(ll a, ll b, int c, int d) : pdif(a), vdif(b), l(c), r(d) {}
    bool sign(){
        return pdif >= 0 != vdif >= 0;
    }
    bool operator<(const Adj& rhs) const {
        if (pdif * rhs.vdif == rhs.pdif * vdif) return l < rhs.l;
        return pdif * rhs.vdif > rhs.pdif * vdif;
    }
};

Adj makeadj(pii a, pii b, int l, int r){
    return Adj((ll) b.first - a.first, (ll) b.second - a.second, l, r);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<pii> ar(n);
    for (int i=0;i<n;i++){
        cin >> ar[i].first >> ar[i].second;
    }
    // first set
    // store: id left, id right

    // second set
    // store: dif pos, dif v, id left, id right
    set<pii> setpos;
    set<Adj> setdah;
    setpos.insert(mp(-1, 0));
    for (int i=0;i<n - 1;i++){
        setpos.insert(mp(i, i + 1));
        setdah.insert(makeadj(ar[i], ar[i + 1], i, i + 1));
    }
    setpos.insert(mp(n - 1, n));
    while (!setdah.empty() && setdah.begin()->vdif < 0){
        auto tp = *setdah.begin();
        setdah.erase(tp);
        vector<pii> pus = {mp(tp.l, tp.r)};
        {
            auto a = setpos.find(mp(tp.l, tp.r));
            auto c = a--;
            auto b = c++;
            setdah.erase(makeadj(ar[a->first], ar[a->second], a->first, a->second));
            pus.pb(*a);
            setdah.erase(makeadj(ar[c->first], ar[c->second], c->first, c->second));
            pus.pb(*c);
            setpos.insert(mp(a->first, c->second));
            if (a->first != -1 && c->second != n) setdah.insert(makeadj(ar[a->first], ar[c->second], a->first, c->second));
        }
        for (auto& x : pus) setpos.erase(x);
    }
    set<int> ans;
    for (auto& x : setpos){
        if (x.fi != -1) ans.insert(x.fi + 1);
        if (x.se != n) ans.insert(x.se + 1);
    }
    cout << ans.size() << el;
    for (auto& x : ans) cout << x << ' '; cout << el;

    return 0;
}
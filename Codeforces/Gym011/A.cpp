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
const int INF = 1e9;

struct Frog{
    int l, w, h;
    Frog(){}
    Frog(int a, int b, int c) : l(a), w(b), h(c) {}
};

bool comp(const Frog& a, const Frog& b){
    if (a.w != b.w) return a.w > b.w;
    return a.h > b.h;
}

void tambah(set<pii>& setdah, pii a){
    auto it = setdah.lower_bound(a);
    if (it->se >= a.se) return;
    setdah.insert(a);
    auto itpus = setdah.lower_bound(a);
    vector<pii> pus;
    while (itpus != setdah.begin()){
        itpus--;
        if (itpus->se <= a.se){
            pus.pb(*itpus);
        } else break;
    }
    for (auto x : pus){
        setdah.erase(x);
    }
}

int n, d;
Frog ar[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;
    for (int i=1;i<=n;i++){
        int a, b, c;
        cin >> a >> b >> c;
        ar[i] = Frog(a, b, c);
    }
    sort(ar + 1, ar + n + 1, &comp);
    set<pii> setdah; // cap, height
    setdah.insert(mp(INF, 0));

    int ans = 0;
    for (int i=1;i<=n;i++){
        auto it = setdah.lower_bound(mp(ar[i].w, 0));
        if (it->se + ar[i].l > d) ans++;
        auto it2 = setdah.lower_bound(mp(ar[i].w + ar[i].w - 1, 0));
        pii baru1 = mp(min(ar[i].w - 1, it->fi - ar[i].w), min(ar[i].h + it->se, INF));
        pii baru2 = mp(ar[i].w - 1, min(ar[i].h + it2->se, INF));

        tambah(setdah, baru2);
        tambah(setdah, baru1);
    }
    cout << ans << el;

    return 0;
}
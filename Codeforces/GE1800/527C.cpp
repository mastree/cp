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

const int N = 2e5 + 7;

int w, h, n;

set <pii> hor[2], ver[2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> w >> h >> n;
    hor[0].insert(mp(0, 0));
    ver[0].insert(mp(0, 0));
    hor[0].insert(mp(h, h));
    ver[0].insert(mp(w, w));

    hor[1].insert(mp(0, 0));
    ver[1].insert(mp(0, 0));
    hor[1].insert(mp(h, h));
    ver[1].insert(mp(w, w));
    while (n--){
        char tipe;
        int x;
        cin >> tipe >> x;
        if (tipe == 'H'){
            auto b = *hor[0].lower_bound(mp(x, -1));
            if (b.fi == x) continue;
            hor[0].erase(b);
            hor[1].erase(mp(b.se, b.fi));

            b = mp(b.fi - b.se, b.fi);
            pii new1, new2;
            new1 = mp(x, x - b.fi);
            new2 = mp(b.se, b.se - x);

            hor[0].insert(new1);
            hor[0].insert(new2);
            hor[1].insert(mp(new1.se, new1.fi));
            hor[1].insert(mp(new2.se, new2.fi));
        } else{
            auto b = *ver[0].lower_bound(mp(x, -1));
            if (b.fi == x) continue;
            ver[0].erase(b);
            ver[1].erase(mp(b.se, b.fi));

            b = mp(b.fi - b.se, b.fi);
            pii new1, new2;
            new1 = mp(x, x - b.fi);
            new2 = mp(b.se, b.se - x);

            ver[0].insert(new1);
            ver[0].insert(new2);
            ver[1].insert(mp(new1.se, new1.fi));
            ver[1].insert(mp(new2.se, new2.fi));
        }
        auto a = *hor[1].rbegin();
        auto b = *ver[1].rbegin();

        cout << ((ll)a.fi) * ((ll)b.fi) << el;
    }

    return 0;
}
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

struct hue{
    ll t, a, b, jth;
};

struct line{
    ll pos, ta, id;

    bool operator<(const line& rhs) const{
        if (pos < rhs.pos) return 1;
        if (pos == rhs.pos){
            if (ta < rhs.ta) return 1;
            if (ta == rhs.ta){
                return id < rhs.id;
            }
        }
        return false;
    }

    bool operator>(const line& rhs) const{
        if (pos > rhs.pos) return 1;
        if (pos == rhs.pos){
            if (ta > rhs.ta) return 1;
            if (ta == rhs.ta){
                return id > rhs.id;
            }
        }
        return false;
    }

    bool operator==(const line& rhs) const{
        return (pos == rhs.pos && ta == rhs.ta && id == rhs.id); 
    }
};

int n, k, m;
ll pos[N];
set <line> taxi;
hue req[N];
pair<ll,ll> ans[N];

bool comp(hue a, hue b){
    return a.t < b.t;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> m;
    for (int i=1;i<=k;i++){
        cin >> pos[i];
        line tem;
        tem.pos = pos[i];
        tem.ta = 0;
        tem.id = i;
        taxi.insert(tem);
    }  

    // for (auto x : taxi){
    //     cout << x.pos << " " << x.ta << " " << x.id << el;
    // }

    for (int i=1;i<=m;i++){
        hue tem;
        cin >> tem.t >> tem.a >> tem.b;

        tem.jth = i;
        req[i] = tem;
    }

    sort(req + 1, req + m + 1, comp);
    // for (int i=1;i<=m;i++){
    //     cout << req[i].t << " " << req[i].a << " " << req[i].b << el;
    // }
    ll dt = 0;
    ll last = 0;
    for (int i=1;i<=m;i++){
        hue pas = req[i];
        ll time = pas.t;
        dt = max((ll)0, last - time);
        line tem;
        tem.pos = pas.a;
        tem.ta = 0;
        tem.id = 0;

        // cout << i << ":: " << el;
        // for (auto x : taxi){
        //     cout << x.pos << " " << x.ta << " " << x.id << el;
        // }
        
        auto it = taxi.upper_bound(tem);
        
        if (it != taxi.begin() && it != taxi.end()){
            auto itb = it--;
            tem.pos = (*it).pos;
            auto ita = taxi.upper_bound(tem);

            line c1, c2;
            c1 = *ita;
            c1.pos = abs((*ita).pos - pas.a);
            c2 = *itb;
            c2.pos = abs((*itb).pos - pas.a);
            if (c1 < c2){
                ll jarak = abs((*ita).pos-pas.a);
                ll cons = jarak + abs(pas.a - pas.b);
                ans[pas.jth] = mp(jarak + dt, (*ita).id);
                last = cons + dt + time;
                tem.pos = pas.b;
                tem.ta = last;
                tem.id = (*ita).id;
                taxi.erase(ita);
                taxi.insert(tem);
            } else{
                ll jarak = abs((*itb).pos-pas.a);
                ll cons = jarak + abs(pas.a - pas.b);
                ans[pas.jth] = mp(jarak + dt, (*itb).id);
                last = cons + dt + time;
                tem.pos = pas.b;
                tem.ta = last;
                tem.id = (*itb).id;
                taxi.erase(itb); 
                taxi.insert(tem);
            }
        } else if (it == taxi.begin()){
            ll jarak = abs((*it).pos-pas.a);
            ll cons = jarak + abs(pas.a - pas.b);
            ans[pas.jth] = mp(jarak + dt, (*it).id);
            last = cons + dt + time;
            tem.pos = pas.b;
            tem.ta = last;
            tem.id = (*it).id;
            taxi.erase(it);
            taxi.insert(tem);
        } else {
            auto ita = --it;
            tem.pos = (*ita).pos;
            auto itb = taxi.upper_bound(tem);
            ll jarak = abs((*itb).pos-pas.a);
            ll cons = jarak + abs(pas.a - pas.b);
            ans[pas.jth] = mp(jarak + dt, (*itb).id);
            last = cons + dt + time;
            tem.pos = pas.b;
            tem.ta = last;
            tem.id = (*itb).id;
            taxi.erase(itb);
            taxi.insert(tem);
        }

        // cout << "akhir => " << el;
        // for (auto x : taxi){
        //     cout << x.pos << " " << x.ta << " " << x.id << el;
        // }
    }

    for (int i=1;i<=m;i++){
        cout << ans[i].se << " " << ans[i].fi << el;
    }

    return 0;
}
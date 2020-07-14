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
const int INF = 1e9;

struct hue{
    int a, b, c;

    hue(){a = b = c = 0;}
    hue(int a, int b, int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

bool comp(hue a, hue b){
    if (a.a == b.a){
        if (a.b == b.b){
            return a.c < b.c;
        }
        return a.b < b.b;
    }
    return a.a < b.a;
}

int n, m;
vector <pii> adl[N];
int dist[3][N];

hue ar[N];
bool tolak[N];

void dijkstra(int source){
    fill(dist[source], dist[source] + n + 2, INF);
    set <pii> setdah;
    dist[source][source] = 0;
    for (int i=0;i<n;i++){
        setdah.insert(mp(dist[source][i], i));
    }

    while (!setdah.empty()){
        auto it = setdah.begin();
        int node = it->se;
        int jarak = it->fi;
        setdah.erase(it);
        for (auto x : adl[node]){
            if (jarak + x.se < dist[source][x.fi]){
                setdah.erase(mp(dist[source][x.fi], x.fi));
                dist[source][x.fi] = jarak + x.se;
                setdah.insert(mp(dist[source][x.fi], x.fi));
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b, w;
        cin >> a >> b >> w;
        adl[a].pb(mp(b, w));
        adl[b].pb(mp(a, w));
    }

    for (int i=0;i<3;i++) dijkstra(i);
    for (int i=0;i<n;i++){
        ar[i] = hue(dist[0][i], dist[1][i], dist[2][i]);
    }
    sort(ar, ar + n, comp);
    set <pii> setdah;
    vector <int> v;
    int last = -1;
    setdah.insert(mp(-1, INF));
    setdah.insert(mp(INF, -1));
    int ans = n;
    for (int i=0;i<n;i++){
        if (last != ar[i].a){
            for (auto x : v){
                pii temp = mp(ar[x].b, ar[x].c);
                auto ita = setdah.lower_bound(temp);
                auto itb = ita--;
                if (ita->se > temp.se){
                    vector <pii> del;
                    while (itb->se >= temp.se){
                        del.pb(*itb);
                        itb++;
                    }
                    for (auto x : del) setdah.erase(x);
                    setdah.insert(temp);
                }
            }
            for (auto x : v){
                if (!tolak[x]){
                    pii temp = mp(ar[x].b, ar[x].c);
                    auto it = setdah.lower_bound(temp);
                    it--;
                    if (it->fi <= temp.fi && it->se < temp.se){
                        tolak[x] = 1;
                    } else if (it->fi < temp.fi && it->se <= temp.se){
                        tolak[x] = 1;
                    }
                }
            }
            v.clear();
            last = ar[i].a;
        } 
        v.pb(i);
        pii temp = mp(ar[i].b, ar[i].c);
        auto it = setdah.upper_bound(temp);
        it--;
        if (it->se <= temp.se){
            tolak[i] = 1;
        }
    } 
    for (auto x : v){
        pii temp = mp(ar[x].b, ar[x].c);
        auto ita = setdah.lower_bound(temp);
        auto itb = ita--;
        if (ita->se > temp.se){
            vector <pii> del;
            while (itb->se >= temp.se){
                del.pb(*itb);
                itb++;
            }
            for (auto x : del) setdah.erase(x);
            setdah.insert(temp);
        }
    }
    for (auto x : v){
        if (!tolak[x]){
            pii temp = mp(ar[x].b, ar[x].c);
            auto it = setdah.lower_bound(temp);
            it--;
            if (it->fi <= temp.fi && it->se < temp.se){
                tolak[x] = 1;
            } else if (it->fi < temp.fi && it->se <= temp.se){
                tolak[x] = 1;
            }
        }
    }
    for (int i=0;i<n;i++){
        if (tolak[i]){
            ans--;
        }
    }
    cout << ans << el;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int N = 1e5 + 10;
const int INF = 1e9;

int n;
pii tempar[N], ar[N];
map<int, int> getid1, getid2;

set<pii> bit[N];
int lis[N];

void addto(int x, pii val){
    auto itb = bit[x].lower_bound(val);
    auto ita = itb;
    ita--;
    if (ita->second >= val.second) return;
    vector<pii> pus;
    while (itb->second <= val.second){
        pus.push_back(*itb);
        itb++;
    }
    for (auto del : pus) bit[x].erase(del);
    bit[x].insert(val);
}
int findat(int x, int y){
    auto it = bit[x].lower_bound(make_pair(y + 1, 0));
    it--;
    return it->second;
}
void update(int x, pii val){
    while (x < N){
        addto(x, val);
        x = x + (x & (-x));
    }
}
int ask(int x, int y){
    int ret = 0;
    while (x > 0){
        ret = max(ret, findat(x, y));
        x = x - (x & (-x));
    }
    return ret;
}

int main(){
    cin >> n;
    for (int i=1;i<N;i++){
        bit[i].insert(make_pair(0, 0));
        bit[i].insert(make_pair(INF, INF));
    }
    for (int i=1;i<=n;i++){
        cin >> tempar[i].first >> tempar[i].second;
        getid1[tempar[i].first] = 1;
        getid2[tempar[i].second] = 1;
    }
    int tempid = 0;
    for (auto x : getid1) getid1[x.first] = ++tempid;
    tempid = 0;
    for (auto x : getid2) getid2[x.first] = ++tempid;
    for (int i=1;i<=n;i++){
        ar[i] = make_pair(getid1[tempar[i].first], getid2[tempar[i].second]);
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        int x = ar[i].first, y = ar[i].second;
        lis[i] = ask(x - 1, y - 1) + 1;
        update(x,  make_pair(y, lis[i]));
        ans = max(ans, lis[i]);
    }
    cout << ans << '\n';

    return 0;
}
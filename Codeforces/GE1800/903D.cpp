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

typedef unsigned long long ull;

const int N = 2e5 + 10;
const ll MH = 1e18;

int n;
ll ar[N];
map<ll, int> mindex;
ll isi[N];
vector<ll> tam;

pair<ll, ll> t[4 * N]; // tot, cnt

struct BigInt{
    vector<int> dig;
    int length = 0;

    BigInt(int sz){
        length = sz;
        dig.resize(sz, 0);
    }
    BigInt(ll x){
        while (x > 0){
            dig.pb(x % 10);
            x /= 10;
            length++;
        }
    }

    const BigInt operator+(const BigInt& b){
        int rlen = max(length, b.length);
        BigInt ret = BigInt(rlen);
        int carry = 0;
        for (int i=0;i<rlen;i++){
            int cur = carry;
            if (length > i){
                cur += dig[i];
            }
            if (b.length > i){
                cur += b.dig[i];
            }
            ret.dig[i] = cur % 10;
            carry = cur / 10;
        }
        if (carry){
            ret.length++;
            ret.dig.pb(carry);
        }
        return ret;
    }

    void printBI(){
        bool udh = 0;
        for (int i=length - 1;i>=0;i--){
            if (dig[i]) udh = 1;
            if (udh) cout << dig[i];
        }
    }
};

void update(int v, int tl, int tr, int pos, ll val){
    if (tr < pos || tl > pos) return;
    else if (tl == tr){
        t[v].fi += val;
        t[v].se++;
        return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, pos, val);
    update(v * 2 + 1, tm + 1, tr, pos, val);
    t[v].fi = t[v * 2].fi + t[v * 2 + 1].fi;
    t[v].se = t[v * 2].se + t[v * 2 + 1].se;
}

pair<ll, ll> ask(int v, int tl, int tr, int l, int r){
    if (l > r) return mp(0, 0);
    else if (l <= tl && tr <= r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    pli temp1 = ask(v * 2, tl, tm, l, min(tm, r));
    pli temp2 = ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return mp(temp1.fi + temp2.fi, temp1.se + temp2.se);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        mindex[ar[i]] = 1;
    }
    int tidx = 0;
    for (auto x : mindex){
        tidx++;
        isi[tidx] = x.fi;
        mindex[x.fi] = tidx;
    }
    int last = 0;
    tam.pb(0);
    for (int i=n;i>=1;i--){
        int id = mindex[ar[i]];
        int idb = id;
        while (isi[idb] && (isi[idb] - ar[i]) <= 1) idb++;
        if (isi[idb]){
            pair<ll, ll> temp = ask(1, 1, tidx, idb, tidx);
            ll tambah = temp.fi - ar[i] * temp.se;
            if (last >= 0 && -MH <= tam[last] && tam[last] <= MH) tam[last] += tambah;
            else tam.pb(tambah);
        }
        int ida = id;
        while (isi[ida] && (ar[i] - isi[ida]) <= 1) ida--;
        if (isi[ida]){
            pair<ll, ll> temp = ask(1, 1, tidx, 1, ida);
            ll tambah = temp.fi - ar[i] * temp.se;
            if (last >= 0 && -MH <= tam[last] && tam[last] <= MH) tam[last] += tambah;
            else tam.pb(tambah);
        }
        update(1, 1, tidx, id, ar[i]);
    }
    for (int ul=1;ul<=15;ul++){
        vector<ll> v;
        int len = tam.size();
        for (int i=0;i<len - 1;i++){
            if ((tam[i] < 0 && tam[i + 1] >= 0) || (tam[i] >= 0 && tam[i + 1] < 0)){
                tam[i + 1] += tam[i];
                continue;
            } else{
                v.pb(tam[i]);
            }
        }
        v.pb(tam[len - 1]);
        tam.clear();
        for (auto x : v){
            tam.pb(x);
        }
    }
    int len = tam.size();
    if (len == 1){
        cout << tam[0] << el;
        return 0;
    }
    bool minus = (tam[0] < 0);
    BigInt temp = BigInt(abs(tam[0]));
    for (int i=1;i<len;i++) temp = temp + BigInt(abs(tam[i]));
    if (minus) cout << "-";
    temp.printBI();
    cout << el;

    return 0;
}
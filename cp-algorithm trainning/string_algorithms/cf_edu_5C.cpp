#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int INF = 1e9;

vector<int> sort_cyclic_shifts(string const& s){
    int n = (int)s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (char x : s){
        cnt[x]++;
    }
    for (int i=1;i<alphabet;i++){
        cnt[i] += cnt[i - 1];
    }
    for (int i=0;i<n;i++){
        p[--cnt[s[i]]] = i;
    }
    c[p[0]] = 0;
    int classes = 1; // cur num of classes
    for (int i=1;i<n;i++){
        if (s[p[i]] != s[p[i - 1]]) classes++;
        c[p[i]] = classes - 1;
    }

    vector<int> pn(n), cn(n);
    for (int h=0;(1 << h)<n;h++){
        for (int i=0;i<n;i++){
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0) pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i=0;i<n;i++){
            cnt[c[i]]++;
        }
        for (int i=1;i<classes;i++){
            cnt[i] += cnt[i - 1];
        }
        for (int i=n - 1;i>=0;i--){
            p[--cnt[c[pn[i]]]] = pn[i];
        }
        cn[p[0]] = 0;
        classes = 1;
        for (int i=1;i<n;i++){
            pii cur = mp(c[p[i]], c[(p[i] + (1 << h)) % n]);
            pii prev = mp(c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]);
            if (cur != prev) classes++;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s){
    s.pb(char(0));
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp_construction(string const& s, vector<int> const& p){
    int n = (int)s.size();
    vector<int> rank(n, 0);
    for (int i=0;i<n;i++) rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n - 1, 0);
    for (int i=0;i<n;i++){
        if (rank[i] == n - 1){
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}

string s;
vector<int> p;
vector<int> lcp;
vector<int> pos;
vector<pii> v;
vector<int> t;

int lcplen;

void make_stree(int v, int tl, int tr){
    if (tl == tr){
        t[v] = lcp[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    make_stree(v * 2, tl, tm);
    make_stree(v * 2 + 1, tm + 1, tr);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int ask(int v, int tl, int tr, int l, int r){
    if (l > r) return INF;
    else if (tl == l && r == tr){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(ask(v * 2, tl, tm, l, min(tm, r)), ask(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int getlcp(int a, int b){
    if (a > b) swap(a, b);
    return ask(1, 0, lcplen - 1, a, b - 1);
}

bool comp(pii a, pii b){
    int lena = a.se - a.fi + 1;
    int lenb = b.se - b.fi + 1;

    int temp = getlcp(pos[a.fi], pos[b.fi]);
    if (temp < min(lena, lenb)){
        return pos[a.fi] < pos[b.fi];
    }
    if (lena == lenb){
        return a.fi < b.fi;
    }
    return lena < lenb;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int slen = (int)s.size();

    if (slen == 1){
        int n;
        cin >> n;
        for (int i=0;i<n;i++){
            int l, r;
            cin >> l >> r;
            v.emplace_back(l, r);
        }
        for (auto x : v){
            cout << x.fi << " " << x.se << el;
        }
        return 0;
    }
    p = suffix_array_construction(s);
    lcp = lcp_construction(s, p);
    lcplen = (int)lcp.size();
    t.resize(lcplen * 4 + 10);
    make_stree(1, 0, lcplen - 1);
    pos.resize(slen);
    for (int i=0;i<slen;i++){
        pos[p[i]] = i;
    }
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        int l, r;
        cin >> l >> r;
        v.emplace_back(l - 1, r - 1);
    }
    sort(v.begin(), v.end(), comp);
    for (auto x : v){
        cout << x.fi + 1 << " " << x.se + 1 << el;
    }

    return 0;
}
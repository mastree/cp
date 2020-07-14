#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<int> sort_cyclic_shifts(string const& s){
    int n = s.size();
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
    int n = s.size();
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

int len, mdig;
string s;
vector<int> p;
vector<int> lcp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> len >> mdig;
    for (int i=0;i<len;i++){
        int x;
        cin >> x;
        s.pb(char(x));
    }
    p = suffix_array_construction(s);
    lcp = lcp_construction(s, p);

    set<pair<int, bool>> setdah;
    setdah.insert(mp(0, 0));
    setdah.insert(mp(len - 2, 1));
    vector<pii> v;
    for (int i=0;i<len - 1;i++){
        v.pb(mp(lcp[i], i));
    }
    sort(v.begin(), v.end());
    ll mx = len;
    int fac = len, pos = 0;
    for (auto x : v){
        auto ita = setdah.lower_bound(mp(x.se, 0));
        auto itb = ita;
        if (ita->se == 0){
            itb++;
        } else{
            ita--;
        }
        ll cur = itb->fi - ita->fi + 2;
        cur *= (ll)x.fi;
        if (mx < cur){
            mx = cur;
            fac = x.fi;
            pos = p[ita->fi];
        }
        if (ita->fi == itb->fi){
            setdah.erase(*ita);
            setdah.erase(*itb);
        } else if (x.se == ita->fi){
            setdah.erase(*ita);
            setdah.insert(mp(x.se + 1, 0));
        } else if (x.se == itb->fi){
            setdah.erase(*itb);
            setdah.insert(mp(x.se - 1, 1));
        } else{
            setdah.insert(mp(x.se - 1, 1));
            setdah.insert(mp(x.se + 1, 0));
        }
    }
    cout << mx << el;
    cout << fac << el;
    for (int i=pos;i<pos + fac;i++){
        cout << int(s[i]) << " ";
    }
    cout << el;

    return 0;
}
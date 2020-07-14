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
    s.pb('$');
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

string s, t, st;
vector<int> p;
vector<int> lcp;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    if (s.size() > t.size()) swap(s, t);
    st = s + "*" + t;
    int slen = s.size();
    int tlen = t.size();
    int stlen = st.size();
    p = suffix_array_construction(st);
    lcp = lcp_construction(st, p);
    
    string ans;
    int mx = 0;
    int lcplen = (int)lcp.size();
    for (int i=0;i<lcplen;i++){
        if (p[i] < slen && p[i + 1] > slen){
            mx = max(mx, min(lcp[i], min(slen - p[i], stlen - p[i + 1])));
        }
        if (p[i + 1] < slen && p[i] > slen){
            mx = max(mx, min(lcp[i], min(slen - p[i + 1], stlen - p[i])));
        }
    }
    if (mx == 0){
        cout << el;
        return 0;
    }
    for (int i=0;i<lcplen;i++){
        int cur = 0;
        if (p[i] < slen && p[i + 1] > slen){
            cur = min(lcp[i], min(slen - p[i], stlen - p[i + 1]));
        }
        if (p[i + 1] < slen && p[i] > slen){
            cur = min(lcp[i], min(slen - p[i + 1], stlen - p[i]));
        }
        if (mx == cur){
            for (int j=0;j<cur;j++){
                ans.pb(st[p[i] + j]);
            }
            break;
        }
    }
    cout << ans << el;

    return 0;
}
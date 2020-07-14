#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int M = 20;

int n, q;
string t;

vector<pii> find_suffix(string s){
    vector<vector<pii>> ret(M, vector<pii>(n));
    vector<pair<char, int>> vs;
    for (int i=0;i<n;i++){
        vs.pb(mp(s[i], i));
    }
    sort(vs.begin(), vs.end());
    int urut = 0;
    for (int i=0;i<n;i++){
        if (i != 0 && vs[i].fi != vs[i - 1].fi) ++urut;
        ret[0][i] = mp(urut, vs[i].se);
    }
    vector<int> geturut(n);
    vector<vector<pii>> radix(n), radix2(n);
    vector<pair<pii, int>> temp(n);
    for (int i=1;i<M;i++){
        int bit = (1 << (i - 1));

        for (int j=0;j<n;j++){
            geturut[ret[i - 1][j].se] = ret[i - 1][j].fi;
            radix[j].clear();
            radix2[j].clear();
        }
        for (int j=0;j<n;j++){
            int a = geturut[j];
            int b = geturut[(j + bit) % n];

            radix[b].pb(mp(a, j));
        }
        for (int j=0;j<n;j++){
            for (auto x : radix[j]){
                radix2[x.fi].pb(mp(j, x.se));
            }
        }
        int id = 0;
        for (int j=0;j<n;j++){
            for (auto x : radix2[j]){
                temp[id++] = mp(mp(j, x.fi), x.se);
            }
        }
        urut = 0;
        for (int j=0;j<n;j++){
            if (j != 0 && temp[j].fi != temp[j - 1].fi) ++urut;
            ret[i][j] = mp(urut, temp[j].se);
        }

        if (bit + bit >= n) return ret[i];
    }
    return ret[M - 1];
}

vector<int> suffix_array_construction(string s) {
    s.pb('$');
    vector<pii> sorted_shifts = find_suffix(s);
    vector<int> ret;
    for (auto x : sorted_shifts) ret.pb(x.se);
    return ret;
}

int comp(const string& s1, const string& s2){
    if (s1 > s2) return 1;
    else if (s1 == s2) return 0;
    return -1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    n = t.length() + 1;
    vector<int> suff = suffix_array_construction(t);
    t.pb('$');
    
    cin >> q;
    while (q--){
        string s;
        cin >> s;
        int len = s.length();

        string temp;
        int best1 = n, best2 = n;
        int low = 0, high = n - 1;
        while (low <= high){
            int mid = (low + high) / 2;

            temp.clear();
            for (int i=0;i<len;i++){
                temp.pb(t[(suff[mid] + i) % n]);
            }
            int res = comp(temp, s);
            if (res >= 0){
                high = mid - 1;
                best1 = mid;
            } else{
                low = mid + 1;
            }
        }
        low = 0; 
        high = n - 1;
        while (low <= high){
            int mid = (low + high) / 2;

            temp.clear();
            for (int i=0;i<len;i++){
                temp.pb(t[(suff[mid] + i) % n]);
            }
            int res = comp(temp, s);
            if (res > 0){
                high = mid - 1;
                best2 = mid;
            } else{
                low = mid + 1;
            }
        }
        cout << best2 - best1 << el;
    }

    return 0;
}
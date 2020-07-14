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
            cnt[c[pn[i]]]++;
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

string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.length();
    vector<int> suff = suffix_array_construction(s);
    int q;
    cin >> q;
    while (q--){
        string t;
        cin >> t;

        int m = t.length();
        int low = 0, high = n - 1;
        string temp;
        while (low < high){
            int mid = (low + high) / 2;
            temp.clear();
            for (int i=0;i<min(n, m);i++){
                if (i + suff[mid] >= n) break;
                temp.pb(s[i + suff[mid]]);
            }
            if (temp >= t){
                high = mid;
            } else{
                low = mid + 1;
            }
        }
        temp.clear();
        for (int i=0;i<min(n, m);i++){
            if (i + suff[high] >= n) break;
            temp.pb(s[i + suff[high]]);
        }
        if (temp == t){
            cout << "Yes" << el;
        } else{
            cout << "No" << el;
        }
    }

    return 0;
}
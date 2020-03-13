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

const int N = 510;

ll n, m, k;
string cur;
pii pos = mp(1, 1);
vector <pair<int, string>> ans;
vector <pair<int, char>> anss;

void sol(){
    cout << "YES" << el;
    for (auto x : ans){
        string s = x.se;
        int cnt = 0;
        char cur = '*';
        for (int i=0;i<s.size();i++){
            if (i == 0){
                cur = s[i];
                cnt++;
            } else{
                if (s[i] != cur){
                    anss.pb(mp(cnt, cur));
                    cnt = 1;
                    cur = s[i];
                } else{
                    cnt++;
                }
            }
        }  
        anss.pb(mp(cnt, cur));
    }

    cout << anss.size() << el;
    for (auto x : anss){
        cout << x.fi << " " << x.se << el;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    ll maks = 4 * n * m - 2 * n - 2 * m;
    if (k > maks){
        cout << "NO" << el;
        return 0;
    }

    ll s1 = (n - 1) * 2;
    ll sisa = k;
    cur = "";
    
    cur.pb('R');
    for (int i=1;i<n;i++){
        cur.pb('D');
    }
    for (int i=1;i<n;i++){
        cur.pb('U');
    }

    while (sisa >= cur.length() && pos != mp(1, (int)m)){
        sisa -= cur.length();
        ans.pb(mp(1, cur));
        pos.se++;
    }

    if (sisa < cur.length() && pos != mp(1, (int)m)){
        if (sisa) ans.pb(mp(1, cur.substr(0, sisa)));
        sol();
        return 0;
    }

    cur = "";
    for (int i=1;i<m;i++){
        cur.pb('L');
    }
    cur.pb('D');
    for (int i=1;i<m;i++){
        cur.pb('R');
    }
    while (sisa >= cur.length() && pos != mp((int)n, (int)m)){
        sisa -= cur.length();
        ans.pb(mp(1, cur));
        pos.fi++;
    }

    if (sisa < cur.length() && pos != mp((int)n, (int)m)){
        if (sisa) ans.pb(mp(1, cur.substr(0, sisa)));
        sol();
        return 0;
    }

    cur = "";
    for (int i=1;i<m;i++){
        cur.pb('L');
    }
    for (int i=1;i<n;i++){
        cur.pb('U');
    }
    if (sisa){
        ans.pb(mp(1, cur.substr(0, sisa)));
    }
    sol();

    return 0;
}
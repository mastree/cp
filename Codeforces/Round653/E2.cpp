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

const int N = 2e5 + 10;
const int INF = 1e9 + 10;

int n, m, k;

vector<pii> va, vb, vab, none;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    va.pb(mp(INF, INF));
    vb.pb(mp(INF, INF));
    vab.pb(mp(INF, INF));
    none.pb(mp(INF, INF));
    for (int i=1;i<=n;i++){
        int t, a, b;
        cin >> t >> a >> b;
        pii temp = mp(t, i);
        if (a && b){
            vab.pb(temp);
        } else if (a){
            va.pb(temp);
        } else if (b){
            vb.pb(temp);
        } else{
            none.pb(temp);
        }
    }
    sort(va.begin(), va.end(), greater<pii>());
    sort(vb.begin(), vb.end(), greater<pii>());
    sort(vab.begin(), vab.end(), greater<pii>());
    sort(none.begin(), none.end(), greater<pii>());

    int cura = 0, curb = 0;
    if ((int) vab.size() + min((int)va.size(), (int)vb.size()) - 2 < k){
        cout << -1 << el;
        return 0;
    }
    // int utes = (int) vab.size() - 1;
    // if (utes + 2 * (k - utes) > m && (utes < k)){
    //     cout << -1 << el;
    //     return 0;
    // }

    int ans = 0, ambil = 0;
    stack<pii> sta, stb, stab;
    while (cura < k && curb < k){
        pii a, b, ab;
        a = va.back();
        b = vb.back();
        ab = vab.back();
        if (a.fi + b.fi > ab.fi){
            ans += ab.fi;
            vab.pop_back();
            cura++;
            curb++;
            ambil++;

            stab.push(ab);
        } else{
            // if (a.fi < b.fi){
                ans += a.fi;
                ans += b.fi;
                va.pop_back();
                vb.pop_back();
                cura++;
                curb++;
                sta.push(a);
                stb.push(b);
                ambil++;
                ambil++;
            // } else{
            // }
        }
    }
    // while (cura < k){
    //     pii a, b, ab;
    //     a = va.back();
    //     b = stb.top();
    //     ab = vab.back();
    //     if (a.fi + b.fi > ab.fi){
    //         ans += ab.fi;
    //         stab.push(ab);
    //         vab.pop_back();
    //         cura++;
    //         stb.pop();
    //         ans -= b.fi;

    //         vb.pb(b);            
    //     } else{
    //         ans += a.fi;
    //         va.pop_back();
    //         cura++;
    //         ambil++;
    //         sta.push(a);
    //     }
    // }
    // while (curb < k){
    //     pii a, b, ab;
    //     a = sta.top();
    //     b = vb.back();
    //     ab = vab.back();
    //     if (a.fi + b.fi > ab.fi){
    //         ans += ab.fi;
    //         stab.push(ab);
    //         vab.pop_back();
    //         curb++;
    //         sta.pop();
    //         ans -= a.fi;
            
    //         va.pb(a);
    //     } else{
    //         ans += b.fi;
    //         vb.pop_back();
    //         curb++;
    //         ambil++;
    //         stb.push(b);
    //     }
    // }
    while (ambil > m){
        if (sta.empty() || stb.empty() || vab.empty()){
            cout << -1 << el;
            return 0;
        }
        pii a = sta.top();
        pii b = stb.top();
        pii ab = vab.back();
        if (ab == mp(INF, INF)){
            cout << -1 << el;
            return 0;
        }
        ambil--;
        sta.pop();
        stb.pop();
        vab.pop_back();
        va.pb(a);
        vb.pb(b);
        stab.push(ab);
        ans -= a.fi + b.fi;
        ans += ab.fi;
    }
    while (ambil < m){
        pii a, b, ab, ne;
        a = va.back();
        b = vb.back();
        ab = vab.back();
        ne = none.back();
        if (a.se == b.se && a.se == ab.se && a.se == ne.se && a.se == INF){
            cout << -1 << el;
            return 0;
        }
        if (a.fi < b.fi && a.fi < ab.fi && a.fi < ne.fi){
            va.pop_back();
            ambil++;
            ans += a.fi;
            sta.push(a);
        } else if (b.fi < a.fi && b.fi < ab.fi && b.fi < ne.fi){
            vb.pop_back();
            ambil++;
            ans += b.fi;
            stb.push(b);
        } else if (ab.fi < a.fi && ab.fi < b.fi && ab.fi < ne.fi){
            vab.pop_back();
            ambil++;
            ans += ab.fi;
            stab.push(ab);
        } else{
            none.pop_back();
            ambil++;
            ans += ne.fi;
            stab.push(ne);
        }
    }
    if (ambil < k || ambil != m || cura < k || curb < k){
        cout << -1 << el;
        return 0;
    }
    while (((int) none.size() > 1) && ((int) vab.size() > 1) && !sta.empty() && !stb.empty()){
        pii a, b, ab, ne;
        a = sta.top();
        b = stb.top();
        ab = vab.back();
        ne = none.back();

        if (ab.fi + ne.fi < a.fi + b.fi){
            ans -= a.fi + b.fi;
            ans += ab.fi + ne.fi;
            stab.push(ab);
            stab.push(ne);
            vab.pop_back();
            none.pop_back();
            sta.pop();
            stb.pop();
        } else{
            break;
        }
    }
    cout << ans << el;
    while (!sta.empty()){
        cout << sta.top().se << " ";
        sta.pop();
    }
    while (!stb.empty()){
        cout << stb.top().se << " ";
        stb.pop();
    }
    while (!stab.empty()){
        cout << stab.top().se << " ";
        stab.pop();
    }
    cout << el;

    return 0;
}
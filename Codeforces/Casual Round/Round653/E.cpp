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

int n, k;
// pair<int, pii> ar[N]; // t, a, b

// pair<int, pii> mp3(int t, int a, int b){
//     return mp(t, mp(a, b));
// }

vector<int> va, vb, vab;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    va.pb(INF);
    vb.pb(INF);
    vab.pb(INF);
    for (int i=1;i<=n;i++){
        int t, a, b;
        cin >> t >> a >> b;
        if (a && b){
            vab.pb(t);
        } else if (a){
            va.pb(t);
        } else if (b){
            vb.pb(t);
        }
    }
    sort(va.begin(), va.end(), greater<int>());
    sort(vb.begin(), vb.end(), greater<int>());
    sort(vab.begin(), vab.end(), greater<int>());

    int cura = 0, curb = 0;
    if ((int) vab.size() + min((int)va.size(), (int)vb.size()) - 2 < k){
        cout << -1 << el;
        return 0;
    }
    int ans = 0;
    stack<int> sta, stb;
    while (cura < k && curb < k){
        int a, b, ab;
        a = va.back();
        b = vb.back();
        ab = vab.back();
        if (a + b > ab){
            ans += ab;
            vab.pop_back();
            cura++;
            curb++;
        } else{
            if (a < b){
                ans += a;
                va.pop_back();
                cura++;
                sta.push(a);
            } else{
                ans += b;
                vb.pop_back();
                curb++;
                stb.push(b);
            }
        }
    }
    while (cura < k){
        int a, b, ab;
        a = va.back();
        b = stb.top();
        ab = vab.back();
        if (a + b > ab){
            ans += ab;
            vab.pop_back();
            cura++;
            stb.pop();
            ans -= b;
        } else{
            ans += a;
            va.pop_back();
            cura++;
        }
    }
    while (curb < k){
        int a, b, ab;
        a = sta.top();
        b = vb.back();
        ab = vab.back();
        if (a + b > ab){
            ans += ab;
            vab.pop_back();
            curb++;
            sta.pop();
            ans -= a;
        } else{
            ans += b;
            vb.pop_back();
            curb++;
        }
    }
    cout << ans << el;

    return 0;
}
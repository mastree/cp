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

const int N = 1e6 + 10;

int n;
ll ar[N];
stack<pair<double, pii>> st; // avg, range;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    cout << fixed << setprecision(11);
    pair<double, pii> cur = mp((double)ar[1], mp(1, 1));
    for (int i=2;i<=n;i++){
        if (cur.fi > (double) ar[i]){
            int range = (cur.se.se - cur.se.fi + 1);
            cur.fi = (cur.fi * ((double) range) + (double) ar[i]) / ((double) (range + 1));
            cur.se.se++;

            while (!st.empty() && st.top().fi > cur.fi){
                auto temp = st.top();
                st.pop();
                int range = (cur.se.se - cur.se.fi + 1);
                int range2 = (temp.se.se - temp.se.fi + 1);
                cur.fi = (cur.fi * ((double) range) + temp.fi * ((double) range2)) / ((double) (range + range2));
                cur.se.fi = temp.se.fi;
            }
        } else{
            st.push(cur);
            cur = mp((double) ar[i], mp(i, i));
        }
    }
    st.push(cur);
    vector<double> ans;
    while (!st.empty()){
        auto temp = st.top();
        st.pop();
        for (int i=temp.se.fi;i<=temp.se.se;i++){
            ans.pb(temp.fi);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans){
        cout << x << el;
    }

    return 0;
}
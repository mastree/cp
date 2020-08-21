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

const int N = 1e5 + 7;
int n, m;
int ar[N];
int cnt[N];
int sqr;

vector <pair<pii, int>> query;
int ans[N];

bool comp(pair<pii, int> a, pair<pii, int> b){
    a.fi.fi = (a.fi.fi - 1) / sqr;
    b.fi.fi = (b.fi.fi - 1) / sqr;
    return a.fi < b.fi;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    sqr = sqrt(n);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
        if (ar[i] > n) ar[i] = N-1;
    }

    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        query.pb(mp(mp(a, b), i));
    }

    sort(query.begin(), query.end(), comp);

    int l = 1, r = 0;
    int cur = 0;
    for (auto x : query){
        pii q = x.fi;
        while (r < q.se){
            r++;
            if (cnt[ar[r]] == ar[r]) cur--;
            cnt[ar[r]]++;
            if (cnt[ar[r]] == ar[r]) cur++;
        }
        while (r > q.se){
            if (cnt[ar[r]] == ar[r]) cur--;
            cnt[ar[r]]--;
            if (cnt[ar[r]] == ar[r]) cur++;
            r--;
        }
        while (l < q.fi){
            if (cnt[ar[l]] == ar[l]) cur--;
            cnt[ar[l]]--;
            if (cnt[ar[l]] == ar[l]) cur++;
            l++;
        }
        while (l > q.fi){
            l--;
            if (cnt[ar[l]] == ar[l]) cur--;
            cnt[ar[l]]++;
            if (cnt[ar[l]] == ar[l]) cur++;
        }
        ans[x.se] = cur;
    }
    for (int i=1;i<=m;i++){
        cout << ans[i] << el;
    }

    return 0;
}
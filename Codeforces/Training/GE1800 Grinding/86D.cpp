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

const int N = 2e5 + 7;
int n, t;
ll ar[N];
int sqsz, sz;
vector <pair<pii, int>> q;
ll cek[N * 5];
ll cur, ans[N];
int curl=1, curr;

bool cmp(pair<pii, int> el1, pair<pii, int> el2){
    pii a = el1.fi;
    pii b = el2.fi;

    a.fi = (a.fi-1)/sqsz;
    b.fi = (b.fi-1)/sqsz;
    return a < b;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    sz = n;
    sqsz = sqrt(sz);

    for (int i=1;i<=t;i++){
        int l, r;
        cin >> l >> r;
        q.pb(mp(mp(l, r), i));
    }

    sort(q.begin(), q.end(), cmp);
    for (auto query : q){
        pii range = query.fi;
        if (curr<=range.se){
            while (curr<range.se){
                curr++;
                ll temp = cek[ar[curr]]++;
                cur += (temp + temp + 1) * ar[curr];
            }
        } else{
            while (curr>range.se){
                ll temp = cek[ar[curr]]--;
                cur += (- temp - temp + 1) * ar[curr];
                curr--;
            }
        }
        if (curl<=range.fi){
            while (curl<range.fi){
                ll temp = cek[ar[curl]]--;
                cur += (- temp - temp + 1) * ar[curl];
                curl++;
            }
        } else{
            while (curl>range.fi){
                curl--;
                ll temp = cek[ar[curl]]++;
                cur += (temp + temp + 1) * ar[curl];
            }
        }

        ans[query.se] = cur;
    }

    for (int i=1;i<=t;i++){
        cout << ans[i] << el;
    }

    return 0;
}
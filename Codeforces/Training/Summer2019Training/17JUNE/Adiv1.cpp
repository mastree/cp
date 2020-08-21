#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

int n;
vector <int> hand,pile;
//bool cekhand[100003],cekpile[100003];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int cnt[n+1];
    for (int i=0;i<=n;i++) cnt[i]=0;
    for (int i=0;i<n;i++){
        int tm;cin >> tm;
        hand.pb(tm);
    //    cekhand[tm]=1;
        cnt[tm]++;
    }

    for (int i=0;i<n;i++){
        int tm;cin >> tm;
        pile.pb(tm);
    //    cekpile[tm]=1;
    }

    queue <int> qu;
    for (auto x : pile){
        qu.push(x);
    }

    int run=0,ar[n+1];
    for (int i=0;i<=n;i++) ar[i]=cnt[i];
    while (ar[0]>0){
        qu.push(0);
        ar[0]--;
        ar[qu.front()]++;
        qu.pop();
        run++;
    }

    //cerr << run << el;

    int low=0,high=run+n;
    while (low<high){
        queue <int> q;
        for (int i=0;i<=n;i++) ar[i]=cnt[i];
        for (auto x : pile) q.push(x);

        int mid=(low+high)/2;
        bool bisa=1;

        if (mid>=n){
            for (int i=0;i<mid-n;i++){
                q.push(0);
                ar[0]--;
                ar[q.front()]++;
                q.pop();
            }

            for (int i=1;i<=n;i++){
                if (ar[i]>0){
                    q.push(i);
                } else {
                    bisa=0;
                    break;
                }
                ar[q.front()]++;
                q.pop();
            }
        } else {
            for (int i=n-mid+1;i<=n;i++){
                if (ar[i]>0){
                    q.push(i);
                } else {
                    bisa=0;
                    break;
                }
                ar[q.front()]++;
                q.pop();
            }
            if (bisa){
                for (int i=1;i<=n;i++) {
                    if (q.front()!=i){
                        bisa=0;break;
                    }
                    q.pop();
                }
            }
        }

    //    cerr << mid << " " << bisa << el;
        if (bisa){
            high=mid;
        } else low=mid+1;

    }

    if (pile[n-1]!=0){
        int alr=pile[n-1];
        bool mungkin=1;
        for (int i=n-alr;i<n;i++){
            if (pile[i]!=i-n+alr+1){
                mungkin=0;
                break;
            }
        }
        
        if (mungkin){
            queue<int> q;
            for (auto x : pile) q.push(x);

            for (int i=0;i<=n;i++) ar[i]=cnt[i];

            for (int i=alr+1;i<=n;i++){
                if (ar[i]>0){
                    q.push(i);
                } else{
                    mungkin=0;
                    break;
                }
                ar[q.front()]++;
                q.pop();
            }
        }

        if (mungkin){
            high=min(high,n-alr);
        }

    }

    cout << high << el;

    return 0;
}
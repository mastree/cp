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

ll n,ar[100005],back;
string num;

vector <ll> sol(ll a){
    ll mid=n/2;
//    cerr << a << el;
    vector <ll> res;
    if (a<mid){
        for (ll i=a+1;i<n;i++){
            res.pb(ar[i]);
        }

        for (ll i=0;i<=a;i++){
            res[i]+=ar[i];
        }
    } else{
        for (ll i=0;i<=a;i++){
            res.pb(ar[i]);
        } 
        for (ll i=a+1;i<n;i++){
            res[i-a-1]+=ar[i];
        }
    }

    ll len=res.size();
    ll tm=0;
    for (ll i=0;i<len;i++){
        res[i]+=tm;
        tm=res[i]/10;
        res[i]%=10;
    }
    if (tm>0){
        res.pb(tm);
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> num;

    for (ll i=0;i<n;i++){
        ar[n-i-1]=(ll)int(num[i]-'0');
    }

 //   for (ll i=n-1;i>=0;i--) cerr << ar[i];

    if (n%2){
        ll mid=n/2;
        ll ba=-1;
        for (ll i=0;i<mid;i++){
            if (ar[i]!=0) ba=i;
        }
        ll bb=n;
        for (ll i=n-2;i>=mid;i--){
            if (ar[i]!=0) bb=i;
        }

        if (ba+1>n-bb-1){
            vector <ll> ans=sol(ba);
            ll len=ans.size();
            for (ll i=len-1;i>=0;i--){
                cout << ans[i];
            }
            cout << el;
        } else if (ba+1<n-bb-1){
            vector <ll> ans=sol(bb);
            ll len=ans.size();
            for (ll i=len-1;i>=0;i--){
                cout << ans[i];
            }
            cout << el;
        } else{
            vector<ll> ans1=sol(ba),ans2=sol(bb);
            ll len1=ans1.size(),len2=ans2.size();

            if (len1>len2){
                for (ll i=len1-1;i>=0;i--) cout << ans1[i];
                cout << el;
            } else if (len2>len1){
                for (ll i=len2-1;i>=0;i--) cout << ans2[i];
                cout << el;
            } else {
                for (ll i=len1-1;i>=0;i--){
                    if (ans1[i]<ans2[i]){
                        for (ll i=len1-1;i>=0;i--){
                            cout << ans1[i];
                        }
                        cout << el;
                        return 0;
                    } else if (ans1[i]>ans2[i]){
                        for (ll i=len2-1;i>=0;i--){
                            cout << ans2[i];
                        }
                        cout << el;
                        return 0;
                    }
                }
            }
        }

    } else{
        ll mid=n/2;
        ll ba=-1;
        for (ll i=0;i<mid;i++){
            if (ar[i]!=0) ba=i;
        }
        ll bb=n;
        for (ll i=n-2;i>=mid;i--){
            if (ar[i]!=0) bb=i;
        }

        if (ba+1>n-bb-1){
            vector <ll> ans=sol(ba);
            ll len=ans.size();
            for (ll i=len-1;i>=0;i--){
                cout << ans[i];
            }
            cout << el;
        } else if (ba+1<n-bb-1){
            vector <ll> ans=sol(bb);
            ll len=ans.size();
            for (ll i=len-1;i>=0;i--){
                cout << ans[i];
            }
            cout << el;
        } else{
            vector<ll> ans1=sol(ba),ans2=sol(bb);
            ll len1=ans1.size(),len2=ans2.size();

            if (len1>len2){
                for (ll i=len1-1;i>=0;i--) cout << ans1[i];
                cout << el;
            } else if (len2>len1){
                for (ll i=len2-1;i>=0;i--) cout << ans2[i];
                cout << el;
            } else {
                for (ll i=len1-1;i>=0;i--){
                    if (ans1[i]<ans2[i]){
                        for (ll i=len1-1;i>=0;i--){
                            cout << ans1[i];
                        }
                        cout << el;
                        return 0;
                    } else if (ans1[i]>ans2[i]){
                        for (ll i=len2-1;i>=0;i--){
                            cout << ans2[i];
                        }
                        cout << el;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
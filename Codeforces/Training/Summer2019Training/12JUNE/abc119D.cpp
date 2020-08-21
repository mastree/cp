#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 90000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

int a,b,q;
ll s[100005],t[100005];

int lows(ll tar){
    int low=0,high=a+1;

    while (low<high){
        int mid=(low+high+1)/2;

        if (s[mid]<=tar) low=mid;
        else high=mid-1; 
    }

    return low;
}

int lowt(ll tar){
    int low=0,high=b+1;

    while (low<high){
        int mid=(low+high+1)/2;

        if (t[mid]<=tar) low=mid;
        else high=mid-1; 
    }

    return low;
}

int his(ll tar){
    int low=0,high=a+1;

    while (low<high){
        int mid=(low+high)/2;

        if (s[mid]>=tar) high=mid;
        else low=mid+1; 
    }

    return high;
}

int hit(ll tar){
    int low=0,high=b+1;

    while (low<high){
        int mid=(low+high)/2;

        if (t[mid]>=tar) high=mid;
        else low=mid+1; 
    }

    return high;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> q;

    for (int i=1;i<=a;i++){
        cin >> s[i];
    }

    for (int i=1;i<=b;i++){
        cin >> t[i];
    }
    s[0]=-MOD;t[0]=-MOD;
    s[a+1]=MOD;t[b+1]=MOD;

    while (q--){
        ll query;
        cin >> query;

        int sa=lows(query),sb=his(query);
        int ta=lowt(query),tb=hit(query);

        ll ans=max(s[sb],t[tb])-query;
        ans=min(ans,query-min(s[sa],t[ta]));
        ans=min(ans,s[sb]-t[ta]+min(s[sb]-query,query-t[ta]));
        ans=min(ans,t[tb]-s[sa]+min(t[tb]-query,query-s[sa]));

        cout << ans << el;
    }

    return 0;
}
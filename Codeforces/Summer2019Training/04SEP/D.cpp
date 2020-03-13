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

int par[100],sz[100],n,cnt[100];
ll ar[100100],pc[62];

int find(int a){
    if (par[a]==a) return a;
    else return (par[a] = find(par[a]));
}

void make(int a,int b){
    a=find(a);
    b=find(b);
    if (a==b) return;

    if (sz[a]<sz[b]) swap(a,b);

    sz[a]+=sz[b];
    par[b]=a;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<61;i++){
        pc[i]=((ll)1 << i);
        par[i]=i;
        sz[i]=1;
    }

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ar[i];
        vector <int> vid;
        for (int j=0;j<61;j++){
            if ((ar[i]&pc[j])>0){
                vid.pb(j);
                cerr << j << " ";
            }
        }cerr << el;

        int len=vid.size();
        for (int j=0;j<len-1;j++){
            make(vid[j],vid[j+1]);
        }
    }

    for (int i=0;i<n;i++){
        if (ar[i]==0) continue;
        ll lsb=(ar[i]&(-ar[i]));
        ll id=log2(lsb);
        int a=(int)id;
        a=find(a);
        cerr << a << " ";
        cnt[a]++;
    }cerr << el;

    int ans=0;
    for (int i=0;i<61;i++){
        int a=find(i);
        ans=max(ans,cnt[a]); 
    }

    if (ans<=1) cout << -1 << el;
    else cout << ans << el;

    return 0;
}
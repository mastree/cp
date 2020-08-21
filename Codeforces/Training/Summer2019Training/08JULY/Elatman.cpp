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
ll in[100010];
ll ar[100010][20];
ll bitup[20];
ll stree[500000][20];
ll lazy[500000][20];
//bool laz[500000];
ll ans[20];

void constree(int low,int high,int pos){
    if (low==high){
        for (int i=0;i<20;i++){
            stree[pos][i]=ar[low][i];
        }
        
        return;
    }

    int mid=(low+high)/2,left=pos+pos+1;
    constree(low,mid,left);
    constree(mid+1,high,left+1);

    for (int i=0;i<20;i++){
        stree[pos][i]=stree[left][i]+stree[left+1][i];
    }
}

void upd(int low,int high,int ulow,int uhigh,int pos){
    if (low>=ulow && high<=uhigh){
        ll cnt=(ll)(high-low+1);
        for (int i=0;i<20;i++){
            if (bitup[i]==0) stree[pos][i]=cnt-stree[pos][i];
        }

        if (low<high){
            int left=pos+pos+1;

            for (int i=0;i<20;i++){
                lazy[left][i]=bitup[i];
                lazy[left+1][i]=bitup[i];
            }
        }
        return;
    }

    if (high<ulow || low>uhigh) return;

    int mid=(low+high)/2,left=pos+pos+1;

    upd(low,mid,ulow,uhigh,left);
    upd(mid+1,high,ulow,uhigh,left+1);

    for (int i=0;i<20;i++){
        stree[pos][i]=stree[left][i]+stree[left+1][i];
    }
}

void ask(int low,int high,int qlow,int qhigh,int pos){
    if (low>qhigh || high<qlow) return;

    int mid=(low+high)/2,left=pos+pos+1;
    ll len=(ll)(high-low+1);
    
    for (int i=0;i<20;i++){
        if (lazy[pos][i]){
            stree[pos][i]=len-stree[pos][i];
        }
        
        if (low!=high){
            lazy[left][i]=(lazy[pos][i]^lazy[left][i]);
            lazy[left+1][i]=(lazy[pos][i]^lazy[left+1][i]);
        }lazy[pos][i]=0;
    }
    
    if (low>=qlow && high<=qhigh){
        for (int i=0;i<20;i++){
            ans[i]+=stree[pos][i];
        }
        return;
    }

    ask(low,mid,qlow,qhigh,left);
    ask(mid+1,high,qlow,qhigh,left+1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++) cin >> in[i];
    for (int i=1;i<=n;i++){
        for (int bit=0;bit<20;bit++){
            ll tm=((ll)1 << bit);
            if ((tm&in[i])>0){
                ar[i][bit]=1;
            }
        }
    }

    int q;
    cin >> q;

    constree(1,n,0);

    while(q--){
        int tipe,l,r;
        cin >> tipe >> l >> r;

        if (tipe==1){
            for (int i=0;i<20;i++){
                ans[i]=0;
            }

            ask(1,n,l,r,0);
            ll tot=0;
            for (int i=0;i<20;i++){
                tot+=ans[i]*((ll)1 << i);
            }
            cout << tot << el;

        } else {
            ll x;
            cin >> x;

            for (int i=0;i<20;i++){
                ll tm=((ll)1 << i);
                if ((tm|x)==x) bitup[i]=1;
                else bitup[i]=0;
            }

            upd(1,n,l,r,0);
        }
         
        for (int i=0;i<20;i++) ans[i]=0;
        ask(1,n,3,3,0);
        ll total=0;
        for (int i=0;i<20;i++) total+=ans[i]*((ll)1 << i); 
        cerr << q << " " << total << el;
        
    }

    return 0;
}
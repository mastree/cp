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

struct Trie{
    struct Node{
        Node * child[26];
        bool dp[2];

        Node(){
            for (int i=0;i<26;i++){
                child[i] = 0;
            }
            dp[0] = dp[1] = 0;
        }
    };

    Node * head;
    string s;
    Trie(){
        head = new Node();
    }

    void insert(){
        Node * cur = head;
        dfs(cur, 0);
    }
    void dfs(Node * node, int dep){
        if (dep < s.length()){
            int dig = s[dep] - 'a';
            if (node -> child[dig] == 0){
                node -> child[dig] = new Node();
            }
            dfs(node -> child[dig], dep+1);
            node -> dp[0] = node -> dp[1] = 0;
            for (int i=0;i<26;i++){
                if (node -> child[i] != 0){
                    node -> dp[0] = (node -> dp[0] || !(node -> child[i] -> dp[0]));
                    node -> dp[1] = (node -> dp[1] || !(node -> child[i] -> dp[1]));
                }
            }
        } else{
            bool ada = 0;
            for (int i=0;i<26;i++){
                if (node -> child[i] != 0){
                    ada = 1;
                }
            }
            if (!ada){
                node -> dp[0] = 1;
            }
        }
    }
};

int n, k;
Trie trie;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> trie.s;
        trie.insert();
    }
    if (trie.head -> dp[0] && trie.head -> dp[1]){
        cout << "First" << el;
        return 0;
    }
    if (trie.head -> dp[1]){
        if (k&1){
            cout << "First" << el;
        } else{
            cout << "Second" << el;
        }
        return 0;
    }
    cout << "Second" << el;

    return 0;
}
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 17;
const int MR = (1 << N);

struct Trie {
    struct Node {
        int level = 0;
        Node* child[2];

        Node() {
            child[0] = child[1] = 0;
        }
        Node(int level) : level(level) {
            child[0] = child[1] = 0;
        }
    };
    vector<int> maxbit;
    Node* head;

    Trie() {
        maxbit = vector<int>(N, 1);
        head = new Node();
    }
    void insert(int x) {
        Node* cur = head;
        for (int i = N - 1; i >= 0; i--) {
            bool on = (x & (1 << i));
            if (!cur->child[on]) cur->child[on] = new Node(cur->level + 1);
            cur = cur->child[on];
        }
    }
    void flip(int bit) {
        maxbit[N - bit - 1] ^= 1;
    }
    int getMax() {
        Node* cur = head;
        int ret = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (cur->child[maxbit[cur->level]]) {
                ret += (1 << i);
                cur = cur->child[maxbit[cur->level]];
            } else {
                cur = cur->child[!maxbit[cur->level]];
            }
        }
        return ret;
    }
    int getMin() {
        Node* cur = head;
        int ret = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (cur->child[!maxbit[cur->level]]) {
                cur = cur->child[!maxbit[cur->level]];
            } else {
                ret += (1 << i);
                cur = cur->child[maxbit[cur->level]];
            }
        }
        return ret;
    }
};

void solve() {
    int l, r;
    cin >> l >> r;
    vector<int> vec;
    for (int i = l; i <= r; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    int n = r - l + 1;
    if (n & 1) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans ^= vec[i];
            ans ^= i + l;
        }
        cout << ans << '\n';
    } else {
        vector<int> cnt(N, 0), ccnt(N, 0);
        for (int i = l; i <= r; i++) {
            int id = i - l;
            for (int j = 0; j < N; j++) {
                if (i & (1 << j)) cnt[j]++;
                if (vec[id] & (1 << j)) ccnt[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            // assert(cnt[i] == ccnt[i] || cnt[i] == n - ccnt[i]);
            if (cnt[i] != ccnt[i] && cnt[i] == n - ccnt[i]) ans += (1 << i);
        }
        Trie trie;
        for (auto& x : vec) {
            trie.insert(x ^ ans);
        }
        for (int i = N - 1; i >= 0; i--) {
            int bit = (1 << i);
            if (cnt[i] == ccnt[i]) {
                int curmax = trie.getMax();
                int curmin = trie.getMin();
                if ((curmax & bit) != (r & bit) || (curmin & bit) != (l & bit)) {
                    trie.flip(i);
                    ans ^= bit;
                }
            }
        }
        cout << ans << '\n';
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        solve();
    }

    return 0;
}
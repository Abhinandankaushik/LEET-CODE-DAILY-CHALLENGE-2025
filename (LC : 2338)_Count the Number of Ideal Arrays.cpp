#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define all(a) a.begin(),a.end()
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

const int MOD = 1e9 + 7;
const int iinf = 1e9;
const int mxn = 4e4 + 10;

ll mod_m(ll a, ll b) {
    a %= MOD; b %= MOD;
    return (a * b) % MOD;
}

ll pow_m(ll a, ll b) {
    a %= MOD; b %= (MOD - 1); // Fermat's little theorem
    ll r = 1;
    while (b) {
        if (b & 1) r = mod_m(r, a);
        a = mod_m(a, a);
        b /= 2;
    }
    return r;
}

ll mod_i(ll a) { return pow_m(a, MOD - 2); }

int fact[mxn], ifact[mxn];
int flag = 0;

void init() {
    if (flag) return;
    flag = 1;
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < mxn; i++) {
        fact[i] = mod_m(fact[i - 1], i * 1ll);
    }
    ifact[mxn - 1] = mod_i(fact[mxn - 1]);
    for (int i = mxn - 2; i >= 0; i--) {
        ifact[i] = mod_m(ifact[i + 1], (i + 1) * 1ll);
    }
}

ll NCR(int n, int r) {
    if (r < 0 || r > n) return 0;
    return mod_m(fact[n], mod_m(ifact[r], ifact[n - r]));
}

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        init();
        int maxStep = log2(maxValue) + 2;
        vi lcnt(maxStep + 1, 0), p(maxValue + 1, 1), c(maxValue + 1, 0);
        lcnt[1] = maxValue;
        p[0] = p[1] = 0;

        for (int step = 2; step <= maxStep; step++) {
            for (int j = 1; j <= maxValue; j++) {
                for (int k = 2 * j; k <= maxValue; k += j) {
                    c[j] = (c[j] + p[k]) % MOD;
                }
            }
            ll len = 0;
            for (int j = 0; j <= maxValue; j++) {
                p[j] = c[j];
                len = (len + c[j]) % MOD;
                c[j] = 0;
            }
            lcnt[step] = len;
        }

        int ans = 0;
        for (int i = 1; i <= min(n, maxStep); i++) {
            ans = (ans + mod_m(lcnt[i], NCR(n - 1, i - 1))) % MOD;
        }

        return ans;
    }
};

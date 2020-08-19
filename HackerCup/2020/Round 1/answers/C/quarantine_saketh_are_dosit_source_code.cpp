#include <bits/stdc++.h>
using namespace std;

// template {{{
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)

#define sort_by(x, y) sort(all(x), [&](const auto& a, const auto& b) { return y; })

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;

using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#define TRACE(x) x
#define __pn(x) pr(#x, " = ")
#define pd(...) __pn((__VA_ARGS__)), ps(__VA_ARGS__), cout << flush

namespace __algorithm {
    template<typename T> void dedup(vector<T>& v) {
        sort(all(v)); v.erase(unique(all(v)), v.end());
    }
    template<typename T> typename vector<T>::const_iterator find(const vector<T>& v, const T& x) {
        auto it = lower_bound(all(v), x); return it != v.end() && *it == x ? it : v.end();
    }
    template<typename T> size_t index(const vector<T>& v, const T& x) {
        auto it = find(v, x); assert(it != v.end() && *it == x); return it - v.begin();
    }

    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator lower_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return lower_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
    template<typename T1, typename T2> typename vector<pair<T1, T2>>::iterator upper_bound(
            const vector<pair<T1, T2>>& v, const T1& x) {
        return upper_bound(all(v), x, [](pair<T1, T2> a, pair<T1, T2> b) { return a.f < b.f; });
    }
}
using namespace __algorithm;

struct __monostate {
    friend istream& operator>>(istream& is, const __attribute__((unused))__monostate& ms) { return is; }
    friend ostream& operator<<(ostream& os, const __attribute__((unused))__monostate& ms) { return os; }
} ms;

namespace __io {
    void setIn(string s) { freopen(s.c_str(),"r",stdin); }
    void setOut(string s) { freopen(s.c_str(),"w",stdout); }
    void setIO(string s = "") {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cout << setprecision(15);
        if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
    }
}
using namespace __io;
// }}}

// union_find {{{
struct union_find {
    struct node {
        int par, rnk, size;
        node(int id = 0) : par(id), rnk(0), size(1) {}
    };

    vector<node> uf;
    union_find(int N = 0) : uf(N) {
        for (int i = 0; i < N; i++)
            uf[i] = node(i);
    }

    int rep(int i) {
        if (i != uf[i].par)
            uf[i].par = rep(uf[i].par);
        return uf[i].par;
    }

    bool unio(int a, int b) {
        a = rep(a), b = rep(b);
        if (a == b) return false;
        if (uf[a].rnk < uf[b].rnk) swap(a, b);
        uf[b].par = a;
        uf[a].size += uf[b].size;
        if (uf[a].rnk == uf[b].rnk) uf[a].rnk++;
        return true;
    }

    node& operator[](int i) { return uf[rep(i)]; }

    friend void pr(const union_find& u) {
        pr("{"); bool f = 1;
        for (int i = 0; i < sz(u.uf); i++) if (u.uf[i].par == i) {
            if (!f) pr(", "); else f = 0;
            pr("[ ", i, " | rank=", u.uf[i].rnk, " size=", u.uf[i].size, " ]");
        }
        pr("}");
    }
};
// }}}

ll nc2(int n) { return ll(n) * (n - 1) / 2; }

void solve() {
    int N, K; re(N, K);
    string s; re(s);

    vi parent(N);
    FOR (i, 1, K + 1) re(parent[i]);

    int A, B, C; re(A, B, C);
    FOR (i, K + 1, N) {
        parent[i] = (ll(A) * parent[i - 2] + ll(B) * parent[i - 1] + C) % i + 1;
    }

    trav (e, parent) --e;

    vvi children(N);
    FOR (i, 1, N) children[parent[i]].pb(i);

    union_find uf(N);
    FOR (i, 1, N) {
        if (s[i] == '*' && s[parent[i]] == '*')
            uf.unio(i, parent[i]);
    }

    vi comps;
    F0R (i, N) if (s[i] == '*' && uf.rep(i) == i) comps.pb(uf[i].size);

    vi SUBT_SZ(N, 1);
    FORd (i, 1, N) SUBT_SZ[parent[i]] += SUBT_SZ[i];

    if (sz(comps) <= 1) { // all the uninfected can already reach each other
        vi subt_sz(N);
        F0Rd (i, N) {
            if (s[i] == '*') subt_sz[i]++;
            if (i > 0) subt_sz[parent[i]] += subt_sz[i];
        }

        ll pairs = comps.empty() ? 0 : nc2(comps[0]);

        ll ways = 0;
        FOR (i, 1, N) {
            if (s[i] == '*' && s[parent[i]] == '*') {
                // need to reconnect the uninfected
                ways += subt_sz[i] * ll(comps[0] - subt_sz[i]);
            } else {
                // put it anywhere reconnecting the original tree
                ways += SUBT_SZ[i] * ll(N - SUBT_SZ[i]);
            }
        }

        ps(pairs, ways);
    } else {
        ll pairs = 0;
        trav (c, comps) pairs += nc2(c);

        sort(all(comps), greater<int>());
        pairs += ll(comps[0]) * comps[1];

        auto sum = [](pii a, pii b) {
            return (a.f == b.f) ? mp(a.f, a.s + b.s) : a.f > b.f ? a : b;
        };

        vpii at(N);
        F0R (i, N) if (s[i] == '*' && uf.rep(i) == i) at[i] = mp(uf[i].size, 1);

        vpii down(N);
        F0Rd (i, N) {
            down[i] = sum(down[i], at[i]);
            down[parent[i]] = sum(down[parent[i]], down[i]);
        }

        vpii up(N);
        F0R (i, N) {
            int CC = sz(children[i]);

            vpii prefixes(CC + 1);
            F0R (c, CC)
                prefixes[c+1] = sum(prefixes[c], down[children[i][c]]);

            vpii suffixes(CC + 1);
            F0Rd (c, CC)
                suffixes[c] = sum(suffixes[c + 1], down[children[i][c]]);

            F0R (c, CC) {
                up[children[i][c]] = sum(sum(up[i], at[i]), sum(prefixes[c], suffixes[c + 1]));
            }
        }

        ll ways = 0;

        FOR (i, 1, N) {
            if (s[i] == '*' && s[parent[i]] == '*') continue; // must disconnect useless one
            if ((down[i].f == comps[0] && up[i].f == comps[1]) ||
                (down[i].f == comps[1] && up[i].f == comps[0])) {
                ways += ll(down[i].f * down[i].s) * (up[i].f * up[i].s);
            }
        }

        ps(pairs, ways);
    }
}

int main() {
    setIO();

    int T; re(T); F0R (t, T) {
        pr("Case #", t+1, ": ");
        solve();
    }

    return 0;
}

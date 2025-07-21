```cpp
namespace Geometry {
using T = ll;
constexpr T eps = 0;
 
bool eq(const T &x, const T &y) { return abs(x - y) <= eps; }
inline constexpr int type(T x, T y) {
    if(x == 0 and y == 0) return 0;
    if(y < 0 or (y == 0 and x > 0)) return -1;
    return 1;
}
struct Point {
    T x, y;
    constexpr Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    constexpr Point operator+() const noexcept { return *this; }
    constexpr Point operator-() const noexcept { return Point(-x, -y); }
    constexpr Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    constexpr Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    constexpr Point &operator+=(const Point &p) { return x += p.x, y += p.y, *this; }
    constexpr Point &operator-=(const Point &p) { return x -= p.x, y -= p.y, *this; }
    constexpr T operator*(const Point &p) const { return x * p.x + y * p.y; }
    constexpr Point &operator*=(const T &k) { return x *= k, y *= k, *this; }
    constexpr Point operator*(const T &k) { return Point(x * k, y * k); }
    constexpr bool operator==(const Point &r) const noexcept { return r.x == x and r.y == y; }
    constexpr T cross(const Point &r) const { return x * r.y - y * r.x; }
 
    constexpr bool operator<(const Point &r) const { return pair(x, y) < pair(r.x, r.y); }
 
    // 1 : left, 0 : same, -1 : right
    constexpr int toleft(const Point &r) const {
        auto t = cross(r);
        return t > eps ? 1 : t < -eps ? -1 : 0;
    }
 
    constexpr bool arg_cmp(const Point &r) const {
        int L = type(x, y), R = type(r.x, r.y);
        if(L != R) return L < R;
 
        T X = x * r.y, Y = r.x * y;
        if(X != Y) return X > Y;
        return x < r.x;
    }
};
bool arg_cmp(const Point &l, const Point &r) { return l.arg_cmp(r); }
ostream &operator<<(ostream &os, const Point &p) { return os << p.x << " " << p.y; }
istream &operator>>(istream &is, Point &p) {
    is >> p.x >> p.y;
    return is;
}
 
struct Line {
    Point a, b;
    Line() = default;
    Line(Point a, Point b) : a(a), b(b) {}
    // ax + by = c
    Line(T A, T B, T C) {
        if(A == 0) {
            a = Point(0, C / B), b = Point(1, C / B);
        } else if(B == 0) {
            a = Point(C / A, 0), b = Point(C / A, 1);
        } else {
            a = Point(0, C / B), b = Point(C / A, 0);
        }
    }
    // 1 : left, 0 : same, -1 : right
    constexpr int toleft(const Point &r) const {
        auto t = (b - a).cross(r - a);
        return t > eps ? 1 : t < -eps ? -1 : 0;
    }
 
    friend std::ostream &operator<<(std::ostream &os, Line &ls) {
        return os << "{"
                  << "(" << ls.a.x << ", " << ls.a.y << "), (" << ls.b.x << ", " << ls.b.y << ")}";
    }
};
istream &operator>>(istream &is, Line &p) { return is >> p.a >> p.b; }
 
struct Segment : Line {
    Segment() = default;
    Segment(Point a, Point b) : Line(a, b) {}
};
 
ostream &operator<<(ostream &os, Segment &p) { return os << p.a << " to " << p.b; }
istream &operator>>(istream &is, Segment &p) {
    is >> p.a >> p.b;
    return is;
}
 
struct Circle {
    Point p;
    T r;
    Circle() = default;
    Circle(Point p, T r) : p(p), r(r) {}
};
 
using pt = Point;
using Points = vector<pt>;
using Polygon = Points;
T cross(const pt &x, const pt &y) { return x.x * y.y - x.y * y.x; }
T dot(const pt &x, const pt &y) { return x.x * y.x + x.y * y.y; }
 
T abs2(const pt &x) { return dot(x, x); }
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
// 点の回転方向
int ccw(const Point &a, Point b, Point c) {
    b = b - a, c = c - a;
    if(cross(b, c) > 0) return +1;   // "COUNTER_CLOCKWISE"
    if(cross(b, c) < 0) return -1;   // "CLOCKWISE"
    if(dot(b, c) < 0) return +2;     // "ONLINE_BACK"
    if(abs2(b) < abs2(c)) return -2; // "ONLINE_FRONT"
    return 0;                        // "ON_SEGMENT"
}
 
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
// 平行判定
bool parallel(const Line &a, const Line &b) { return (cross(a.b - a.a, b.b - b.a) == 0); }
 
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A
// 垂直判定
bool orthogonal(const Line &a, const Line &b) { return (dot(a.a - a.b, b.a - b.b) == 0); }
 
bool intersect(const Line &l, const Point &p) { return abs(ccw(l.a, l.b, p)) != 1; }
 
bool intersect(const Line &l, const Line &m) { return !parallel(l, m); }
 
bool intersect(const Segment &s, const Point &p) { return ccw(s.a, s.b, p) == 0; }
 
bool intersect(const Line &l, const Segment &s) { return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) <= 0; }
 
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B
bool intersect(const Segment &s, const Segment &t) { return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0; }
 
bool intersect(const Polygon &ps, const Polygon &qs) {
    int pl = si(ps), ql = si(qs), i = 0, j = 0;
    while((i < pl or j < ql) and (i < 2 * pl) and (j < 2 * ql)) {
        auto ps0 = ps[(i + pl - 1) % pl], ps1 = ps[i % pl];
        auto qs0 = qs[(j + ql - 1) % ql], qs1 = qs[j % ql];
        if(intersect(Segment(ps0, ps1), Segment(qs0, qs1))) return true;
        Point a = ps1 - ps0;
        Point b = qs1 - qs0;
        T v = cross(a, b);
        T va = cross(qs1 - qs0, ps1 - qs0);
        T vb = cross(ps1 - ps0, qs1 - ps0);
 
        if(!v and va < 0 and vb < 0) return false;
        if(!v and !va and !vb) {
            i += 1;
        } else if(v >= 0) {
            if(vb > 0)
                i += 1;
            else
                j += 1;
        } else {
            if(va > 0)
                j += 1;
            else
                i += 1;
        }
    }
    return false;
}
 
T norm(const Point &p) { return p.x * p.x + p.y * p.y; }
Point projection(const Segment &l, const Point &p) {
    T t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}
 
Point crosspoint(const Line &l, const Line &m) {
    T A = cross(l.b - l.a, m.b - m.a);
    T B = cross(l.b - l.a, l.b - m.a);
    if(A == 0 and B == 0) return m.a;
    return m.a + (m.b - m.a) * (B / A);
}
 
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
Point crosspoint(const Segment &l, const Segment &m) { return crosspoint(Line(l), Line(m)); }
 
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B
// 凸性判定
bool is_convex(const Points &p) {
    int n = (int)p.size();
    for(int i = 0; i < n; i++) {
        if(ccw(p[(i + n - 1) % n], p[i], p[(i + 1) % n]) == -1) return false;
    }
    return true;
}
 
Points convex_hull(Points p) {
    int n = p.size(), k = 0;
    if(n <= 2) return p;
    sort(begin(p), end(p), [](pt x, pt y) { return (x.x != y.x ? x.x < y.x : x.y < y.y); });
    Points ch(2 * n);
    for(int i = 0; i < n; ch[k++] = p[i++]) {
        while(k >= 2 && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) <= 0) --k;
    }
    for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
        while(k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) <= 0) --k;
    }
    ch.resize(k - 1);
    return ch;
}
 
// 面積の 2 倍
T area2(const Points &p) {
    T res = 0;
    rep(i, si(p)) { res += cross(p[i], p[i == si(p) - 1 ? 0 : i + 1]); }
    return res;
}
 
enum { _OUT, _ON, _IN };
 
int contains(const Polygon &Q, const Point &p) {
    bool in = false;
    for(int i = 0; i < Q.size(); i++) {
        Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;
        if(a.y > b.y) swap(a, b);
        if(a.y <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;
        if(cross(a, b) == 0 && dot(a, b) <= 0) return _ON;
    }
    return in ? _IN : _OUT;
}
 
Polygon Minkowski_sum(const Polygon &P, const Polygon &Q) {
    vector<Segment> e1(P.size()), e2(Q.size()), ed(P.size() + Q.size());
    const auto cmp = [](const Segment &u, const Segment &v) { return (u.b - u.a).arg_cmp(v.b - v.a); };
    rep(i, P.size()) e1[i] = {P[i], P[(i + 1) % P.size()]};
    rep(i, Q.size()) e2[i] = {Q[i], Q[(i + 1) % Q.size()]};
    rotate(begin(e1), min_element(all(e1), cmp), end(e1));
    rotate(begin(e2), min_element(all(e2), cmp), end(e2));
    merge(all(e1), all(e2), begin(ed), cmp);
    const auto check = [](const Points &res, const Point &u) {
        const auto back1 = res.back(), back2 = *prev(end(res), 2);
        return eq(cross(back1 - back2, u - back2), eps) and dot(back1 - back2, u - back1) >= -eps;
    };
    auto u = e1[0].a + e2[0].a;
    Points res{u};
    res.reserve(P.size() + Q.size());
    for(const auto &v : ed) {
        u = u + v.b - v.a;
        while(si(res) >= 2 and check(res, u)) res.pop_back();
        res.eb(u);
    }
    if(res.size() and check(res, res[0])) res.pop_back();
    return res;
}
 
// -1 : on, 0 : out, 1 : in
// O(log(n))
int is_in(const Polygon &p, const Point &a) {
    if(p.size() == 1) return a == p[0] ? -1 : 0;
    if(p.size() == 2) return intersect(Segment(p[0], p[1]), a);
    if(a == p[0]) return -1;
    if((p[1] - p[0]).toleft(a - p[0]) == -1 || (p.back() - p[0]).toleft(a - p[0]) == 1) return 0;
    const auto cmp = [&](const Point &u, const Point &v) { return (u - p[0]).toleft(v - p[0]) == 1; };
    const size_t i = lower_bound(p.begin() + 1, p.end(), a, cmp) - p.begin();
    if(i == 1) return intersect(Segment(p[0], p[i]), a) ? -1 : 0;
    if(i == p.size() - 1 && intersect(Segment(p[0], p[i]), a)) return -1;
    if(intersect(Segment(p[i - 1], p[i]), a)) return -1;
    return (p[i] - p[i - 1]).toleft(a - p[i - 1]) > 0;
}
 
Points halfplane_intersection(vector<Line> L, const T inf = 1e9) {
    Point box[4] = {Point(inf, inf), Point(-inf, inf), Point(-inf, -inf), Point(inf, -inf)};
    rep(i, 4) { L.emplace_back(box[i], box[(i + 1) % 4]); }
    sort(all(L), [](const Line &l, const Line &r) { return (l.b - l.a).arg_cmp(r.b - r.a); });
    deque<Line> dq;
    int len = 0;
    auto check = [](const Line &a, const Line &b, const Line &c) { return a.toleft(crosspoint(b, c)) == -1; };
    rep(i, L.size()) {
        while(dq.size() > 1 and check(L[i], *(end(dq) - 2), *(end(dq) - 1))) dq.pop_back();
        while(dq.size() > 1 and check(L[i], dq[0], dq[1])) dq.pop_front();
        // dump(L[i], si(dq));
 
        if(dq.size() and eq(cross(L[i].b - L[i].a, dq.back().b - dq.back().a), 0)) {
            if(dot(L[i].b - L[i].a, dq.back().b - dq.back().a) < eps) return {};
            if(L[i].toleft(dq.back().a) == -1)
                dq.pop_back();
            else
                continue;
        }
        dq.emplace_back(L[i]);
    }
 
    while(dq.size() > 2 and check(dq[0], *(end(dq) - 2), *(end(dq) - 1))) dq.pop_back();
    while(dq.size() > 2 and check(dq.back(), dq[0], dq[1])) dq.pop_front();
    if(si(dq) < 3) return {};
    Polygon ret(dq.size());
    rep(i, dq.size()) ret[i] = crosspoint(dq[i], dq[(i + 1) % dq.size()]);
    return ret;
}
} // namespace Geometry
 
using namespace Geometry;
 
```


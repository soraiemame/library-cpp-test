---
data:
  _extendedDependsOn:
  - {icon: ':heavy_check_mark:', path: geometory/main.hpp, title: geometory/main.hpp}
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_G
    links: ['https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_G']
  bundledCode: "#line 1 \"test/geometory/common_tangent.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_G\"\n#define\
    \ ERROR 0.00000001\n\n#include <iomanip>\n\n#line 1 \"geometory/main.hpp\"\n\n\
    \n\n#include <vector>\n#include <complex>\n#include <iostream>\n#include <algorithm>\n\
    #include <assert.h>\n\n#define x real()\n#define y imag()\nusing DD = long double;\n\
    using Point = std::complex<DD>;\nusing VP = std::vector<Point>;\nconst DD eps\
    \ = 1e-9;\nstruct lineseg{Point S,T;lineseg(Point s = 0,Point t = 0):S(s),T(t){}};\n\
    struct line{Point S,T;line(Point s = 0,Point t = 0):S(s),T(t){}};\nstruct circle{Point\
    \ C;DD r;circle(Point C_ = 0,DD r_ = 0):C(C_),r(r_){}};\nstruct polygon{\n   \
    \ int n;\n    VP ps;\n    polygon(int n_ = 0):n(n_),ps(n_){}\n    polygon(VP ps_):n(ps_.size()),ps(ps_){}\n\
    \    Point &operator[](int n){return ps[n];}\n};\nint sign(DD a){\n    if(a <\
    \ -eps)return -1;\n    else if(a > eps)return 1;\n    else return 0;\n}\nPoint\
    \ inputP(){\n    DD X,Y;\n    std::cin >> X >> Y;\n    return Point(X,Y);\n}\n\
    bool eq(DD a,DD b){return abs(a - b) < eps;}\nstd::ostream &operator<<(std::ostream&\
    \ os,Point p){return os << \"(\" << p.x << \",\" << p.y << \")\";}\nstd::ostream\
    \ &operator<<(std::ostream& os,line l){return os << l.S << \"->\" << l.T;}\nstd::ostream\
    \ &operator<<(std::ostream& os,lineseg l){return os << l.S << \"->\" << l.T;}\n\
    DD det(Point a,Point b){return a.x * b.y - a.y * b.x;}\nDD dot(Point a,Point b){return\
    \ a.x * b.x + a.y * b.y;}\n\n//o\u3092\u4E2D\u5FC3\u306Bp\u3092theta\u53CD\u6642\
    \u8A08\u56DE\u308A\u306B\u56DE\u8EE2\nPoint rot(Point o,Point p,DD theta){\n \
    \   Point pp = p - o;\n    Point res(pp.x * cosl(theta) - pp.y * sinl(theta),pp.x\
    \ * sinl(theta) + pp.y * cosl(theta));\n    return res + o;\n}\n\n//a->b->c\u306E\
    \u9032\u307F\u65B9\nint dir(Point a,Point b,Point c){\n    b -= a;c -= a;\n  \
    \  if(sign(det(b,c)) == 1)return 1;//counter clockwise\n    else if(sign(det(b,c))\
    \ == -1)return -1;//clockwise\n    else{\n        if(sign(dot(b,c)) == -1)return\
    \ 2;//b a c or c a b\n        else if(norm(b) < norm(c))return -2;//a b c or c\
    \ b a or a == b\n        else return 0;//a c b or b c a or a == c or b == c\n\
    \    }\n}\n\n//\u76F4\u7DDA\u3068\u70B9\nbool isecLP(line l,Point a){return abs(dir(l.S,a,l.T))\
    \ != 1;}\n//2\u3064\u306E\u76F4\u7DDA\u306E\u95A2\u4FC2\nint line_place(line l,line\
    \ m){\n    if(isecLP(l,m.S) && isecLP(l,m.T))return 1;//\u4E00\u81F4\n    else\
    \ if(isecLP(line(l.T - l.S,m.T - m.S),0))return 2;//\u5E73\u884C\n    else if(sign(dot(l.T\
    \ - l.S,m.T - m.S)) == 0)return 3;//\u76F4\u4EA4\n    else return 0;\n}\n//\u76F4\
    \u7DDA\u3068\u76F4\u7DDA\nbool isecLL(line l,line m){\n    return line_place(l,m)\
    \ != 2 && line_place(l,m) != 1;//!(\u5E73\u884C) && !\u4E00\u81F4\n}\n//\u76F4\
    \u7DDA\u3068\u7DDA\u5206\nbool isecLS(line l,lineseg s){\n    s.S -= l.S;s.T -=\
    \ l.S;l.T -= l.S;l.S -= l.S;\n    return sign(det(l.T,s.S) * det(l.T,s.T)) !=\
    \ 1;//l.T\u306B\u5BFE\u3059\u308B\u4F4D\u7F6E\u95A2\u4FC2\u3092\u8ABF\u3079\u305F\
    \n}\n//\u7DDA\u5206\u3068\u7DDA\u5206\nbool isecSS(lineseg s,lineseg t){\n   \
    \ return (dir(s.S,s.T,t.S) * dir(s.S,s.T,t.T) <= 0)\n    && (dir(t.S,t.T,s.S)\
    \ * dir(t.S,t.T,s.T) <= 0);//\u305D\u308C\u305E\u308C\u306E\u7DDA\u5206\u3068\u70B9\
    \u3092\u898B\u3066\u3044\u304D\u3001\u4F4D\u7F6E\u95A2\u4FC2\u304C\u7570\u306A\
    \u308B\u3053(\u4EA4\u308F\u308B)\u3092\u78BA\u8A8D\n}\n//\u7DDA\u5206\u3068\u70B9\
    \nbool isecSP(lineseg s,Point a){\n    return dir(s.S,s.T,a) == 0;\n}\nbool isecPL(Point\
    \ p,line l){return isecLP(l,p);}\nbool isecSL(lineseg s,line l){return isecLS(l,s);}\n\
    bool isecPS(Point p,lineseg s){return isecSP(s,p);}\n\n//p\u304B\u3089l\u306B\u5782\
    \u7DDA\u3092\u304A\u308D\u3057\u305F\u6642\u306E\u4EA4\u70B9\u306E\u5EA7\u6A19\
    \nPoint project(line l,Point p){\n    Point a = l.T - l.S,b = p - l.S;\n    return\
    \ l.S + dot(a,b) / norm(a) * a;//l.S ~ l.T\u3068l.S ~ p\u306E\u8DDD\u96E2\u306E\
    \u6BD4\u3092\u639B\u3051\u308B\n}\n//l\u3092\u8EF8\u306B\u3057\u3066p\u3068\u7DDA\
    \u5BFE\u79F0\u306A\u70B9\nPoint reflect(line l,Point p){return DD(2.0) * project(l,p)\
    \ - p;}\n\n//\u70B9\u3068\u70B9\nDD distPP(Point p,Point q){return abs(p - q);}\n\
    //\u76F4\u7DDA\u3068\u70B9\nDD distLP(line l,Point p){return distPP(project(l,p),p);}\n\
    //\u76F4\u7DDA\u3068\u76F4\u7DDA\nDD distLL(line l,line m){\n    if(line_place(l,m)\
    \ != 2)return 0;\n    else return distLP(l,m.S);\n}\n//\u76F4\u7DDA\u3068\u7DDA\
    \u5206\nDD distLS(line l,lineseg s){\n    if(isecLS(l,s))return 0;\n    else return\
    \ std::min(distLP(l,s.S),distLP(l,s.T));\n}\n//\u7DDA\u5206\u3068\u70B9\nDD distSP(lineseg\
    \ s,Point p){\n    Point q = project(line(s.S,s.T),p);\n    if(isecSP(s,q))return\
    \ abs(p - q);\n    else return std::min(std::abs(s.S - p),std::abs(s.T - p));\n\
    }\n//\u7DDA\u5206\u3068\u7DDA\u5206\nDD distSS(lineseg s,lineseg t){\n    if(isecSS(s,t))return\
    \ 0;\n    else return std::min(std::min(distSP(s,t.S),distSP(s,t.T)),std::min(distSP(t,s.S),distSP(t,s.T)));\n\
    }\n//\u9006\nDD distPL(Point p,line l){return distLP(l,p);}\nDD distSL(lineseg\
    \ s,line l){return distLS(l,s);}\nDD distPS(Point p,lineseg s){return distSP(s,p);}\n\
    \n//2\u76F4\u7DDA\u306E\u4EA4\u70B9\u3092\u8FD4\u3059\n//\u5E73\u884C\u56DB\u8FBA\
    \u5F62\u306E\u9762\u7A4D\u3092\u5916\u7A4D\u3067\u51FA\u3057\u3066\u305D\u306E\
    \u6BD4\u3092\u4F7F\u3063\u3066\u6C42\u3081\u308B\nPoint crosspointLL(line l,line\
    \ m){\n    DD a = det(m.T - m.S,m.S - l.S);\n    DD b = det(m.T - m.S,l.T - l.S);\n\
    \    if(sign(a) == 0 && sign(b) == 0)return l.S;\n    else if(sign(b) == 0)throw\
    \ \"No crosspoint\";\n    return l.S + (l.T - l.S) * (a / b);\n}\n\n//\u5186\u306B\
    \u3064\u3044\u3066\u306E\u8272\u3005\n//\u5186\u3068\u70B9\nDD distCP(circle c,Point\
    \ p,bool inside_zero = 0){\n    if(inside_zero)return std::max(distPP(c.C,p) -\
    \ c.r,DD(0.0));\n    else return std::max(std::abs(distPP(c.C,p) - c.r),DD(0.0));\n\
    }\n\n//\u5186\u3068\u76F4\u7DDA\nDD distCL(circle c,line l){return std::max(distLP(l,c.C)\
    \ - c.r,DD(0.0));}\n\n//\u5186\u3068\u7DDA\u5206\nDD distCS(circle c,lineseg s,bool\
    \ inside_zero = 0){\n    DD sqr1 = norm(s.S - c.C),sqr2 = norm(s.T - c.C);\n \
    \   if(inside_zero == 0){\n        if((sqr1 < c.r * c.r) ^ (sqr2 < c.r * c.r))return\
    \ 0;\n        else if(sqr1 < c.r && sqr2 < c.r)return c.r - sqrtl(std::max(sqr1,sqr2));\n\
    \        else return std::max(distSP(s,c.C) - c.r,DD(0.0));\n    }\n    else{\n\
    \        if(sqr1 < c.r * c.r || sqr2 < c.r * c.r)return 0;\n        else return\
    \ std::max(distSP(s,c.C) - c.r,DD(0.0));\n    }\n}\n\n//\u5186\u3068\u5186\nDD\
    \ distCC(circle c,circle d){\n    DD di = abs(c.C - d.C);\n    return sign(di\
    \ - abs(c.r - d.r)) == 1 ? std::max(di - c.r - d.r,DD(0.0)):abs(c.r - d.r) - di;//!\u5185\
    \u5305:\u5185\u5305\n}\n\nDD distPC(Point p,circle c,bool b = 0){return distCP(c,p,b);}\n\
    DD distLC(line l,circle c){return distCL(c,l);}\nDD distSC(lineseg s,circle c,bool\
    \ b = 0){return distCS(c,s,b);}\n\n//\u5186\u3068\u70B9\nbool isecCP(circle c,Point\
    \ p){return sign(distCP(c,p)) == 0;}\n\n//\u5186\u3068\u76F4\u7DDA\nbool isecCL(circle\
    \ c,line l){return sign(distCL(c,l)) == 0;}\n\n//\u5186\u3068\u7DDA\u5206\nbool\
    \ isecCS(circle c,lineseg s){return sign(distCS(c,s)) == 0;}\n\n//\u5186\u3068\
    \u5186\nbool isecCC(circle c,circle d){return sign(distCC(c,d)) == 0;}\nbool isecPC(Point\
    \ p,circle c){return isecCP(c,p);}\nbool isecLC(line l,circle c){return isecCL(c,l);}\n\
    bool isecSC(lineseg s,circle c){return isecCS(c,s);}\n\n//\u5186\u3068\u76F4\u7DDA\
    \u306E\u4EA4\u70B9\nVP crosspointCL(circle c,line l){\n    VP res;\n    if(sign(distCL(c,l)\
    \ - c.r) == 1)return res;\n    Point p = project(l,c.C);//\u5F26\u306B\u5BFE\u3059\
    \u308B\u5782\u76F4\u4E8C\u7B49\u5206\u7DDA\u306E\u4EA4\u70B9\n    Point q = std::max(sqrtl(c.r\
    \ * c.r - norm(p - c.C)),DD(0.0)) / abs(l.T - l.S) * (l.T - l.S);\n    res.push_back(p\
    \ + q);\n    if(sign(norm(p) - c.r * c.r) != 0)res.push_back(p - q);\n    return\
    \ res;\n}\n\n//\u5186\u3068\u5186\n//1.\u4EA4\u5DEE\u5224\u5B9A\n//2.(url\u5148\
    \u306E\u56F3\u306E)\u9752\u3068\u8D64\u306E\u4EA4\u70B9\u3068c.C\u306E\u8DDD\u96E2\
    \u3092\u6C42\u3081\u308B\n//3.\u8D64\u306E\u30D9\u30AF\u30C8\u30EB\u3068\u9752\
    \u3068\u8D64\u306E\u4EA4\u70B9\u3092\u6C42\u3081\u308B\nVP crosspointCC(circle\
    \ c,circle d){\n    VP res;\n    if(sign(distCC(c,d)) != 0)return res;//1\n  \
    \  Point cd = d.C - c.C;\n    DD di = abs(cd);//c.C\u3068d.C\u306E\u8DDD\u96E2\
    \n    DD X = (norm(cd) - d.r * d.r + c.r * c.r) / (DD(2.0) * di);//2\n    Point\
    \ kou = c.C + X / di * cd;//\u4EA4\u70B9 3\n    Point redv = cd * Point(0,sqrtl(c.r\
    \ * c.r - X * X) / di);//\u8D64\u30D9\u30AF\u30C8\u30EB\u3092\u6BD4\u3068\u56DE\
    \u8EE2\u3067\u6C42\u3081\u308B\n    res.push_back(kou + redv);\n    if(sign(norm(redv))\
    \ != 0)res.push_back(kou - redv);\n    return res;\n}\n\n//p\u304B\u3089c\u3078\
    \u306E\u63A5\u7DDA\u306E\u63A5\u70B9\n//\u8FBA\u306E\u6BD4\u304B\u3089\u89D2\u5EA6\
    \u3092\u51FA\u3057\u3066\u8A08\u7B97\nVP tangentpoints(circle c,Point p){\n  \
    \  VP res;\n    DD sin = c.r / abs(p - c.C);\n    if(sign(sin - DD(1.0)) == 1)return\
    \ res;\n    DD theta = M_PI_2 - asin(std::min(sin,DD(1.0)));\n    res.push_back(c.C\
    \ + (p - c.C) * std::polar(sin,theta));\n    if(sign(sin - DD(1.0)) != 0)res.push_back(c.C\
    \ + (p - c.C) * std::polar(sin,-theta));\n    return res;\n}\n\n//2\u3064\u306E\
    \u5186\u306E\u5171\u901A\u63A5\u7DDA\u3092\u8FD4\u3059\n//1.\u63A5\u7DDA\u306F\
    \u5206\u304B\u3089\u306A\u3044\u306E\u3067\u63A5\u70B9\u3068\u306E\u4E09\u89D2\
    \u6BD4\u3092\u6C42\u3081\u308B\n//2.\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB\u3092\
    \u639B\u3051\u305F\u308A\u3059\u308B\nstd::vector<line> tangetlines(circle c,circle\
    \ d,bool same_point = 0){\n    std::vector<line> res;\n    bool swaped = 0;\n\
    \    if(c.r < d.r){\n        std::swap(c,d);\n        swaped = 1;\n    }\n   \
    \ DD g = norm(c.C - d.C);\n    if(sign(g) == 0)return res;\n    Point u = (d.C\
    \ - c.C) / sqrtl(g);//c->d\u306E\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB\n    Point\
    \ v = u * Point(0,1);//u\u309290\xB0\u56DE\u8EE2\n    for(int s : {-1,1}){\n \
    \       DD h = (c.r + DD(s) * d.r) / sqrt(g);//cos(\u63A5\u70B91,c.r,d.r)\n  \
    \      if(sign(h * h - DD(1.0)) == 0){//\u4E8C\u3064\u306E\u5186\u304C\u63A5\u3057\
    \u3066\u3044\u308B\u3068\u3053\u308D\n            if(!same_point)res.push_back(line(c.C\
    \ + u * c.r,c.C + u * c.r + v));//v\u3092\u8DB3\u3057\u3066\u540C\u3058\u70B9\u3092\
    \u8FD4\u3059\u3053\u3068\u3092\u9632\u3050\n            else res.push_back(line(c.C\
    \ + u * c.r,c.C + u * c.r));\n        }\n        else if(sign(DD(1.0) - h * h)\
    \ == 1){\n            Point uu = u * h,vv = v * sqrtl(DD(1.0) - h * h);//uu:u\
    \ * cos,vv:v * sin\n            res.push_back(line(c.C + (uu + vv) * c.r,d.C -\
    \ (uu + vv) * d.r * DD(s)));\n            res.push_back(line(c.C + (uu - vv) *\
    \ c.r,d.C - (uu - vv) * d.r * DD(s)));\n        }\n    }\n    if(swaped)for(auto\
    \ &a : res)swap(a.S,a.T);\n    return res;\n}\n\n//p\u3068q\u3092\u901A\u308B\u534A\
    \u5F84d\u306E\u5186\u306E\u4E2D\u5FC3\nVP circlepointsradius(Point p,Point q,DD\
    \ d){\n    VP res;\n    Point pqM = (q - p) / DD(2.0);\n    DD di = abs(pqM);\n\
    \    if(sign(di) == 0 || norm(pqM) > d * d)return res;\n    Point n = pqM * Point(0,1)\
    \ * (sqrtl(norm(pqM) - d * d) / di);//\u30D9\u30AF\u30C8\u30EB\u309290\xB0\u56DE\
    \u8EE2\u3055\u305B\u3066\u6BD4\u3092\u304B\u3051\u308B\n    res.push_back(p +\
    \ pqM + n);\n    if(sign(sqrtl(norm(pqM) - d * d)) > 0)res.push_back(p + pqM -\
    \ n);\n    return res;\n}\n\n\n\n//\u591A\u89D2\u5F62\n//\u5916\u5FC3\nPoint gaisin(polygon\
    \ po){\n    assert(po.n == 3);\n    po[0] = (po[0] - po[2]) / DD(2.0);\n    po[1]\
    \ = (po[1] - po[2]) / DD(2.0);\n    return po[2] + crosspointLL(line(po[0],po[0]\
    \ * Point(1,1)),line(po[1],po[1] * Point(1,1)));\n}\nPoint gaisin(Point a,Point\
    \ b,Point c){return gaisin(polygon({a,b,c}));}\n\n//\u91CD\u5FC3\nPoint jusin(polygon\
    \ po){\n    assert(po.n == 3);\n    return (po[0] + po[1] + po[2]) / DD(3.0);\n\
    }\nPoint jusin(Point a,Point b,Point c){return jusin(polygon({a,b,c}));}\n\n//\u5185\
    \u5FC3\nPoint naisin(polygon po){\n    assert(po.n == 3);\n    DD a = distPP(po[1],po[2]);\n\
    \    DD b = distPP(po[0],po[2]);\n    DD c = distPP(po[0],po[1]);\n    return\
    \ (po[0] * a + po[1] * b + po[2] * c) / (a + b + c);\n}\nPoint naisin(Point a,Point\
    \ b,Point c){return naisin(polygon({a,b,c}));}\n\n//\u5782\u5FC3\n//\u30AA\u30A4\
    \u30E9\u30FC\u7DDA:\u5782\u5FC3H,\u91CD\u5FC3G,\u5916\u5FC3O\u3068\u3059\u308B\
    \u3068OG:GH = 1:2\nPoint suisin(polygon po){\n    assert(po.n == 3);\n    return\
    \ po[0] + po[1] + po[2] - DD(2.0) * gaisin(po);\n}\nPoint suisin(Point a,Point\
    \ b,Point c){return suisin(polygon({a,b,c}));}\n\ncircle minenclosingcircle(const\
    \ VP &ps){\n    int n = ps.size();\n    VP alt;\n    for(int i = 0;i < n;i++){\n\
    \        for(int j = i + 1;j < n;j++){\n            alt.push_back((ps[i] + ps[j])\
    \ / DD(2));\n            for(int k = j + 1;k < n;k++){\n                if(dir(ps[i],ps[j],ps[k])\
    \ != 1 && dir(ps[i],ps[j],ps[k]) != -1)continue;\n                alt.push_back(gaisin(ps[i],ps[j],ps[k]));\n\
    \            }\n        }\n    }\n    DD r = 1LL << 60;\n    Point c;\n    for(Point\
    \ p : alt){\n        DD mx = 0;\n        for(int i = 0;i < n;i++){\n         \
    \   mx = std::max(mx,distPP(ps[i],p));\n        }\n        if(sign(r - mx) ==\
    \ 1){\n            r = mx;\n            c = p;\n        }\n    }\n    return circle(c,r);\n\
    }\n\n//\u5168\u3066\u306E\u9802\u70B9\u3092\u542B\u3080\u6700\u5C0F\u306E\u5186\
    \u3092\u8FD4\u3059\ncircle minenclosingcircle2(const VP &ps){\n    Point c;\n\
    \    DD move = 0.5;\n    for(int i = 0;i < 40;i++){//\u7CBE\u5EA6\n        for(int\
    \ _ = 0;_ < 200;_++){//\u3053\u3053\u306B\u3088\u3063\u3066\u5909\u308F\u308A\u305D\
    \u3046\n            DD mx = 0;\n            int k = 0;\n            for(int j\
    \ = 0;j < int(ps.size());j++){\n                if(mx < norm(ps[j] - c)){\n  \
    \                  mx = norm(ps[j] - c);\n                    k = j;\n       \
    \         }\n            }\n            c += (ps[k] - c) * move;\n        }\n\
    \        move /= DD(2.0);\n    }\n    DD r = 0;\n    for(int i = 0;i < int(ps.size());i++){\n\
    \        r = std::max(r,std::abs(c - ps[i]));\n    }\n    return circle(c,r);\n\
    }\n\n\n//\u591A\u89D2\u5F62\u306E\u9762\u7A4D\nDD area(polygon &po){\n    DD a\
    \ = 0;\n    for(int i = 0;i < po.n;i++)a += det(po[i],po[(i + 1) % po.n]);\n \
    \   return a / DD(2);\n}\n\n//\u591A\u89D2\u5F62\u306E\u51F8\u5224\u5B9A\nbool\
    \ isconvex(polygon& po){\n    int neg = 0,pos = 0;\n    for(int i = 0;i < po.n;i++){\n\
    \        int ccw = dir(po[i],po[(i + 1) % po.n],po[(i + 2) % po.n]);\n       \
    \ if(ccw == 1)pos++;\n        else if(ccw == -1)neg++;\n    }\n    if(pos && neg)return\
    \ false;\n    else return true;\n}\n\n//\u591A\u89D2\u5F62\u306E\u5185\u90E8\u5224\
    \u5B9A\n//p\u304B\u3089x\u6B63\u306E\u65B9\u5411\u3078\u534A\u76F4\u7DDA\u3092\
    \u4F38\u3070\u3057\u3066\u4EA4\u70B9\u3092\u6570\u3048\u308B\n//0:\u5916\u90E8\
    ,1:\u5185\u90E8,2:\u7DDA\u5206\u4E0A\nint inpolygon(Point p,polygon& po){\n  \
    \  int n = po.n;\n    bool in = 0;\n    for(int i = 0;i < n;i++){\n        Point\
    \ a = po[i];\n        Point b = po[(i + 1) % n];\n        if(isecPS(p,lineseg(a,b)))return\
    \ 2;\n        if(!isecLS(line(p,p + DD(1.0)),lineseg(a,b)))continue;\n       \
    \ if(a.y > b.y)swap(a,b);\n        try{\n            Point q = crosspointLL(line(p,p\
    \ + DD(1.0)),line(a,b));\n            if(sign(q.x - p.x) == 1 && !(sign(q.x -\
    \ b.x) == 0 && sign(q.y - b.y) == 0))in = !in;\n        }\n        catch(...){continue;}\n\
    \    }\n    return in;\n}\n\nbool compare_x(const Point a,const Point b){\n  \
    \  return sign(a.x - b.x) == 0 ? a.y < b.y:a.x < b.x;\n}\nbool compare_y(const\
    \ Point a,const Point b){\n    return sign(a.y - b.y) == 0 ? a.x < b.x:a.y < b.y;\n\
    }\n\n//\u51F8\u5305\nVP convexhull(VP vp){\n    int n = vp.size();\n    int k\
    \ = 0;\n    sort(vp.begin(),vp.end(),compare_x);\n    VP res(2 * n);\n    for(int\
    \ i = 0;i < n;i++){\n        while(k >= 2 && dir(res[k - 2],res[k - 1],vp[i])\
    \ == 1)k--;\n        res[k] = vp[i];\n        k++;\n    }\n    int t = k + 1;\n\
    \    k--;\n    for(int i = n - 1;i >= 0;i--){\n        while(k >= t && dir(res[k\
    \ - 2],res[k - 1],vp[i]) == 1)k--;\n        res[k] = vp[i];\n        k++;\n  \
    \  }\n    res.resize(k - 1);\n    return res;\n}\n\n//\u6700\u9060\u70B9\u5BFE\
    \u51F8\u591A\u89D2\u5F62\u306B\u306A\u3063\u3066\u308B\u5834\u5408\u306E\u307F\
    \nstd::pair<int,int> farthestpoints(const VP& con){\n    int n = con.size();\n\
    \    int i = std::min_element(con.begin(),con.end(),compare_x) - con.begin();\n\
    \    int j = std::max_element(con.begin(),con.end(),compare_x) - con.begin();\n\
    \    int MAXI = -1,MAXJ = -1;\n    DD MAXDD = 0;\n    for(int k = 0;k < 2 * n;k++){\n\
    \        if(MAXDD < std::norm(con[i] - con[j])){\n            MAXDD = std::norm(con[i]\
    \ - con[j]);\n            MAXI = i;MAXJ = j;\n        }\n        if(sign(det(con[(i\
    \ + 1) % n] - con[i],con[j] - con[(j + 1) % n])) <= 0)j = (j + 1) % n;\n     \
    \   else i = (i + 1) % n;\n    }\n    return std::make_pair(MAXI,MAXJ);\n}\n\n\
    DD farthestdist(VP& vp){\n    vp = convexhull(vp);\n    std::reverse(vp.begin(),vp.end());\n\
    \    auto r = farthestpoints(vp);\n    return abs(vp[r.first] - vp[r.second]);\n\
    }\n\n//\u6700\u8FD1\u70B9\u5BFE\n//\u5206\u5272\u7D71\u6CBB\nDD closestdist(VP\
    \ &vp,int l,int r){\n    if(r - l <= 1)return 1LL << 60;\n    int mid = (l + r)\
    \ / 2;\n    DD X = vp[mid].x;\n    DD d = std::min(closestdist(vp,l,mid),closestdist(vp,mid,r));\n\
    \    std::inplace_merge(vp.begin() + l,vp.begin() + mid,vp.begin() + r,compare_y);\n\
    \    std::vector<Point> B;\n    for(int i = l;i < r;i++){\n        if(sign(std::abs(vp[i].x\
    \ - X) - d) >= 0)continue;\n        for(int j = B.size() - 1;j >= 0;j--){\n  \
    \          if(sign(std::abs((vp[i] - B[j]).y) - d) >= 0)break;\n            if(d\
    \ > std::abs(vp[i] - B[j]))d = std::abs(vp[i] - B[j]);\n        }\n        B.push_back(vp[i]);\n\
    \    }\n    return d;\n}\n\nDD closestdist(VP &vp){\n    return closestdist(vp,0,int(vp.size()));\n\
    }\n\n//2\u5186\u306E\u5171\u901A\u9762\u7A4D\nDD twocirclearea(circle c,circle\
    \ d){\n    DD dist = abs(c.C - d.C);\n    if(sign(dist - c.r - d.r) >= 0)return\
    \ DD(0.0);\n    if(sign(dist - abs(c.r - d.r)) <= 0){\n        DD r = std::min(c.r,d.r);\n\
    \        return r * r * M_PI;\n    }\n    //2\u5186\u306E\u4EA4\u70B9\u3092\u6C42\
    \u3081\u305F\u6642\u3068\u540C\u3058\u3088\u3046\u306B\u8DDD\u96E2\u3092\u6E2C\
    \u308B\n    DD rc = (c.r * c.r - d.r * d.r + dist * dist) / (DD(2.0) * dist);\n\
    \    DD theta1 = acosl(rc / c.r);\n    DD theta2 = acosl((dist - rc) / d.r);\n\
    \    return (c.r * c.r * theta1 + d.r * d.r * theta2 - dist * sinl(theta1) * c.r);\n\
    }\n\n//\u5E7E\u4F55\u30B0\u30E9\u30D5\nstruct g_edge{\n    int from,to;DD cost;\n\
    \    g_edge(int from_,int to_,DD cost_):from(from_),to(to_),cost(cost_){}\n};\n\
    struct g_graph{\n    int n;\n    std::vector<std::vector<g_edge>> es;\n    g_graph(int\
    \ n_ = 0):n(n_),es(n_){}\n    void add_edge(g_edge e){\n        es[e.from].push_back(e);\n\
    \        es[e.to].push_back({e.to,e.from,e.cost});\n    }\n};\n\n//\u53EF\u8996\
    \u30B0\u30E9\u30D5\ng_graph visibilitygraph(const VP& vp,const std::vector<polygon>&\
    \ objs){\n    int n = vp.size();\n    g_graph res(n);\n    bool cross = 0;\n \
    \   for(int i = 0;i < n;i++){\n        for(int j = 0;j < i;j++){\n           \
    \ cross = 0;\n            for(auto obj : objs){\n                int A = inpolygon(vp[i],obj);\n\
    \                int B = inpolygon(vp[j],obj);\n                if((A ^ B) % 2\
    \ || (A * B != 1 && inpolygon((vp[i] + vp[j]) * DD(0.5),obj) == 1)){\n       \
    \             cross = 1;\n                    break;\n                }\n    \
    \            for(int k = 0;k < obj.n;k++){\n                    lineseg ls(obj[k],obj[(k\
    \ + 1) % obj.n]);\n                    if(isecSS(lineseg(vp[i],vp[j]),ls) && !isecSP(ls,vp[i])\
    \ && !isecSP(ls,vp[j])){\n                        cross = 1;\n               \
    \         break;\n                    }\n                }\n                if(cross)break;\n\
    \            }\n            if(!cross)res.add_edge({int(i),int(j),abs(vp[i] -\
    \ vp[j])});\n        }\n    }\n    return res;\n}\n//#undef x\n//#undef y\n\n\n\
    #line 7 \"test/geometory/common_tangent.test.cpp\"\n\nint main(){\n    std::cout\
    \ << std::fixed << std::setprecision(15);\n    circle A,B;\n    A.C = inputP();std::cin\
    \ >> A.r;\n    B.C = inputP();std::cin >> B.r;\n    auto _ans = tangetlines(A,B,true);\n\
    \    VP ans;\n    for(auto a : _ans)ans.push_back(a.S);\n    std::sort(ans.begin(),ans.end(),compare_x);\n\
    \    for(auto a : ans)std::cout << a.x << \" \" << a.y << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_G\"\
    \n#define ERROR 0.00000001\n\n#include <iomanip>\n\n#include \"../../geometory/main.hpp\"\
    \n\nint main(){\n    std::cout << std::fixed << std::setprecision(15);\n    circle\
    \ A,B;\n    A.C = inputP();std::cin >> A.r;\n    B.C = inputP();std::cin >> B.r;\n\
    \    auto _ans = tangetlines(A,B,true);\n    VP ans;\n    for(auto a : _ans)ans.push_back(a.S);\n\
    \    std::sort(ans.begin(),ans.end(),compare_x);\n    for(auto a : ans)std::cout\
    \ << a.x << \" \" << a.y << \"\\n\";\n}"
  dependsOn: [geometory/main.hpp]
  isVerificationFile: true
  path: test/geometory/common_tangent.test.cpp
  requiredBy: []
  timestamp: '2021-03-28 10:59:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometory/common_tangent.test.cpp
layout: document
redirect_from: [/verify/test/geometory/common_tangent.test.cpp, /verify/test/geometory/common_tangent.test.cpp.html]
title: test/geometory/common_tangent.test.cpp
---

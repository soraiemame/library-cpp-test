#ifndef SORAIE_GEOMETORY_MAIN
#define SORAIE_GEOMETORY_MAIN

#include <vector>
#include <complex>
#include <iostream>
#include <algorithm>
#include <assert.h>

#define x real()
#define y imag()
using DD = long double;
using Point = std::complex<DD>;
using VP = std::vector<Point>;
const DD eps = 1e-9;
struct lineseg{Point S,T;lineseg(Point s = 0,Point t = 0):S(s),T(t){}};
struct line{Point S,T;line(Point s = 0,Point t = 0):S(s),T(t){}};
struct circle{Point C;DD r;circle(Point C_ = 0,DD r_ = 0):C(C_),r(r_){}};
struct polygon{
    int n;
    VP ps;
    polygon(int n_ = 0):n(n_),ps(n_){}
    polygon(VP ps_):n(ps_.size()),ps(ps_){}
    Point &operator[](int n){return ps[n];}
};
int sign(DD a){
    if(a < -eps)return -1;
    else if(a > eps)return 1;
    else return 0;
}
Point inputP(){
    DD X,Y;
    std::cin >> X >> Y;
    return Point(X,Y);
}
bool eq(DD a,DD b){return abs(a - b) < eps;}
std::ostream &operator<<(std::ostream& os,Point p){return os << "(" << p.x << "," << p.y << ")";}
std::ostream &operator<<(std::ostream& os,line l){return os << l.S << "->" << l.T;}
std::ostream &operator<<(std::ostream& os,lineseg l){return os << l.S << "->" << l.T;}
DD det(Point a,Point b){return a.x * b.y - a.y * b.x;}
DD dot(Point a,Point b){return a.x * b.x + a.y * b.y;}

//oを中心にpをtheta反時計回りに回転
Point rot(Point o,Point p,DD theta){
    Point pp = p - o;
    Point res(pp.x * cosl(theta) - pp.y * sinl(theta),pp.x * sinl(theta) + pp.y * cosl(theta));
    return res + o;
}

//a->b->cの進み方
int dir(Point a,Point b,Point c){
    b -= a;c -= a;
    if(sign(det(b,c)) == 1)return 1;//counter clockwise
    else if(sign(det(b,c)) == -1)return -1;//clockwise
    else{
        if(sign(dot(b,c)) == -1)return 2;//b a c or c a b
        else if(norm(b) < norm(c))return -2;//a b c or c b a or a == b
        else return 0;//a c b or b c a or a == c or b == c
    }
}

//直線と点
bool isecLP(line l,Point a){return abs(dir(l.S,a,l.T)) != 1;}
//2つの直線の関係
int line_place(line l,line m){
    if(isecLP(l,m.S) && isecLP(l,m.T))return 1;//一致
    else if(isecLP(line(l.T - l.S,m.T - m.S),0))return 2;//平行
    else if(sign(dot(l.T - l.S,m.T - m.S)) == 0)return 3;//直交
    else return 0;
}
//直線と直線
bool isecLL(line l,line m){
    return line_place(l,m) != 2 && line_place(l,m) != 1;//!(平行) && !一致
}
//直線と線分
bool isecLS(line l,lineseg s){
    s.S -= l.S;s.T -= l.S;l.T -= l.S;l.S -= l.S;
    return sign(det(l.T,s.S) * det(l.T,s.T)) != 1;//l.Tに対する位置関係を調べた
}
//線分と線分
bool isecSS(lineseg s,lineseg t){
    return (dir(s.S,s.T,t.S) * dir(s.S,s.T,t.T) <= 0)
    && (dir(t.S,t.T,s.S) * dir(t.S,t.T,s.T) <= 0);//それぞれの線分と点を見ていき、位置関係が異なるこ(交わる)を確認
}
//線分と点
bool isecSP(lineseg s,Point a){
    return dir(s.S,s.T,a) == 0;
}
bool isecPL(Point p,line l){return isecLP(l,p);}
bool isecSL(lineseg s,line l){return isecLS(l,s);}
bool isecPS(Point p,lineseg s){return isecSP(s,p);}

//pからlに垂線をおろした時の交点の座標
Point project(line l,Point p){
    Point a = l.T - l.S,b = p - l.S;
    return l.S + dot(a,b) / norm(a) * a;//l.S ~ l.Tとl.S ~ pの距離の比を掛ける
}
//lを軸にしてpと線対称な点
Point reflect(line l,Point p){return DD(2.0) * project(l,p) - p;}

//点と点
DD distPP(Point p,Point q){return abs(p - q);}
//直線と点
DD distLP(line l,Point p){return distPP(project(l,p),p);}
//直線と直線
DD distLL(line l,line m){
    if(line_place(l,m) != 2)return 0;
    else return distLP(l,m.S);
}
//直線と線分
DD distLS(line l,lineseg s){
    if(isecLS(l,s))return 0;
    else return std::min(distLP(l,s.S),distLP(l,s.T));
}
//線分と点
DD distSP(lineseg s,Point p){
    Point q = project(line(s.S,s.T),p);
    if(isecSP(s,q))return abs(p - q);
    else return std::min(std::abs(s.S - p),std::abs(s.T - p));
}
//線分と線分
DD distSS(lineseg s,lineseg t){
    if(isecSS(s,t))return 0;
    else return std::min(std::min(distSP(s,t.S),distSP(s,t.T)),std::min(distSP(t,s.S),distSP(t,s.T)));
}
//逆
DD distPL(Point p,line l){return distLP(l,p);}
DD distSL(lineseg s,line l){return distLS(l,s);}
DD distPS(Point p,lineseg s){return distSP(s,p);}

//2直線の交点を返す
//平行四辺形の面積を外積で出してその比を使って求める
Point crosspointLL(line l,line m){
    DD a = det(m.T - m.S,m.S - l.S);
    DD b = det(m.T - m.S,l.T - l.S);
    if(sign(a) == 0 && sign(b) == 0)return l.S;
    else if(sign(b) == 0)throw "No crosspoint";
    return l.S + (l.T - l.S) * (a / b);
}

//円についての色々
//円と点
DD distCP(circle c,Point p,bool inside_zero = 0){
    if(inside_zero)return std::max(distPP(c.C,p) - c.r,DD(0.0));
    else return std::max(std::abs(distPP(c.C,p) - c.r),DD(0.0));
}

//円と直線
DD distCL(circle c,line l){return std::max(distLP(l,c.C) - c.r,DD(0.0));}

//円と線分
DD distCS(circle c,lineseg s,bool inside_zero = 0){
    DD sqr1 = norm(s.S - c.C),sqr2 = norm(s.T - c.C);
    if(inside_zero == 0){
        if((sqr1 < c.r * c.r) ^ (sqr2 < c.r * c.r))return 0;
        else if(sqr1 < c.r && sqr2 < c.r)return c.r - sqrtl(std::max(sqr1,sqr2));
        else return std::max(distSP(s,c.C) - c.r,DD(0.0));
    }
    else{
        if(sqr1 < c.r * c.r || sqr2 < c.r * c.r)return 0;
        else return std::max(distSP(s,c.C) - c.r,DD(0.0));
    }
}

//円と円
DD distCC(circle c,circle d){
    DD di = abs(c.C - d.C);
    return sign(di - abs(c.r - d.r)) == 1 ? std::max(di - c.r - d.r,DD(0.0)):abs(c.r - d.r) - di;//!内包:内包
}

DD distPC(Point p,circle c,bool b = 0){return distCP(c,p,b);}
DD distLC(line l,circle c){return distCL(c,l);}
DD distSC(lineseg s,circle c,bool b = 0){return distCS(c,s,b);}

//円と点
bool isecCP(circle c,Point p){return sign(distCP(c,p)) == 0;}

//円と直線
bool isecCL(circle c,line l){return sign(distCL(c,l)) == 0;}

//円と線分
bool isecCS(circle c,lineseg s){return sign(distCS(c,s)) == 0;}

//円と円
bool isecCC(circle c,circle d){return sign(distCC(c,d)) == 0;}
bool isecPC(Point p,circle c){return isecCP(c,p);}
bool isecLC(line l,circle c){return isecCL(c,l);}
bool isecSC(lineseg s,circle c){return isecCS(c,s);}

//円と直線の交点
VP crosspointCL(circle c,line l){
    VP res;
    if(sign(distCL(c,l) - c.r) == 1)return res;
    Point p = project(l,c.C);//弦に対する垂直二等分線の交点
    Point q = std::max(sqrtl(c.r * c.r - norm(p - c.C)),DD(0.0)) / abs(l.T - l.S) * (l.T - l.S);
    res.push_back(p + q);
    if(sign(norm(p) - c.r * c.r) != 0)res.push_back(p - q);
    return res;
}

//円と円
//1.交差判定
//2.(url先の図の)青と赤の交点とc.Cの距離を求める
//3.赤のベクトルと青と赤の交点を求める
VP crosspointCC(circle c,circle d){
    VP res;
    if(sign(distCC(c,d)) != 0)return res;//1
    Point cd = d.C - c.C;
    DD di = abs(cd);//c.Cとd.Cの距離
    DD X = (norm(cd) - d.r * d.r + c.r * c.r) / (DD(2.0) * di);//2
    Point kou = c.C + X / di * cd;//交点 3
    Point redv = cd * Point(0,sqrtl(c.r * c.r - X * X) / di);//赤ベクトルを比と回転で求める
    res.push_back(kou + redv);
    if(sign(norm(redv)) != 0)res.push_back(kou - redv);
    return res;
}

//pからcへの接線の接点
//辺の比から角度を出して計算
VP tangentpoints(circle c,Point p){
    VP res;
    DD sin = c.r / abs(p - c.C);
    if(sign(sin - DD(1.0)) == 1)return res;
    DD theta = M_PI_2 - asin(std::min(sin,DD(1.0)));
    res.push_back(c.C + (p - c.C) * std::polar(sin,theta));
    if(sign(sin - DD(1.0)) != 0)res.push_back(c.C + (p - c.C) * std::polar(sin,-theta));
    return res;
}

//2つの円の共通接線を返す
//1.接線は分からないので接点との三角比を求める
//2.単位ベクトルを掛けたりする
std::vector<line> tangetlines(circle c,circle d,bool same_point = 0){
    std::vector<line> res;
    bool swaped = 0;
    if(c.r < d.r){
        std::swap(c,d);
        swaped = 1;
    }
    DD g = norm(c.C - d.C);
    if(sign(g) == 0)return res;
    Point u = (d.C - c.C) / sqrtl(g);//c->dの単位ベクトル
    Point v = u * Point(0,1);//uを90°回転
    for(int s : {-1,1}){
        DD h = (c.r + DD(s) * d.r) / sqrt(g);//cos(接点1,c.r,d.r)
        if(sign(h * h - DD(1.0)) == 0){//二つの円が接しているところ
            if(!same_point)res.push_back(line(c.C + u * c.r,c.C + u * c.r + v));//vを足して同じ点を返すことを防ぐ
            else res.push_back(line(c.C + u * c.r,c.C + u * c.r));
        }
        else if(sign(DD(1.0) - h * h) == 1){
            Point uu = u * h,vv = v * sqrtl(DD(1.0) - h * h);//uu:u * cos,vv:v * sin
            res.push_back(line(c.C + (uu + vv) * c.r,d.C - (uu + vv) * d.r * DD(s)));
            res.push_back(line(c.C + (uu - vv) * c.r,d.C - (uu - vv) * d.r * DD(s)));
        }
    }
    if(swaped)for(auto &a : res)swap(a.S,a.T);
    return res;
}

//pとqを通る半径dの円の中心
VP circlepointsradius(Point p,Point q,DD d){
    VP res;
    Point pqM = (q - p) / DD(2.0);
    DD di = abs(pqM);
    if(sign(di) == 0 || norm(pqM) > d * d)return res;
    Point n = pqM * Point(0,1) * (sqrtl(norm(pqM) - d * d) / di);//ベクトルを90°回転させて比をかける
    res.push_back(p + pqM + n);
    if(sign(sqrtl(norm(pqM) - d * d)) > 0)res.push_back(p + pqM - n);
    return res;
}



//多角形
//外心
Point gaisin(polygon po){
    assert(po.n == 3);
    po[0] = (po[0] - po[2]) / DD(2.0);
    po[1] = (po[1] - po[2]) / DD(2.0);
    return po[2] + crosspointLL(line(po[0],po[0] * Point(1,1)),line(po[1],po[1] * Point(1,1)));
}
Point gaisin(Point a,Point b,Point c){return gaisin(polygon({a,b,c}));}

//重心
Point jusin(polygon po){
    assert(po.n == 3);
    return (po[0] + po[1] + po[2]) / DD(3.0);
}
Point jusin(Point a,Point b,Point c){return jusin(polygon({a,b,c}));}

//内心
Point naisin(polygon po){
    assert(po.n == 3);
    DD a = distPP(po[1],po[2]);
    DD b = distPP(po[0],po[2]);
    DD c = distPP(po[0],po[1]);
    return (po[0] * a + po[1] * b + po[2] * c) / (a + b + c);
}
Point naisin(Point a,Point b,Point c){return naisin(polygon({a,b,c}));}

//垂心
//オイラー線:垂心H,重心G,外心OとするとOG:GH = 1:2
Point suisin(polygon po){
    assert(po.n == 3);
    return po[0] + po[1] + po[2] - DD(2.0) * gaisin(po);
}
Point suisin(Point a,Point b,Point c){return suisin(polygon({a,b,c}));}

circle minenclosingcircle(const VP &ps){
    int n = ps.size();
    VP alt;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            alt.push_back((ps[i] + ps[j]) / DD(2));
            for(int k = j + 1;k < n;k++){
                if(dir(ps[i],ps[j],ps[k]) != 1 && dir(ps[i],ps[j],ps[k]) != -1)continue;
                alt.push_back(gaisin(ps[i],ps[j],ps[k]));
            }
        }
    }
    DD r = 1LL << 60;
    Point c;
    for(Point p : alt){
        DD mx = 0;
        for(int i = 0;i < n;i++){
            mx = std::max(mx,distPP(ps[i],p));
        }
        if(sign(r - mx) == 1){
            r = mx;
            c = p;
        }
    }
    return circle(c,r);
}

//全ての頂点を含む最小の円を返す
circle minenclosingcircle2(const VP &ps){
    Point c;
    DD move = 0.5;
    for(int i = 0;i < 40;i++){//精度
        for(int _ = 0;_ < 200;_++){//ここによって変わりそう
            DD mx = 0;
            int k = 0;
            for(int j = 0;j < int(ps.size());j++){
                if(mx < norm(ps[j] - c)){
                    mx = norm(ps[j] - c);
                    k = j;
                }
            }
            c += (ps[k] - c) * move;
        }
        move /= DD(2.0);
    }
    DD r = 0;
    for(int i = 0;i < int(ps.size());i++){
        r = std::max(r,std::abs(c - ps[i]));
    }
    return circle(c,r);
}


//多角形の面積
DD area(polygon &po){
    DD a = 0;
    for(int i = 0;i < po.n;i++)a += det(po[i],po[(i + 1) % po.n]);
    return a / DD(2);
}

//多角形の凸判定
bool isconvex(polygon& po){
    int neg = 0,pos = 0;
    for(int i = 0;i < po.n;i++){
        int ccw = dir(po[i],po[(i + 1) % po.n],po[(i + 2) % po.n]);
        if(ccw == 1)pos++;
        else if(ccw == -1)neg++;
    }
    if(pos && neg)return false;
    else return true;
}

//多角形の内部判定
//pからx正の方向へ半直線を伸ばして交点を数える
//0:外部,1:内部,2:線分上
int inpolygon(Point p,polygon& po){
    int n = po.n;
    bool in = 0;
    for(int i = 0;i < n;i++){
        Point a = po[i];
        Point b = po[(i + 1) % n];
        if(isecPS(p,lineseg(a,b)))return 2;
        if(!isecLS(line(p,p + DD(1.0)),lineseg(a,b)))continue;
        if(a.y > b.y)swap(a,b);
        try{
            Point q = crosspointLL(line(p,p + DD(1.0)),line(a,b));
            if(sign(q.x - p.x) == 1 && !(sign(q.x - b.x) == 0 && sign(q.y - b.y) == 0))in = !in;
        }
        catch(...){continue;}
    }
    return in;
}

bool compare_x(const Point a,const Point b){
    return sign(a.x - b.x) == 0 ? a.y < b.y:a.x < b.x;
}
bool compare_y(const Point a,const Point b){
    return sign(a.y - b.y) == 0 ? a.x < b.x:a.y < b.y;
}

//凸包
VP convexhull(VP vp){
    int n = vp.size();
    int k = 0;
    sort(vp.begin(),vp.end(),compare_x);
    VP res(2 * n);
    for(int i = 0;i < n;i++){
        while(k >= 2 && dir(res[k - 2],res[k - 1],vp[i]) == 1)k--;
        res[k] = vp[i];
        k++;
    }
    int t = k + 1;
    k--;
    for(int i = n - 1;i >= 0;i--){
        while(k >= t && dir(res[k - 2],res[k - 1],vp[i]) == 1)k--;
        res[k] = vp[i];
        k++;
    }
    res.resize(k - 1);
    return res;
}

//最遠点対凸多角形になってる場合のみ
std::pair<int,int> farthestpoints(const VP& con){
    int n = con.size();
    int i = std::min_element(con.begin(),con.end(),compare_x) - con.begin();
    int j = std::max_element(con.begin(),con.end(),compare_x) - con.begin();
    int MAXI = -1,MAXJ = -1;
    DD MAXDD = 0;
    for(int k = 0;k < 2 * n;k++){
        if(MAXDD < std::norm(con[i] - con[j])){
            MAXDD = std::norm(con[i] - con[j]);
            MAXI = i;MAXJ = j;
        }
        if(sign(det(con[(i + 1) % n] - con[i],con[j] - con[(j + 1) % n])) <= 0)j = (j + 1) % n;
        else i = (i + 1) % n;
    }
    return std::make_pair(MAXI,MAXJ);
}

DD farthestdist(VP& vp){
    vp = convexhull(vp);
    std::reverse(vp.begin(),vp.end());
    auto r = farthestpoints(vp);
    return abs(vp[r.first] - vp[r.second]);
}

//最近点対
//分割統治
DD closestdist(VP &vp,int l,int r){
    if(r - l <= 1)return 1LL << 60;
    int mid = (l + r) / 2;
    DD X = vp[mid].x;
    DD d = std::min(closestdist(vp,l,mid),closestdist(vp,mid,r));
    std::inplace_merge(vp.begin() + l,vp.begin() + mid,vp.begin() + r,compare_y);
    std::vector<Point> B;
    for(int i = l;i < r;i++){
        if(sign(std::abs(vp[i].x - X) - d) >= 0)continue;
        for(int j = B.size() - 1;j >= 0;j--){
            if(sign(std::abs((vp[i] - B[j]).y) - d) >= 0)break;
            if(d > std::abs(vp[i] - B[j]))d = std::abs(vp[i] - B[j]);
        }
        B.push_back(vp[i]);
    }
    return d;
}

DD closestdist(VP &vp){
    return closestdist(vp,0,int(vp.size()));
}

//2円の共通面積
DD twocirclearea(circle c,circle d){
    DD dist = abs(c.C - d.C);
    if(sign(dist - c.r - d.r) >= 0)return DD(0.0);
    if(sign(dist - abs(c.r - d.r)) <= 0){
        DD r = std::min(c.r,d.r);
        return r * r * M_PI;
    }
    //2円の交点を求めた時と同じように距離を測る
    DD rc = (c.r * c.r - d.r * d.r + dist * dist) / (DD(2.0) * dist);
    DD theta1 = acosl(rc / c.r);
    DD theta2 = acosl((dist - rc) / d.r);
    return (c.r * c.r * theta1 + d.r * d.r * theta2 - dist * sinl(theta1) * c.r);
}

//幾何グラフ
struct g_edge{
    int from,to;DD cost;
    g_edge(int from_,int to_,DD cost_):from(from_),to(to_),cost(cost_){}
};
struct g_graph{
    int n;
    std::vector<std::vector<g_edge>> es;
    g_graph(int n_ = 0):n(n_),es(n_){}
    void add_edge(g_edge e){
        es[e.from].push_back(e);
        es[e.to].push_back({e.to,e.from,e.cost});
    }
};

//可視グラフ
g_graph visibilitygraph(const VP& vp,const std::vector<polygon>& objs){
    int n = vp.size();
    g_graph res(n);
    bool cross = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i;j++){
            cross = 0;
            for(auto obj : objs){
                int A = inpolygon(vp[i],obj);
                int B = inpolygon(vp[j],obj);
                if((A ^ B) % 2 || (A * B != 1 && inpolygon((vp[i] + vp[j]) * DD(0.5),obj) == 1)){
                    cross = 1;
                    break;
                }
                for(int k = 0;k < obj.n;k++){
                    lineseg ls(obj[k],obj[(k + 1) % obj.n]);
                    if(isecSS(lineseg(vp[i],vp[j]),ls) && !isecSP(ls,vp[i]) && !isecSP(ls,vp[j])){
                        cross = 1;
                        break;
                    }
                }
                if(cross)break;
            }
            if(!cross)res.add_edge({int(i),int(j),abs(vp[i] - vp[j])});
        }
    }
    return res;
}
//#undef x
//#undef y

#endif /*SORAIE_GEOMETORY_MAIN*/
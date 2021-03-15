#ifndef SORAIE_LAZYSEGTREE_ABSTRACT
#define SORAIE_LAZYSEGTREE_ABSTRACT

#include <vector>
#include <assert.h>

template<class S,S (*op)(S,S),S (*e)(),class F,S (*mapping)(F,S),F (*composition)(F,F),F(*id)()>
struct lazy_segtree_base{
    lazy_segtree_base(int _n):h(0),sz(_n){
        int x = 1;
        while(x < sz)x <<= 1,h++;
        n = x;
        data = std::vector<S>(2 * n,e());
        lazy = std::vector<F>(n,id());
    }
    lazy_segtree_base(const std::vector<S>& v):sz(v.size()){
        int x = 1;
        while(x < sz)x <<= 1,h++;
        n = x;
        data = std::vector<S>(2 * n,e());
        lazy = std::vector<F>(n,id());
        for(int i = 0;i < sz;i++)data[n + i] = v[i];
        for(int i = n - 1;i >= 1;i--)update(i);
    }
    
    void update(int l,int r,F f){
        assert(0 <= l && l <= r && r <= sz);
        if(l == r)return;
        l += n;
        r += n;
        for(int i = h;i >= 1;i--){
            if(((l >> i) << i) != l)push(l >> i);
            if(((r >> i) << i) != r)push((r - 1) >> i);
        }

        {
            int l2 = l,r2 = r;
            while(l < r){
                if(l & 1)all_apply(l++,f);
                if(r & 1)all_apply(--r,f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for(int i = 1;i <= h;i++){
            if(((l >> i) << i) != l)update(l >> i);
            if(((r >> i) << i) != r)update((r - 1) >> i);
        }
    }

    S query(int l,int r){
        assert(0 <= l && l <= r && r <= sz);
        if(l == r)return e();
        l += n;
        r += n;
        for(int i = h;i >= 1;i--){
            if(((l >> i) << i) != l)push(l >> i);
            if(((r >> i) << i) != r)push((r - 1) >> i);
        }
        S vl = e(),vr = e();
        while(l < r){
            if(l & 1)vl = op(vl,data[l++]);
            if(r & 1)vr = op(data[--r],vr);
            l >>= 1;
            r >>= 1;
        }
        return op(vl,vr);
    }

    S get(int p){
        assert(0 <= p && p <= sz);
        p += n;
        for(int i = h;i >= 1;i--)push(p >> i);
        return data[p];
    }

    void set(int p,S a){
        assert(0 <= p && p <= sz);
        p += n;
        for(int i = h;i >= 1;i--)push(p >> i);
        data[p] = a;
        for(int i = 1;i <= h;i++)update(p >> i);
    }

    void update(int p,F f){
        assert(0 <= p && p <= sz);
        p += n;
        for(int i = h;i >= 1;i--)push(p >> i);
        data[p] = mapping(f,data[p]);
        for(int i = 1;i <= h;i++)update(p >> i);
    }

    S query_all(){
        return data[1];
    }

    template <bool (*g)(S)>
    int max_right(int l){
        return max_right(l,[](S x) {return g(x);});
    }
    template <class G>
    int max_right(int l,G g){
        assert(0 <= l && l <= sz);
        assert(g(e()));
        if (l == sz) return sz;
        l += n;
        for (int i = h;i >= 1;i--)push(l >> i);
        S sm = e();
        do{
            while(l % 2 == 0)l >>= 1;
            if(!g(op(sm,data[l]))){
                while(l < n){
                    push(l);
                    l = (2 * l);
                    if(g(op(sm,data[l]))){
                        sm = op(sm,data[l]);
                        l++;
                    }
                }
                return l - n;
            }
            sm = op(sm,data[l]);
            l++;
        }while((l & -l) != l);
        return sz;
    }

    template <bool (*g)(S)>
    int min_left(int r){
        return min_left(r, [](S x){return g(x);});
    }
    template <class G>
    int min_left(int r,G g){
        assert(0 <= r && r <= sz);
        assert(g(e()));
        if(r == 0)return 0;
        r += n;
        for(int i = h;i >= 1;i--)push((r - 1) >> i);
        S sm = e();
        do{
            r--;
            while(r > 1 && (r % 2))r >>= 1;
            if(!g(op(data[r],sm))){
                while(r < n){
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(data[r],sm))){
                        sm = op(data[r],sm);
                        r--;
                    }
                }
                return r + 1 - n;
            }
            sm = op(data[r],sm);
        }while((r & -r) != r);
        return 0;
    }

private:
    int n,h,sz;
    std::vector<S> data;
    std::vector<F> lazy;

    void all_apply(int k,F f){
        data[k] = mapping(f,data[k]);
        if(k < n)lazy[k] = composition(f,lazy[k]);
    }
    void push(int k){
        all_apply(2 * k,lazy[k]);
        all_apply(2 * k + 1,lazy[k]);
        lazy[k] = id();
    }
    void update(int k){
        data[k] = op(data[2 * k],data[2 * k + 1]);
    }
};

#endif /*SORAIE_LAZYSEGTREE_ABSTRACT*/
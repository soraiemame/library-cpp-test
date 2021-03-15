#ifndef SORAIE_SCC
#define SORAIE_SCC

#include <vector>

struct SCC{
private:
    int n,k;
    std::vector<std::vector<int>> G,RG;
    std::vector<bool> use;
    std::vector<int> ret,topo;
    void dfs1(int v){
        use[v] = true;
        for(int x : G[v])if(!use[x])dfs1(x);
        ret.push_back(v);
    }
    void dfs2(int v,int k){
        topo[v] = k;
        use[v] = true;
        for(int x : RG[v])if(!use[x])dfs2(x,k);
    }
    void init(const std::vector<std::vector<int>>& _G){
        n = _G.size();k = -1;
        use.resize(n,false);topo.resize(n,0);
        G = _G;RG.resize(n);
        for(int i = 0;i < n;i++)for(const int &x : _G[i])RG[x].push_back(i);
    }
public:
    void build(){
        k = 0;
        for(int i = 0;i < n;i++)if(!use[i])dfs1(i);
        use.assign(n,false);
        for(int i = n - 1;i >= 0;i--)if(!use[ret[i]])dfs2(ret[i],k++);
    }
    std::vector<std::vector<int>> components(){
        if(k == -1)build();
        std::vector<std::vector<int>> res(k);
        for(int i = 0;i < n;i++)res[topo[i]].push_back(i);
        return res;
    }
    std::vector<std::vector<int>> compressed(){
        if(k == -1)build();
        std::vector<std::vector<int>> res(n);
        for(int i = 0;i < n;i++)for(auto x : G[i])res[topo[i]].push_back(topo[x]);
        return res;
    }
    
    SCC(int _n = 0){init(std::vector<std::vector<int>>(_n));}
    SCC(const std::vector<std::vector<int>>& _G){init(_G);}
    void add_edge(int a,int b){
        G[a].push_back(b);
        RG[b].push_back(a);
    }
};

#endif /*SORAIE_SCC*/
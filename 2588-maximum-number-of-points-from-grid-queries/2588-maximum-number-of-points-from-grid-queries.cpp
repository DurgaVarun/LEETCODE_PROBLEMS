class Solution {
public:
    inline bool check(int a,int b,int c,int d){
        return a>=0 && a<c && b>=0 && b<d;
    }
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
    vector<vector<int>>side={{-1,0},{0,-1},{0,1},{1,0}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& q) {
        set<vector<int>>st;
        vector<pair<int,int>>v(q.size());
        for(int i=0;i<q.size();i++) v[i]={q[i],i};
        sort(v.begin(),v.end());
        int q1=q.size();
        int n=grid.size(),m=grid[0].size();
        st.insert({grid[0][0],0,0});
        int last=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0]=1;
        for(int i=0;i<q1;i++){
            int k=v[i].first;
            int count=0;
            while(!st.empty()){
                vector<int> it=*st.begin();
                if(it[0]>=k) break;
                st.erase(st.begin());
                count++;
                for(auto r:side){
                    int x=r[0]+it[1],y=r[1]+it[2];
                    if(check(x,y,n,m) && vis[x][y]==0) st.insert({grid[x][y],x,y}),vis[x][y]=1; 
                }
            }
            last+=count;
            v[i].first=last;
        }
        sort(v.begin(),v.end(),comp);
        vector<int>ans(q1);
        for(int i=0;i<q1;i++) ans[i]=v[i].first;
        return ans;
    }
};
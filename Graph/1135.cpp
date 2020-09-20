#include <bits/stdc++.h>
using namespace std;
/*
Prim's Algorithm
*/
int minimumCost(int N, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> graph(N+1);
        for(auto &x:connections)                          
        {
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        vector<bool> vis(N+1,false);                       
        vector<int> min_cost(N+1,INT_MAX);                 
        auto cmp=[](const pair<int,int> &a,const pair<int,int> &b)
        {
            return a.second>b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);   //Min heap according to the weight of the edges
        pq.push({1,0}); 
        int count=0,ans=0;
        while(!pq.empty()&&count!=N)
        {
            pair<int,int> p=pq.top();
            pq.pop();
            if(vis[p.first]==true)continue;   
            count++;                               
            vis[p.first]=true;                     
            ans+=p.second;
                for(auto &x:graph[p.first])
                {
                    if(!vis[x.first] && x.second < min_cost[x.first])
                    {
                        pq.push({x.first,x.second});
                        min_cost[x.first]=x.second;
                    }
                }
               
        }
        return count==N?ans:-1;
    }

/*
Kruskals Algorithm
Time complexity:-O(ElogE)
*/

int find(int x,vector<int>& parent)
{
    return parent[x]==x?x:find(parent[x],parent);
}
int minimumCost(int N, vector<vector<int>>& connections) {
    vector<int> groups(N+1,0);
    for(int i=0;i<groups.size();i++)groups[i]=i;
    sort(connections.begin(),connections.end(),[](vector<int> &a,vector<int> &b)
            {
                return a[2]<b[2];
            });
    int ans=0,count=0;
    for(auto &x:connections)
    {
        int group1=find(x[0],groups);
        int group2=find(x[1],groups);
        if(group1!=group2)
        {
            ans+=x[2];
            groups[group1]=group2;
            count++;
            if(count==N-1)return ans;
        }
    }
    return -1;
}
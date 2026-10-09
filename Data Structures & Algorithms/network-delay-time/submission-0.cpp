class Solution {
public:
   
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    const long long INF=4e18;
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0; i<times.size(); i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }

        vector<long long> dist(n+1, INF);
        dist[k]=0;
        priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
       

        pq.push({dist[k],k});
        while(!pq.empty()){
            auto[curTime, u]=pq.top();
            pq.pop();

            for(auto e: adj[u]){
                int v=e.first;
                int time=e.second;
                if(dist[u]+time<dist[v]){
                    dist[v]=dist[u]+time;
                    pq.push({dist[v], v});
                }
            }
           
        }
        long long ans=0;
        for(int i=1; i<=n; i++){
            if(dist[i]==INF){
                return -1;
            }
            ans=max(ans, dist[i]);
        }
        return ans;
}
};

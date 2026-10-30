class Solution {
public:
    typedef tuple<int,int,int>T;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});

        }
        vector<vector<int>>distance(n,vector<int>(k+1 , INT_MAX));
        distance[0][1] = 0; // distance of node 0 with 1 consecutive character is 0
        priority_queue<T , vector<T> , greater<T>> pq; // distance , node , cnt
        pq.push({0 , 0  , 1});
        while(!pq.empty()){
            auto [dist , node , cntk] = pq.top();
            pq.pop();
            if(distance[node][cntk] < dist){
                continue;
            }
            if(node == n-1){
                return dist;
            }
            for(auto nei  : adj[node]){
                int nextnode = nei.first;
                int nextwt = nei.second;
                int newdistance = dist  + nextwt;
                int newcnt = cntk;
                if(labels[nextnode] == labels[node] ){
                    newcnt++;
                }
                else{
                    newcnt = 1;
                }
                if(newcnt > k){
                    continue;
                }
                if(distance[nextnode][newcnt] > newdistance){
                    pq.push({newdistance , nextnode , newcnt});
                    distance[nextnode][newcnt] = newdistance;
                }
            }
    
        }
        return -1;

       

        
    }
};
#ifndef KHAN_H
#define KHAN_H

#include <vector>
#include <queue>

// adjacency list represents outgoing connections
std::vector<int> KhansAlgorithm(std::vector<std::vector<int>> adj, std::size_t n){
    std::vector<int> inDegree(0,n);
    
    for(int i = 0; i < adj.size(); i++){
        for(int j = 0; j < adj[i].size(); j++){
            inDegree[adj[i][j]] += 1; // want to store the incoming node degrees
        }
    }
    
    
    std::queue<int> leafNodes;
    
    std::vector<int> result(0,n);
    int pointer = 0;

    for(int node = 0; node < n; node++){
        if (inDegree[node] == 0){
            leafNodes.push(node);
        }

    }

    while (!leafNodes.empty()){
        std::size_t queueSize = leafNodes.size();

        for(int i = 0; i < queueSize; i++){
            
            int leaf = leafNodes.front();
            leafNodes.pop();
            result[pointer] = leaf;
            pointer += 1;
            
            // adjacency should be a map

            for(auto child : adj[leaf]){

            }
        }

    }
    
    return {};
}

#endif
#ifndef KHAN_H
#define KHAN_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

// adjacency list represents outgoing connections
std::vector<int> KhansAlgorithm( std::unordered_map<int, std::vector<int>> adj, std::size_t n){
    
    // number of incoming degrees into a node ** Remember adj stores the outgoing connections (parent-child relations), we wan how many parents are pointing to child
    std::vector<int> inDegree(n,0); // size, value
    // who am I dependent on
    

    for(const auto& node : adj){
        for(int i = 0; i < node.second.size(); i++){
            inDegree[node.second[i]] += 1;
        }
    }

    
    std::queue<int> leafNodes;
    std::vector<int> result(n,0);
    int pointer = 0; // track what position we are in the sorting

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

            // store leaf node in sorting order
            result[pointer] = leaf;
            pointer += 1;
            
            // adjacency should be a map
            for(const auto &child : adj[leaf]){
                inDegree[child] -= 1;

                if (inDegree[child] == 0){
                    leafNodes.push(child);
                }
            }
        }

    }
    
    if(pointer != n){
        return {};
    }else{
        return result;
    }

}

#endif
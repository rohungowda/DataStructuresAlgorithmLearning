
#include <limits>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// returns minimum distance from a start node to every node in the graph
vector<int> Bellman_Ford(int n, int start, vector<tuple<int,int,int>> edges){

    int inf = std::numeric_limits<int>::max();

    vector<int> distance(n + 1,inf);
    distance[start] = 0;

    int hops = n - 1;

    for(int hop = 0; hop < hops; hop++){
        for(tuple<int,int,int> edge : edges){
            int u = get<0>(edge);
            int v = get<1>(edge);
            int cost = get<2>(edge);

            // u -> v
            distance[v] = min(distance[v], distance[u] + cost);
        }
    }

    return distance;
}

int main(){

    vector<tuple<int,int,int>> edges = {
        tuple<int,int,int>(1,2,6),
        tuple<int,int,int>(1,3,5),
        tuple<int,int,int>(1,4,5),
        tuple<int,int,int>(2,5,-1),
        tuple<int,int,int>(3,2,-2),
        tuple<int,int,int>(3,5,1),
        tuple<int,int,int>(4,3,-2),
        tuple<int,int,int>(4,6,-1),
        tuple<int,int,int>(5,7,3),
        tuple<int,int,int>(6,7,3),
    };

    int nodes = 7;

    vector<int> res = Bellman_Ford(7, 1, edges);

    for(int cost : res){
        cout << cost << endl;
    }

    return 0;
}
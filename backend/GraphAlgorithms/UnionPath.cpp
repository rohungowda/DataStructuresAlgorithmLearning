#include <limits>
#include <vector>
#include <unordered_map>
#include <iostream>

#include <numeric>

using namespace std;

class UnionPath{
    public:
        // makeSet
        UnionPath(int n) 
        : parents(n), rank(n,0)
        {
            iota(parents.begin(), parents.end(), 0);
        }

    int findSet(int node){
        if(node == parents[node]){
            return node;
        }
        parents[node] = findSet(parents[node]);
        return parents[node];
    }

    void merge(int nodeA, int nodeB){
        int parentA = findSet(nodeA);
        int parentB = findSet(nodeB);

        if(parentA == parentB){
            return;
        }

        if(rank[parentA] > rank[parentB]){
            parents[parentB] = parentA;
        }else if(rank[parentA] < rank[parentB]){
            parents[parentA] = parentB;
        }else{
            parents[parentB] = parentA;
            rank[parentA] += 1;
        }

    }

    
    private:
        vector<int> parents;
        vector<int> rank;

};

int main(){

    UnionPath path(9);

    vector<vector<int>> unions = {{1,2},{2,3},{4,5},{6,7},{5,6}};

    for(vector<int> pair : unions){
        int a = pair[0];
        int b = pair[1];
        path.merge(a,b);
        
        for(int i = 0; i < 9; i++){
            cout << path.findSet(i) << " ";
        }
        cout << endl;
    
    }

    return 0;
}
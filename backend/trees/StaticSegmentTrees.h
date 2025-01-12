#ifndef STATICSEGMENTTREES_H
#define STATICSEGMENTTREES_H

#include <vector>
#include <cmath> 
#include <functional>

#include <iostream>

template <typename T, typename Comparator = std::less<T>>
class StaticSegmentTrees
{
private:
    int n;
    std::vector<T> data;
    T NULL_;
    Comparator compare;

    void constructTree(std::vector<T> &input, int low, int high, int pos){
        int m = low + (high - low) / 2;
        if(low == high){
            data[pos] = input[low]; // low == high is the leaf node and as such corresponds with the correct index in the array
            return;
        }
        constructTree(input, low, m, (2*pos + 1)); // left child search
        constructTree(input, m+1, high, (2*pos + 2)); // right child search

        data[pos] = compare(data[(2*pos + 1)],data[(2*pos + 2)]) ? data[(2*pos + 1)] : data[(2*pos + 2)];
    }

    T rangeQuery(int qlow, int qhigh, int low, int high, int pos){
        if (qlow <= low && qhigh >= high){
            return data[pos];
        }
        if (qlow > high || qhigh < low){
            return NULL_;
        }

        int m = low + (high - low) / 2;
        T left = rangeQuery(qlow,qhigh,low,m,(2*pos + 1));
        T right = rangeQuery(qlow,qhigh,m+1,high,(2*pos + 2));
        return compare(left,right) ? left : right;
    }

public:
    StaticSegmentTrees(T NUL)
    : n(0), data(0), NULL_(NUL), compare(Comparator()) // 2^(log_2(size)) - 1
    {}

    void build(std::vector<T> &input){
        n = input.size();

        int allocate = static_cast<int>(2 * (pow(2,ceil(log2(n)))) - 1);
        data.resize(allocate, NULL_);
        constructTree(input, 0,n - 1,0);

    }


    T Query(int qlow, int qhigh){

        return rangeQuery(qlow,qhigh,0,n-1,0);
    }

    void print(){
        for(auto el : data){
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }


};



#endif
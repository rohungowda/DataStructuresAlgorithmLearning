#include "trees/StaticSegmentTrees.h"

#include <iostream>

int main(){

    int max = std::numeric_limits<int>::max();

    std::vector<int> test = {33,5,34,23,34,543,4,2,1,45,6};

    StaticSegmentTrees tree = StaticSegmentTrees(max);
    tree.build(test);
    std::cout << tree.Query(0,5) << std::endl;
    std::cout << tree.Query(1,8) << std::endl;
    std::cout << tree.Query(13,13) << std::endl;
    std::cout << tree.Query(6,9) << std::endl;

    return 0;
}
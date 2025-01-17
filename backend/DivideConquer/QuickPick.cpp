
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>


// maxHeap automatically is one
// heapq tokes n log(k) to find the element
// QuickPick should take O(n)

int QuickPick(std::vector<int> S, int k){
    if (k <= 5){
         std::sort(S.begin(), S.end());
        
        return S[k];
    }else{
        // divide S into len(s)/5 groupsof 5 + remainder
        int groups = S.size() / 5;
        int remainder = S.size() % 5;
        std::vector<int>::iterator start = S.begin();
        std::vector<int>::iterator end = (S.begin() + 5);

        std::vector<int> medians;

        for(int i= 0; i < groups; i++){

            std::sort(start,end);
            medians.push_back(*(start + 2));

            start += 5;
            if (i != (groups - 1)){
                end += 5;
            }
        }

        if (remainder){
            end = start + remainder;
            std::sort(start,end);

            int k = remainder / 2;
            medians.push_back(*(start + k));
        }

        
        for(auto element : medians){
            std::cout << element <<  " ";
        }
        std::cout << std::endl;

        for(auto element : S){
            std::cout << element <<  " ";
        }
        std::cout << std::endl;


        int e = QuickPick(medians, (medians.size() / 2));
        return e;

    }

    return 0;
}

int main(){

    std::vector<int> test = {2,5,2,4,5,1,7,3,3,3,5,2,9};
    std::cout << QuickPick(test,8) << std::endl;

    return 0;
}

/*
        for(auto element : medians){
            std::cout << element <<  " ";
        }
        std::cout << std::endl;

        for(auto element : S){
            std::cout << element <<  " ";
        }
        std::cout << std::endl;
*/
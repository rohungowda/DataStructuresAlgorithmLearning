
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>


// maxHeap automatically is one
// heapq tokes n log(k) to find the element
// QuickPick should take O(n)

// [l, r)
int QuickPick(std::vector<int>S, int k, int l, int r){
        if (k <= 5){
            std::priority_queue<int> pq;
            for(int i = l; i < r; i++){
                pq.push(S[i]);

                if (pq.size() > k){
                    pq.pop();
                }
            }

            return pq.top();
        }else{

        int groups = (r-l) / 5;
        int remainder = (r-l) % 5;

        std::vector<int> medians;

        for(int i= 0; i < groups; i+=1){
            int start = (l + (i*5));
            std::sort(S.begin() + start, S.begin() + start + 5);
            int median = (start + (start + 4)) / 2;
            medians.push_back(S[median]);

        }

        if (remainder){
            int start = (r - remainder);
            std::sort(S.begin() + start, S.begin() + r);
            int median = (start + (r-1)) / 2;
            medians.push_back(S[median]);
        }

        int e = QuickPick(medians, (medians.size() / 2) + 1, 0, medians.size());

        int pointerL = l;
        int pointerM = l;
        int pointerH = r - 1;

        // Dutch Flag Partition
        while(pointerM <= pointerH){
            if (S[pointerM] == e){
                pointerM += 1;
            } else if(S[pointerM] < e){
                std::swap(S[pointerM], S[pointerL]);
                pointerM += 1;
                pointerL += 1;

            }else{
                std::swap(S[pointerM], S[pointerH]);
                pointerH -= 1;
            }
        }


        int rank = (pointerL - l) + 1;

        if (k >= rank && k < ((pointerM-l)+1)){
            return e;
        }

        if (k < rank){
            return QuickPick(S, k, l, pointerL);
        }else{
            return QuickPick(S, k - (pointerM - l), pointerM, r);
        }

    }
}

int main(){

    std::vector<int> test;
    std::random_device rd;

    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(-21785, 21785);

    for (int i = 0; i < 50000; ++i) {
        test.push_back(distr(gen));
    }
    
    std::uniform_int_distribution<> dist(1, test.size());
    std::vector<int> saved = test;

    auto start = std::chrono::high_resolution_clock::now();
    std::sort(saved.begin(), saved.end());
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Time to Beat: Sort: " << elapsed.count() << " ms\n" << std::endl;

    for(int i = 0; i < 3; i++){

        int random = dist(gen);
        std::cout << "Pick the " << random << "th smallest element" << std::endl;

        auto start = std::chrono::high_resolution_clock::now();
        int element = QuickPick(test, random, 0 , test.size());
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << "Elapsed time for QuickPick: " << elapsed.count() << " ms\n";


        if(saved[(random-1)] != element){
            for(auto element : test){
            std::cout << element <<  " ";
            }
            std::cout << std::endl;
            std::cout << "Test FAILED, expected: " << saved[random] << " got " << element << std::endl;
            return 1;
        }

        std::cout << "Sort: " << saved[(random-1)] << " / QuickPick: " << element << std::endl;

        std::cout << "--------------------------------" << std::endl;
    }



    return 0;
}

/*



    std::cout << std::endl;


        for(auto element : medians){
            std::cout << element <<  " ";
        }
        std::cout << std::endl;

        for(auto element : S){
            std::cout << element <<  " ";
        }
        std::cout << std::endl;
*/
#define BOOST_TEST_MODULE dataset_example68
#include "../../trees/StaticSegmentTrees.h"
#include "../../trees/AddSegmentTrees.h"
#include <climits>

#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <vector>

namespace bdata = boost::unit_test::data;


// Dynamic Segment Tree

std::vector<int> data = {10, 5, 8, 15, 3, 7, 12, 2, 9, 4};

std::vector<std::pair<int, int>> ranges = {
    {0, 3}, {2, 5}, {4, 6}, {1, 8}, {0, 9}, {3, 7}, {2, 7}, {5, 9}, {1, 4}, {0, 6}
};

std::vector<int> test = {5, 3, 3, 2, 2, 2, 2, 2, 3, 3};

std::vector<int> check(){
    StaticSegmentTrees<int> tree = StaticSegmentTrees<int>(INT_MAX);
    tree.build(data);
    std::vector<int> result(data.size(),0);
    for(int i = 0; i < ranges.size(); i++){
        auto [l,r] = ranges[i];
        result[i] = tree.Query(l,r);
    }

    return result;
}







BOOST_DATA_TEST_CASE(
    test1,
    bdata::make(test) ^ bdata::make(check()), 
    rangeQuery, exp)
{
      BOOST_TEST(rangeQuery == exp);
}


// dataset generator code
/*
template <typename T>
class SegmentTree_dataset {
    public:

        static const int arity = 1;

        struct iterator{
        public:
            iterator(std::vector<T> &data)
            : ref(data) {}

            int operator*() const   { return ref[i]; }
            
            void operator++()
            {
                i += 1;
            }

        private:
            std::vector<T> ref;
            int i = 0;
        };

        SegmentTree_dataset(std::vector<T> &data)
        : iter(data), n(data.size())
        {}

        bdata::size_t size() const { 
            return n; 
        }

        iterator begin() const {
            return iter; 
            }

    private:
        iterator iter;
        size_t n;

};

namespace boost { namespace unit_test { namespace data { namespace monomorphic {
  // registering fibonacci_dataset as a proper dataset
  template <>
  struct is_dataset<SegmentTree_dataset<int>> : boost::mpl::true_ {};
}}}}

*/
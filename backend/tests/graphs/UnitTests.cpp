#define BOOST_TEST_MODULE dataset_example68
#include "../../DependencySortAlgorithms/khan.h"


#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <vector>

namespace bdata = boost::unit_test::data;




std::vector<int> check2(){
    size_t n = 9;

    std::unordered_map<int,std::vector<int>> adj = {
        {0, {1,2}},
        {1, {2}},
        {3, {1}},
        {4, {2}},
        {5, {3}},
        {6, {3}},
        {7, {3}},
        {8, {7}}

    };

    std::vector<int> result = KhansAlgorithm(adj,n);

    return result;
}


std::vector<int> test3 = {0, 4, 5, 6, 8, 7, 3, 1, 2};




BOOST_DATA_TEST_CASE(
    test2,
    bdata::make(test3) ^ bdata::make(check2()), 
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
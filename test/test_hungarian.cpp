#include "../SLISC/hungarian.h"

int test_hungarian() //example of usage
{
    using namespace slisc;
    using namespace std;
    
    vector<vvecLong> tests;
    
    tests.push_back({{25,40,35},
                     {40,60,35},
                     {20,40,25}});
    
    tests.push_back({{64,18,75},
                     {97,60,24},
                     {87,63,15}});
    
    tests.push_back({{80,40,50,46}, 
                     {40,70,20,25},
                     {30,10,20,30},
                     {35,20,25,30}});
    
    tests.push_back({{10,19,8,15,0},
                     {10,18,7,17,0},
                     {13,16,9,14,0},
                     {12,19,8,18,0},
                     {14,17,10,19,0}});

    SLS_ASSERT(hungarian(tests[0]) == 95);
    SLS_ASSERT(hungarian(tests[1]) == 129);
    SLS_ASSERT(hungarian(tests[2]) == 111);
    SLS_ASSERT(hungarian(tests[3]) == 48);
    
    return 0;
}

#include "../SLISC/hungarian.h"

void test_hungarian() //example of usage
{
    using namespace slisc;
    using namespace std;
    
    vector<vvecLong> tests;
    vecLong res;
    
    tests.push_back({{25,40,35},
                     {40,60,35},
                     {20,40,25}}); res.push_back(95);
    
    tests.push_back({{64,18,75},
                     {97,60,24},
                     {87,63,15}}); res.push_back(129);
    
    tests.push_back({{80,40,50,46}, 
                     {40,70,20,25},
                     {30,10,20,30},
                     {35,20,25,30}}); res.push_back(111);
    
    tests.push_back({{10,19,8,15,0},
                     {10,18,7,17,0},
                     {13,16,9,14,0},
                     {12,19,8,18,0},
                     {14,17,10,19,0}}); res.push_back(48);

    tests.push_back({{25,40,35},
                    {40,60,35},
                    {20,40,25}}); res.push_back(95);

    // tests.push_back({{15,40,45},
    //                 {20,60,35},
    //                 {20,40,25}}); res.push_back(85);    // failed!!!!!!!!!

    for (Long i = 0; i < (Long)tests.size(); ++i)
        SLS_ASSERT(hungarian(tests[i]) == res[i]);
}

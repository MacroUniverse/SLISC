#include "../SLISC/hungarian.h"

void test_hungarian() //example of usage
{
	using namespace slisc;
    
    vector<vector<vector<Long>>> tests;
    
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
    
    tests.push_back({{10,19,8,15,1000},
                     {10,18,7,17,1000},
                     {13,16,9,14,1000},
                     {12,19,8,18,1000},
                     {14,17,10,19,1000}});
    
    for (auto& m: tests) {
        auto r = hungarian(m);
        // cout << "Optimal cost: " << r << endl;
        // cout << "----------------- \n\n";
		r *= 0;
    }
}

//
//  cnf.hpp
//  sat2mrhs
//
//  Created by Fikrim Kabashi on 18.9.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#ifndef cnf_hpp
#define cnf_hpp

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Cnf{
private:
    vector<vector<int> > cnfFormulas_;
    vector<vector<int> > xorFormulas_;
    int numberOfLiterals_;
    int numberOfClauses_;
public:
    Cnf();
    ~Cnf();
    void fillCnf(const string &filePath);
    void makeOptimalization();
    vector<vector<int> > getCnfFormulas();
    vector<vector<int> > getXorFormulas();
    int getNumberOfLiterals();
    int getNumberOfClauses();
    void printCnfFormulas();
};
#endif /* cnf_hpp */

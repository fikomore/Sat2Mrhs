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
    vector<vector<int> > cnf_formulas_;
    vector<vector<int> > xor_formulas_;
    int number_of_literals_;
    int number_of_clauses_;
public:
    Cnf();
    ~Cnf();
    void FillCnf(const string &filePath);
    void MakeOptimalization();
    vector<vector<int> > GetCnfFormulas();
    vector<vector<int> > GetXorFormulas();
    int GetNumberOfLiterals();
    int GetNumberOfClauses();
    void PrintCnfFormulas();
};
#endif /* cnf_hpp */

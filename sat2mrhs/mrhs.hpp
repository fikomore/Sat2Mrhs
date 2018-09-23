//
//  mrhs.hpp
//  sat2mrhs
//
//  Created by Fikrim Kabashi on 19.9.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#ifndef mrhs_hpp
#define mrhs_hpp

#include <stdio.h>
#include <vector>

using namespace std;

class Mrhs{
private:
    vector<vector<vector<int> > > big_block_;
    vector<vector<vector<int> > > right_sides_;
public:
    Mrhs();
    ~Mrhs();
    
    void CreatBlocksFromCnfFormulas(vector<vector<int> > cnfFormulas, int numberOfLiterals);
    void CreatBlocksFromXorFormulas(vector<vector<int> > xorFormulas, int numberOfLiterals);
    void FillBigBlock(vector<vector<int> > cnfFormulas, vector<vector<int> > xorFormulas, int numberOfLiterals);
    
    void CreatRightSidesFromCnfFormulas(vector<vector<int> > cnfFormulas);
    void CreatRightSidesFromXorFormulas(vector<vector<int> > xorFormulas);
    void FillRightSides(vector<vector<int> > cnfFormulas, vector<vector<int> > xorFormulas);
    
    vector<vector<int> > CreatTruthTable(int n);
    vector<int> FindForbidenCombination(vector<int> cnfFormula);
    void RemoveForbidenCombination(vector<vector<int> > &rightSides, vector<int> forbidenCombination);
    
    vector<vector<vector<int> > > GetBigBlock();
    vector<vector<vector<int> > > GetRightSides();
    
    void PrintBigBlock(int numberOfLiterals);
    void PrintRightSides();
};
#endif /* mrhs_hpp */

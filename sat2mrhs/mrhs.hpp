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
    vector<vector<vector<int> > > bigBlock_;
    vector<vector<vector<int> > > rightSides_;
public:
    Mrhs();
    ~Mrhs();
    
    void creatBlocksFromCnfFormulas(vector<vector<int> > cnfFormulas, int numberOfLiterals);
    void creatBlocksFromXorFormulas(vector<vector<int> > xorFormulas, int numberOfLiterals);
    void fillBigBlock(vector<vector<int> > cnfFormulas, vector<vector<int> > xorFormulas, int numberOfLiterals);
    
    void creatRightSidesFromCnfFormulas(vector<vector<int> > cnfFormulas);
    void creatRightSidesFromXorFormulas(vector<vector<int> > xorFormulas);
    void fillRightSides(vector<vector<int> > cnfFormulas, vector<vector<int> > xorFormulas);
    
    vector<vector<int> > creatTruthTable(int n);
    vector<int> findForbidenCombination(vector<int> cnfFormula);
    void removeForbidenCombination(vector<vector<int> > &rightSides, vector<int> forbidenCombination);
    
    vector<vector<vector<int> > > getBigBlock();
    vector<vector<vector<int> > > getRightSides();
    
    void printBigBlock(int numberOfLiterals);
    void printRightSides();
};
#endif /* mrhs_hpp */

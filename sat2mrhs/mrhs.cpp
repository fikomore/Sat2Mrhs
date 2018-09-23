//
//  mrhs.cpp
//  sat2mrhs
//
//  Created by Fikrim Kabashi on 19.9.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#include "mrhs.hpp"
#include <bitset>
#include <math.h>
#include <boost/dynamic_bitset.hpp>
#include "iostream"

Mrhs::Mrhs() {
    
}

Mrhs::~Mrhs() {
    
}

void Mrhs::CreatBlocksFromCnfFormulas(vector<vector<int> > cnfFormulas, int numberOfLiterals) {
    for (int i=0; i<cnfFormulas.size(); i++) {
        vector<vector<int> > tmpBlock;
        for (int j=0; j<numberOfLiterals; j++) {
            vector<int> tmpLine;
            for (int k=0; k<cnfFormulas[i].size(); k++) {
                if (cnfFormulas[i][k] == (j+1) || cnfFormulas[i][k] == -(j+1)) {
                    tmpLine.push_back(1);
                }
                else {
                    tmpLine.push_back(0);
                }
            }
            tmpBlock.push_back(tmpLine);
        }
        big_block_.push_back(tmpBlock);
    }
}

void Mrhs::CreatBlocksFromXorFormulas(vector<vector<int> > xorFormulas, int numberOfLiterals) {
    for (int i=0; i<xorFormulas.size(); i++) {
        vector<vector<int> > tmpBlock;
        for (int j=0; j<numberOfLiterals; j++) {
            vector<int> tmpLine;
            for (int k=0; k<xorFormulas[i].size(); k++) {
                if (xorFormulas[i][k] == (j+1) || xorFormulas[i][k] == -(j+1)) {
                    tmpLine.push_back(1);
                    break;
                }
            }
            if (tmpLine.empty()) {
                tmpLine.push_back(0);
            }
            tmpBlock.push_back(tmpLine);
        }
        big_block_.push_back(tmpBlock);
    }
}

void Mrhs::FillBigBlock(vector<vector<int> > cnfFormulas, vector<vector<int> > xorFormulas, int numberOfLiterals) {
    CreatBlocksFromCnfFormulas(cnfFormulas, numberOfLiterals);
    CreatBlocksFromXorFormulas(xorFormulas, numberOfLiterals);
}

void Mrhs::CreatRightSidesFromCnfFormulas(vector<vector<int> > cnfFormulas) {
    for (int i = 0; i < cnfFormulas.size(); i++) {
        vector<vector<int> > rightSides = CreatTruthTable(cnfFormulas[i].size());
        vector<int> forbidenCombination = FindForbidenCombination(cnfFormulas[i]);
        RemoveForbidenCombination(rightSides, forbidenCombination);
        right_sides_.push_back(rightSides);
    }
    
}

vector<vector<int> > Mrhs::CreatTruthTable(int n) {
    std::vector<vector<int> > result;
    int maxValue = 1<<n;
    for (int i = maxValue; i > 0; i--) {
        boost::dynamic_bitset<> bs(n, (maxValue - i));
        vector<int> row;
        for (int j = 0; j < n; j++) {
            row.push_back(bs[j]);
        }
        result.push_back(row);
    }
    return result;
}

vector<int> Mrhs::FindForbidenCombination(vector<int> cnfFormula) {
    std::vector<int> result;
    for(int i=0;i<cnfFormula.size();i++){
        if(cnfFormula[i]>0)
            result.push_back(0);
        else
            result.push_back(1);
    }
    return result;
}

void Mrhs::RemoveForbidenCombination(vector<vector<int> > &rightSides, vector<int> forbidenCombination) {
    int counter =0;
    for(std::vector<std::vector<int> >::const_iterator i=rightSides.begin();i!=rightSides.end();i++){
        if(*i==forbidenCombination){
            rightSides.erase(rightSides.begin()+counter);
            break;
        }
        counter++;
    }
}

void Mrhs::FillRightSides(vector<vector<int> > cnfFormulas, vector<vector<int> > xorFormulas) {
    CreatRightSidesFromCnfFormulas(cnfFormulas);
}

vector<vector<vector<int> > > Mrhs::GetBigBlock() {
    return big_block_;
}

vector<vector<vector<int> > > Mrhs::GetRightSides() {
    return right_sides_;
}

void Mrhs::PrintBigBlock(int numberOfLiterals){
    cout<<" ";
    for (int i = 0; i < numberOfLiterals; i++) {
        cout<<"[";
        for (int j = 0; j <big_block_.size(); j++) {
            for (int k = 0; k< big_block_[j][i].size(); k++) {
                cout<<big_block_[j][i][k];
                if (k+1 != big_block_[j][i].size()) {
                    cout<<" ";
                }
            }
            if(j != big_block_.size()-1) {
                cout<<" ";
            }
        }
        cout<<"]\n";
    }
}

void Mrhs::PrintRightSides() {
    cout<<"\n";
    for (int i=0; i<right_sides_.size(); i++) {
        for (int j=0; j<right_sides_[i].size(); j++) {
            cout<<"[";
            for (int k=0; k<right_sides_[i][j].size(); k++) {
                cout<<right_sides_[i][j][k]<<" ";
            }
            cout<<"]\n";
        }
        cout<<"\n";
    }
}

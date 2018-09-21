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

void Mrhs::creatBlocksFromCnfFormulas(vector<vector<int> > cnfFormulas, int numberOfLiterals) {
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
        bigBlock_.push_back(tmpBlock);
    }
}

void Mrhs::creatBlocksFromXorFormulas(vector<vector<int> > xorFormulas, int numberOfLiterals) {
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
        bigBlock_.push_back(tmpBlock);
    }
}

void Mrhs::fillBigBlock(vector<vector<int> > cnfFormulas, vector<vector<int> > xorFormulas, int numberOfLiterals) {
    creatBlocksFromCnfFormulas(cnfFormulas, numberOfLiterals);
    creatBlocksFromXorFormulas(xorFormulas, numberOfLiterals);
}

void Mrhs::creatRightSidesFromCnfFormulas(vector<vector<int> > cnfFormulas) {
    for (int i = 0; i < cnfFormulas.size(); i++) {
        vector<vector<int> > rightSides = creatTruthTable(cnfFormulas[i].size());
        vector<int> forbidenCombination = findForbidenCombination(cnfFormulas[i]);
        removeForbidenCombination(rightSides, forbidenCombination);
        rightSides_.push_back(rightSides);
    }
    
}

vector<vector<int> > Mrhs::creatTruthTable(int n) {
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

vector<int> Mrhs::findForbidenCombination(vector<int> cnfFormula) {
    std::vector<int> result;
    for(int i=0;i<cnfFormula.size();i++){
        if(cnfFormula[i]>0)
            result.push_back(0);
        else
            result.push_back(1);
    }
    return result;
}

void Mrhs::removeForbidenCombination(vector<vector<int> > &rightSides, vector<int> forbidenCombination) {
    int counter =0;
    for(std::vector<std::vector<int> >::const_iterator i=rightSides.begin();i!=rightSides.end();i++){
        if(*i==forbidenCombination){
            rightSides.erase(rightSides.begin()+counter);
            break;
        }
        counter++;
    }
}

void Mrhs::fillRightSides(vector<vector<int> > cnfFormulas, vector<vector<int> > xorFormulas) {
    creatRightSidesFromCnfFormulas(cnfFormulas);
}

vector<vector<vector<int> > > Mrhs::getBigBlock() {
    return bigBlock_;
}

vector<vector<vector<int> > > Mrhs::getRightSides() {
    return rightSides_;
}

void Mrhs::printBigBlock(int numberOfLiterals){
    cout<<" ";
    for (int i = 0; i < numberOfLiterals; i++) {
        cout<<"[";
        for (int j = 0; j <bigBlock_.size(); j++) {
            for (int k = 0; k< bigBlock_[j][i].size(); k++) {
                cout<<bigBlock_[j][i][k];
                if (k+1 != bigBlock_[j][i].size()) {
                    cout<<" ";
                }
            }
            if(j != bigBlock_.size()-1) {
                cout<<" ";
            }
        }
        cout<<"]\n";
    }
}

void Mrhs::printRightSides() {
    cout<<"\n";
    for (int i=0; i<rightSides_.size(); i++) {
        for (int j=0; j<rightSides_[i].size(); j++) {
            cout<<"[";
            for (int k=0; k<rightSides_[i][j].size(); k++) {
                cout<<rightSides_[i][j][k]<<" ";
            }
            cout<<"]\n";
        }
        cout<<"\n";
    }
}

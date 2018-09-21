//
//  engine.cpp
//  sat2mrhs
//
//  Created by Fikrim Kabashi on 18.9.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#include "engine.hpp"
#include <iostream>

Engine::Engine(const string &filePath) {
    cnf_.fillCnf(filePath);
    cnf_.printCnfFormulas();
    mrhs_.fillBigBlock(cnf_.getCnfFormulas(), cnf_.getXorFormulas(), cnf_.getNumberOfLiterals());
    mrhs_.fillRightSides(cnf_.getCnfFormulas(), cnf_.getXorFormulas());
    mrhs_.printBigBlock(cnf_.getNumberOfLiterals());
    mrhs_.printRightSides();
}


Engine::~Engine() {

}

void Engine::printCnf() {
    for (int i=0; i<cnf_.getCnfFormulas().size(); i++) {
        for (int j=0; j<cnf_.getCnfFormulas()[i].size(); j++) {
            cout<<cnf_.getCnfFormulas()[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Pocet klauzul je: "<<cnf_.getNumberOfClauses()<<"\n";
    cout<<"Pocet literalov je:"<<cnf_.getNumberOfLiterals()<<"\n";
}

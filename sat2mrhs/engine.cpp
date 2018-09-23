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
    cnf_.FillCnf(filePath);
    cnf_.PrintCnfFormulas();
    mrhs_.FillBigBlock(cnf_.GetCnfFormulas(), cnf_.GetXorFormulas(), cnf_.GetNumberOfLiterals());
    mrhs_.FillRightSides(cnf_.GetCnfFormulas(), cnf_.GetXorFormulas());
    mrhs_.PrintBigBlock(cnf_.GetNumberOfLiterals());
    mrhs_.PrintRightSides();
}


Engine::~Engine() {

}

void Engine::PrintCnf() {
    for (int i=0; i<cnf_.GetCnfFormulas().size(); i++) {
        for (int j=0; j<cnf_.GetCnfFormulas()[i].size(); j++) {
            cout<<cnf_.GetCnfFormulas()[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"Pocet klauzul je: "<<cnf_.GetNumberOfClauses()<<"\n";
    cout<<"Pocet literalov je:"<<cnf_.GetNumberOfLiterals()<<"\n";
}

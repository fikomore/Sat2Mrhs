//
//  cnf.cpp
//  sat2mrhs
//
//  Created by Fikrim Kabashi on 18.9.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#include "cnf.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>



Cnf::Cnf () {
    
}

Cnf::~Cnf() {
    
}

void Cnf::fillCnf(const string &filePath) {
    ifstream in;                    //in(filePath) nefunguje preco??
    in.open(filePath);
    if(in.is_open()) {
        string line;
        while (getline(in, line)) {
            if (line.at(0) == 'c') {
                continue;
            }else if (line.at(0) == 'p'){
                stringstream confLine(line.substr(5));
                confLine>>numberOfLiterals_;
                confLine>>numberOfClauses_;
            }else if (line.at(0) == '-' || isdigit(line.at(0)) ) {
                istringstream is(line);
                vector<int> vec;
                int n;
                while (is>>n) {
                    vec.push_back(n);
                }
                vec.pop_back();
                cnfFormulas_.push_back(vec);
                if (in.eof()) {
                    break;
                }
            }else if (line.at(0) == 'x') {
                istringstream is(line.substr(1));
                vector<int> vec;
                int n;
                while (is>>n) {
                    vec.push_back(n);
                }
                xorFormulas_.push_back(vec);
                if(in.eof()) {
                    break;
                }
            }
        }
    } else {
        cerr<<"Unable to open file: "<<filePath<<endl;
    }
    in.close();
}

vector<vector<int> > Cnf::getCnfFormulas() {
    return cnfFormulas_;
}

vector<vector<int> > Cnf::getXorFormulas() {
    return xorFormulas_;
}

int Cnf::getNumberOfLiterals() {
    return numberOfLiterals_;
}

int Cnf::getNumberOfClauses() {
    return numberOfClauses_;
}

void Cnf::printCnfFormulas() {
    for (int i = 0; i < cnfFormulas_.size(); i++) {
        for (int j = 0; j < cnfFormulas_[i].size(); j++) {
            cout<<cnfFormulas_[i][j]<<" ";
        }
        cout<<"\n";
    }
}

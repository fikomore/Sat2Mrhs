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

void Cnf::FillCnf(const string &filePath) {
    ifstream in;                    //in(filePath) nefunguje preco??
    in.open(filePath);
    if(in.is_open()) {
        string line;
        while (getline(in, line)) {
            if (line.at(0) == 'c') {
                continue;
            }else if (line.at(0) == 'p'){
                stringstream confLine(line.substr(5));
                confLine>>number_of_literals_;
                confLine>>number_of_clauses_;
            }else if (line.at(0) == '-' || isdigit(line.at(0)) ) {
                istringstream is(line);
                vector<int> vec;
                int n;
                while (is>>n) {
                    vec.push_back(n);
                }
                vec.pop_back();
                cnf_formulas_.push_back(vec);
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
                xor_formulas_.push_back(vec);
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

vector<vector<int> > Cnf::GetCnfFormulas() {
    return cnf_formulas_;
}

vector<vector<int> > Cnf::GetXorFormulas() {
    return xor_formulas_;
}

int Cnf::GetNumberOfLiterals() {
    return number_of_literals_;
}

int Cnf::GetNumberOfClauses() {
    return number_of_clauses_;
}

void Cnf::PrintCnfFormulas() {
    for (int i = 0; i < cnf_formulas_.size(); i++) {
        for (int j = 0; j < cnf_formulas_[i].size(); j++) {
            cout<<cnf_formulas_[i][j]<<" ";
        }
        cout<<"\n";
    }
}

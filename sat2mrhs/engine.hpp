//
//  engine.hpp
//  sat2mrhs
//
//  Created by Fikrim Kabashi on 18.9.18.
//  Copyright © 2018 Fikrim Kabashi. All rights reserved.
//

#ifndef engine_hpp
#define engine_hpp

#include <stdio.h>
#include "cnf.hpp"
#include "mrhs.hpp"
#include <string>

using namespace std;

class Engine{
private:
    Cnf cnf_;
    Mrhs mrhs_;
public:
    Engine (const string &filePath);
    ~Engine ();
    
    void printCnf();
};
#endif /* engine_hpp */

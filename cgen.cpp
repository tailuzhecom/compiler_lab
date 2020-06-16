//
// Created by young on 2020/6/15.
//

#include "cgen.h"
#include <iostream>

Program::Program() {
    std::cout << "Program is created" << std::endl;
}



Beg::Beg() {
    name_ = "beg";
}

void Beg::Show() {
    std::cout << name_ << std::endl;
}
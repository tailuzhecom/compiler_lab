//
// Created by young on 2020/6/15.
//

#include "cgen.h"
#include <iostream>

Program::Program() {
    std::cout << "Program is created" << std::endl;
}

void Program::Append(Beg *b) {
    begs_.push_back(b);
}

void Program::Traverse() {
    for (int i = 0; i < begs_.size(); i++)
        begs_[i]->Show();
}

Beg::Beg() {
    name_ = "beg";
}

void Beg::Show() {
    std::cout << name_ << std::endl;
}
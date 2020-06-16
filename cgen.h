//
// Created by young on 2020/6/15.
//

#ifndef LAB2_CGEN_H
#define LAB2_CGEN_H

#include <vector>
#include <string>

class Beg;

class Program {
public:
    Program();
    void Append(Beg *b);
    void Traverse();

private:
    std::vector<Beg*> begs_;
};

class Beg {
public:
    Beg();
    void Show();

private:
    std::string name_;
};


#endif //LAB2_CGEN_H

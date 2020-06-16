#include <vector>
#include <iostream>
#include <string>

class Beg;

class Program {
public:
    void Append(Beg *b) {
        begs_.push_back(b);
    }

    void Traverse() {
        for (int i = 0; i < begs_.size(); i++)
            begs_[i]->Show();
    }

private:
    std::vector<Beg*> begs_;
};

class Beg {
public:
    Beg() {
        name_ = "beg";
    }

    void Show() {
        std::cout << name_ << std::endl;
    }

private:
    std::string name_;
};

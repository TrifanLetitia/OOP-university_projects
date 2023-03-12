//
// Created by Leti on 28.04.2022.
//

#include "Friendship.h"
#include "../../Utils/utils.h"

std::string Friendship::getEmail1() const {
    return this->email1;
}

std::string Friendship::getEmail2() const {
    return this->email2;
}

void Friendship::setEmail1(const string& e1 ){
    this->email1 = e1;
}

void Friendship::setEmail2(const string& e2) {
    this->email2 =e2;
}


Friendship &Friendship::operator=(const Friendship &f) {
    if (this != &f) {
        this->setEmail1(f.email1);
        this->setEmail2(f.email2);
    }
    return *this;
}

bool Friendship::operator==(const Friendship &f) const {
    return (this->email1 == f.email1) && (this->email2 == f.email2);
}

ostream &operator<<(ostream &os, const Friendship &f) {
    os << "Friend 1: " << f.email1 << " Friend 2: " << f.email2;
    return os;
}

Friendship::Friendship(const string& email1, const string& email2) : email1(email1), email2(email2) {
}

Friendship::Friendship(const Friendship &f) {
    this-> email1 = f.email1;
    this->email2 = f.email2;
}

void Friendship::loadFromString(const string &args, char sep) {
    List<string> elements = split(args, sep);
    if (elements.Size() == 2){
        this->email1 = elements[0];
        this->email2 = elements[1];
    }
    else{
        throw invalid_argument("nr invalid de argumente in stringul ce tb parsat");
    }
}

string Friendship::toStringDelimiter(char sep) const {
    return this->email1 + sep + this->email2;
}

Friendship::Friendship(string args, char sep) {
    this->loadFromString(args, sep);
}


Friendship::Friendship() = default;

Friendship::~Friendship() = default;

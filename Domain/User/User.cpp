//
// Created by Leti on 28.04.2022.
//

#include "User.h"
#include "../../Utils/utils.h"
string User::getName() const {
    return this->name;
}


void User::setName(const string &n) {
    this->name = n;
}


ostream &operator<<(ostream &os, const User &u) {
    os << "User"<< " name: " << u.name << " || Age: " << u.age << " || Email: " << u.email;
    return os;
}

int User::getAge() const {
    return this->age;
}

User::User(const string& n, int a, const string& e, const string& p) {
    this-> name = n;
    this-> age = a;
    this->email = e;
    this->password = p;
}

void User::setAge(int a) {
    this-> age = a;
}

User &User::operator=(const User &u) {
    if (this != &u) {
        this->setName(u.name);
        this->setAge(u.age);
        this->setEmail(u.email);
        this->setPassword(u.password);
    }
    return *this;
}

bool User::operator==(const User &u) {
    return (this->name == u.name) && (this->age == u.age) && (this->email == u.email) && (this->password == u.password);
}

User::User(){
    this->name = "";
    this->age = 0;
    this->email = "";
    this->password = "";
}

string User::getEmail() const {
    return this->email;
}

void User::setEmail(const string& e) {
    this->email = e;
}

void User::loadFromString(string args, char sep) {
    List<string> elements = split(args, sep);
    if (elements.Size() == 4){
        this->name = elements[0];
        stringstream i(elements[1]);
        i >> this->age;
        this->email = elements[2];
        this->password = elements[3];
    }
    else{
        throw invalid_argument("nr invalid de argumente in stringul ce tb parsat");
    }
}

string User::toStringDelimiter(char sep) {
    return this->name + sep + to_string(this->age) + sep + this->email + sep + this->password;
}

User::User(string args, char sep) {
    this->loadFromString(args, sep);
}

User::User(const User &u) {
    this->name = u.name;
    this->age = u.age;
    this->email = u.email;
    this->password = u.password;
}

bool User::operator<(const User &p) const {
    return (this->age < p.age);
}

bool User::operator<=(const User &p) const {
    return (this->age <= p.age);
}

bool User::operator>(const User &p) const {
    return (this->age > p.age);
}

bool User::operator>=(const User &p) const {
    return (this->age >= p.age);
}

string User::getPassword() const {
    return this->password;
}

void User::setPassword(const string &p) {
    this->password = p;
}

User::~User() = default;


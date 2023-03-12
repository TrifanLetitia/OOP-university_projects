//
// Created by Leti on 28.04.2022.
//

#ifndef SOCIALNETWORK_USER_H
#define SOCIALNETWORK_USER_H


#include <string>
#include "iostream"

using namespace std;

class User{
private:
    string name;
    int age;
    string email;
    string password;
public:
    ~User();
    User();
    User(const string& n, int a, const string& e, const string& p);
    string getName() const;
    int getAge() const;
    string getEmail() const;
    string getPassword() const;
    void setName(const string &n);
    void setAge(int a);
    void setEmail(const string& e);
    void setPassword(const string& p);
    User &operator=(const User &u);
    User(const User& u);
    bool operator==(const User &u);
    bool operator<(const User &p) const;
    bool operator<=(const User &p) const;
    bool operator>(const User &p) const;
    bool operator>=(const User &p) const;
    friend ostream& operator<<(ostream& os, const User& u);
    User(string args, char sep);
    void loadFromString(string args, char sep);
    string toStringDelimiter(char sep);
};


#endif //SOCIALNETWORK_USER_H

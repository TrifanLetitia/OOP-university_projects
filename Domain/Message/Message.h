//
// Created by Leti on 28.04.2022.
//

#ifndef SOCIALNETWORK_MESSAGE_H
#define SOCIALNETWORK_MESSAGE_H

#include <string>
#include "../User/User.h"

using namespace std;

class Message {
private:
    int id;
    string message;
    string eu1;
    string eu2;
public:
    Message();
    Message(int id1, const string& m, const string& eu1, const string& eu2);
    Message(const Message &m);
    ~Message();
    string getMessage() const;
    void setMessage(const string& m);
    void setEmail1(const string& eu1);
    void setEmail2(const string& eu2);
    void setId(int id);
    string getEmail1() const;
    string getEmail2() const;
    int getId() const;
    Message &operator=(const Message &m);
    bool operator==(const Message& m);
    friend std::ostream &operator<<(std::ostream &os, const Message& m);
    Message(string args, char sep);
    void loadFromString(const string& args, char sep);
    string toStringDelimiter(char sep);
};


#endif //SOCIALNETWORK_MESSAGE_H

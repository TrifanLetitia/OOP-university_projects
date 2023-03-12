//
// Created by Leti on 28.04.2022.
//

#include "Message.h"
#include "../../Utils/utils.h"


Message::Message(){
    this->message = "";
    this->id = 0;
    this->eu1 = "";
    this->eu2 = "";
}

Message::Message(int id1, const string& m, const string& eu1, const string& eu2) {
    this->id = id1;
    this->message = m;
    this->eu1 = eu1;
    this->eu2 = eu2;
}

string Message::getMessage() const{
    return this->message;
}

void Message::setMessage(const string& m) {
   this->message = m;
}

Message &Message::operator=(const Message &m) {
    if (this != &m) {
        this->setId(m.id);
        this->setMessage(m.message);
        this->setEmail1(m.eu1);
        this->setEmail2(m.eu2);
    }
    return *this;
}

Message::Message(const Message &m) {
    this->id = m.id;
    this->message = m.message;
    this->eu1 = m.eu1;
    this->eu2 = m.eu2;
}

Message::~Message(){
    this->id = 0;
    this->message = "";
    this->eu1 = "";
    this->eu2 = "";
}

std::ostream &operator<<(std::ostream &os, const Message& m) {
    os << " Message: " << "Id: " << m.id << " " <<  m.message << " From: " <<m.eu1 <<" To: " << m.eu2;
    return os;
}

bool Message::operator==(const Message& m) {
    return (this->id == m.id) && (this->message == m.message) && (this->eu1 == m.eu1) && (this->eu2 == m.eu2);
}

void Message::setEmail1(const string &eu1) {
    this->eu1 = eu1;
}

void Message::setEmail2(const string &eu2) {
    this->eu2 = eu2;
}

string Message::getEmail1() const {
    return this->eu1;
}

string Message::getEmail2() const{
    return this->eu2;
}

void Message::loadFromString(const string& args, char sep) {
    List<string> elements = split(args, sep);
    if (elements.Size() == 4){
        stringstream i(elements[0]);
        i >> this->id;
        this->message = elements[1];
        this->eu1 = elements[2];
        this->eu2 = elements[3];
    }
    else{
        throw invalid_argument("nr invalid de argumente in stringul ce tb parsat");
    }
}

string Message::toStringDelimiter(char sep) {
    return to_string(this->id) + sep + this->message + sep + this->eu1 + sep + this->eu2;
}

Message::Message(string args, char sep) {
    this->loadFromString(args, sep);
}

void Message::setId(int id1) {
    this->id = id1;
}

int Message::getId() const {
    return this->id;
}






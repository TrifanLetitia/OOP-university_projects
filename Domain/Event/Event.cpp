//
// Created by Leti on 19.05.2022.
//
#include "Event.h"
#include "../../Utils/utils.h"

Event::~Event() = default;

Event::Event(int id1, const User &creator, const string &n, const string &d, const List<string>&p){
    this->id = id1;
    this->creator = creator;
    this->name = n;
    this->details = d;
    this->participants = p;
}

void Event::setName(const string &n) {
    this->name = n;
}

string Event::getEventName() {
    return this->name;
}


Event &Event::operator=(const Event &p) {
    if (this != &p) {
        this->setId(p.id);
        this->setCreator(p.creator);
        this->setName(p.name);
        this->setDetails(p.details);
        this->setParticipants(p.participants);
        this->setOberver(p.observer);
    }
    return *this;
}

void Event::setDetails(const string &details) {
    this->details = details;
}

string Event::getDetails() {
    return this->details;
}

bool Event::operator==(const Event &e) {
    return (this->id == e.id) && (this->creator == e.creator) && (this->name == e.name) && (this->details == e.details); //&& (this->participants == e.participants);
}

bool Event::operator<(const Event &e) const {
    return (participants.size < e.participants.size);
}

bool Event::operator<=(const Event &e) const {
    return (this->participants.size <= e.participants.size);
}

bool Event::operator>(const Event &e) const {
    return (this->participants.size > e.participants.size);
}

bool Event::operator>=(const Event &e) const {
    return (this->participants.size >= e.participants.size);
}

std::ostream &operator<<(ostream &os, const Event& e) {
    os << "Event Id: " << e.id << " name: " << e.name << " Details: " << e.details ;
    return os;
}

void Event::loadFromString(const string &args, char sep) {
    List<string> elements = split(args, sep);
    if(elements.Size() >= 7) {
        stringstream c(elements[0]);
        c >> this->id;
        stringstream i(elements[2]);
        int age;
        i >> age;
        string s, s1, s2, s3, s4;
        s = elements[1];
        s2 = elements[3];
        s1 = elements[4];
        User u(s, age, s2, s1);
        this->creator = u;
        this->name = elements[5];
        this->details = elements[6];
        for (int j = 7; j < elements.Size(); j++) {
            participants.add(elements[j]);
        }
    }
    else{
        throw invalid_argument("nr invalid de argumente in stringul ce tb parsat");
    }
}

string Event::toStringDelimiter(char sep) {
    string s = to_string(this->id) + sep + this->creator.toStringDelimiter(sep) + sep + this->name + sep + this->details + sep;
    for(int i = 0; i < participants.Size(); i++){
        s = s + participants[i] + sep;
    }
    return s;
}

int Event::getId() const {
    return this->id;
}

void Event::setId(int id1) {
    this->id = id1;
}

Event::Event(const string &args, char sep){
    this->loadFromString(args, sep);
}

List<User> Event::getSubscribers() {
    return observer.getSubscribers();
}

List<User> Event::getUnsubscribers() {
    return observer.getUnsubscribers();
}

void Event::setOberver(const Observer& ob) {
    this->observer = ob;
}

Observer Event::getObserver() {
    return this->observer;
}

void Event::addSubscribers(const User& u) {
    observer.addSubscribers(u);
}

void Event::deleteSubscribers(const User& u) {
    observer.deleteSubscribers(u);
}

Event::Event(const Event &e) {
    this->id = e.id;
    this->creator = e.creator;
    this->name = e.name;
    this->details = e.details;
    this->observer = e.observer;
    this->participants = e.participants;
}

List<string> Event::getParticipants() {
    return this->participants;
}

void Event::setParticipants(const List<string>& p) {
    this->participants = p;
}

void Event::addParticipant(const string& u) {
    this->participants.add(u);
}

void Event::deleteParticipant(const string &u) {
    for(int i = 0; i < participants.size; i++){
        if(participants.elems[i] == u){
            this->participants.remove(i);
           // this->participants.elems[i] = this->participants.elems[i + 1];
          //  participants.size--;
        }
    }
}

void Event::setCreator(const User& u) {
    this->creator = u;
}

User Event::getCreator() {
    return this->creator;
}

Event::Event(List<string> &participants) : participants(participants) {
}

Event::Event()= default;;

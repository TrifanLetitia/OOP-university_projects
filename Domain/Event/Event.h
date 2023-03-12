//
// Created by Leti on 19.05.2022.
//

#ifndef SOCIALNETWORK_EVENT_H
#define SOCIALNETWORK_EVENT_H
#include <iostream>
#include "../User/User.h"
#include "../../TADList/List.h"
#include "../Observer/Observer.h"


class Event {
private:
    Observer observer;
    int id;
    User creator;
    std::string name;
    std::string details;
    List<string> participants;
public:
    void setOberver(const Observer& ob);
    Observer getObserver();
    ~Event();
    Event();
    Event(List<string> &participants);
    Event(const Event &e);
    void setCreator(const User& u);
    User getCreator();
    void addSubscribers(const User& u) ;
    void deleteSubscribers(const User& u) ;
    explicit Event(int id1, const User &creator, const string &n, const string &d, const List<string>& p);
    void addParticipant(const string& u);
    void deleteParticipant(const string& u);
    List<string> getParticipants();
    void setParticipants(const List<string>& p);
    List<User> getSubscribers();
    List<User> getUnsubscribers() ;
    void setName(const string& n);
    string getEventName();
    int getId() const;
    void setId(int id1);
    void setDetails(const string& details);
    string getDetails();
    Event &operator=(const Event &e);
    bool operator==(const Event &e);
    bool operator<(const Event &e) const;
    bool operator<=(const Event &e) const;
    bool operator>(const Event &e) const;
    bool operator>=(const Event &e) const;
    friend std::ostream &operator<<(std::ostream &os, const Event& e);
    void loadFromString(const string& args, char sep);
    string toStringDelimiter(char sep);
    Event(const string &args, char sep);
};


#endif //SOCIALNETWORK_EVENT_H

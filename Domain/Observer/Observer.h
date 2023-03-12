//
// Created by Leti on 21.05.2022.
//

#ifndef SOCIALNETWORK_OBSERVER_H
#define SOCIALNETWORK_OBSERVER_H
#include "iostream"
#include "../User/User.h"
#include "../../TADList/List.h"

class Observer {
private:
    std::string notifications;
    List<User> subscribers;
    List<User> unsubscribers;
public:
    string getNotifications();
    void setNotifications(const string& n);
    virtual List<User> getSubscribers();

    virtual void addSubscribers(const User& u);

    virtual void deleteSubscribers(const User& u);
    virtual List<User> getUnsubscribers();
    Observer(List<User> &subscribers, List<User> &unsubscribers);
    ~Observer();
    Observer();

};


#endif //SOCIALNETWORK_OBSERVER_H

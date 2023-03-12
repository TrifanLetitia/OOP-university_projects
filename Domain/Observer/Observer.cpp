//
// Created by Leti on 21.05.2022.
//

#include "Observer.h"

Observer::Observer(List<User> &subscribers, List<User> &unsubscribers)
        : subscribers(subscribers), unsubscribers(unsubscribers) {}

Observer::~Observer() = default;

string Observer::getNotifications() {
    return this->notifications;
}

void Observer::setNotifications(const string &n) {
    this->notifications = n;
}

List<User> Observer::getSubscribers() {
    return this->subscribers;
}

void Observer::addSubscribers(const User& u) {
    subscribers.add(u);
}

void Observer::deleteSubscribers(const User &u) {
    for(int i = 0; i < subscribers.Size(); i++){
        if(subscribers.getAt(i) == u){
            subscribers.remove(i);
            unsubscribers.add(u);
        }
    }
}

List<User> Observer::getUnsubscribers() {
    return this->unsubscribers;
}

Observer::Observer() = default;

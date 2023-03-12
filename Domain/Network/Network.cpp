//
// Created by Leti on 21.05.2022.
//
#include "Network.h"


Network *Network::getInstance() {
    if (!instance)
        instance = new Network();
    return instance;
}

UserService& Network::getUS() {
    return this->users;
}

FriendshipService& Network::getFS() {
    return this->friends;
}

void Network::setUS(UserService& users1) {
    this->users = users1;
}

void Network::setFS(FriendshipService& friends1) {
    this->friends = friends1;
}
Network *Network::instance  = nullptr;

Network::Network() : users(users), friends(friends) {

}

Network::Network(UserService& users, FriendshipService &friends) : users(users),friends(friends) {

}

Network::~Network() = default;

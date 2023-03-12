//
// Created by Leti on 21.05.2022.
//

#include "NetworkService.h"

UserService NetworkService::getUsers() {
    return network->getUS();
}

FriendshipService NetworkService::getFriendships() {
    return network->getFS();
}

void NetworkService::addUserService(const User& u) {
    network->getUS().addUser(u);
}

void NetworkService::addFriendshipService(const Friendship& f) {
    int nr = 0;
    int nr1 = 0;
    for (int i = 0; i < getUsers().getSize(); i++) {
        if (getUsers().getAll()[i].getEmail() == f.getEmail1()) {
            nr++;
        }
    }
    for(int i = 0; i < getUsers().getSize(); i++){
        if(getUsers().getAll()[i].getEmail() == f.getEmail2()){
            nr1++;
        }
    }
    if(nr == 0){throw invalid_argument("Invalid email! No user with given email!");}
    if(nr1 == 0){throw invalid_argument("Invalid email! No user with given email!");}
    network->getFS().addFriendship(f);
}

void NetworkService::deleteUserService(const User& u) {
    network->getUS().deleteUser(u);
}

void NetworkService::deleteFriendshipService(const Friendship& f) {
    network->getFS().deleteFriend(f);
}

void NetworkService::updateUserService(const User& f) {
    network->getUS().updateUser(f);
}

void NetworkService::updateFriendshipService(const Friendship& f) {
  //  network->getFS().updateFriendship(f);
}

NetworkService::NetworkService(Network *network) : network(network) {

}
NetworkService::~NetworkService() = default;

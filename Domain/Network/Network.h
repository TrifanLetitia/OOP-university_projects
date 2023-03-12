//
// Created by Leti on 21.05.2022.
//
#ifndef SOCIALNETWORK_NETWORK_H
#define SOCIALNETWORK_NETWORK_H


#include "../../Service/UserService/UserService.h"
#include "../../Service/FriendshipService/FriendshipService.h"

class Network {
    static Network *instance;
    UserService &users;
    FriendshipService friends;
public:
    ~Network();

    Network();

    Network(UserService &users, FriendshipService &friends);

    static Network *getInstance();

    UserService &getUS();

    FriendshipService &getFS();

    void setUS(UserService &users1);

    void setFS(FriendshipService &friends1);
};


#endif //SOCIALNETWORK_NETWORK_H

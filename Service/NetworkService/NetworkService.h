//
// Created by Leti on 21.05.2022.
//

#ifndef SOCIALNETWORK_COPIE_NETWORKSERVICE_H
#define SOCIALNETWORK_COPIE_NETWORKSERVICE_H


#include "../../Domain/Network/Network.h"

class NetworkService {
private:
    Network* network;
public:
    explicit NetworkService(Network *network);
    ~NetworkService();
    UserService getUsers();
    FriendshipService getFriendships();
    void addUserService(const User& u);
    void addFriendshipService(const Friendship& f);
    void deleteUserService(const User& u);
    void deleteFriendshipService(const Friendship& f);
    void updateUserService(const User& f);
    void updateFriendshipService(const Friendship& f);
};


#endif //SOCIALNETWORK_COPIE_NETWORKSERVICE_H

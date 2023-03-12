//
// Created by Leti on 20.05.2022.
//

#ifndef SOCIALNETWORK_FRIENDSHIPSERVICE_H
#define SOCIALNETWORK_FRIENDSHIPSERVICE_H

#include "../../Domain/Friendship/Friendship.h"
#include "../../Repository/RepositoryFileCSV.h"
#include "../../Domain/User/User.h"
#include "../../Domain/FriendshipValidator/FriendshipValidator.h"

class FriendshipService {
private:
    RepositoryFileCSV<Friendship> repo;
   // FriendshipValidator FV;
public:
    explicit FriendshipService(const RepositoryFileCSV<Friendship>& repo1);//const FriendshipValidator& FV);
    void addFriendship(const Friendship &r);
    int getSize();
    List<Friendship> getAll();
    void deleteFriend(const Friendship &r);
   // FriendshipService(FriendshipService & fs);
    void updateFriendship(const Friendship& f);
    Friendship getFriendship(const Friendship& f);
    bool inFriendship(const User& u1, const User& u2);
    ~FriendshipService();

};


#endif //SOCIALNETWORK_FRIENDSHIPSERVICE_H

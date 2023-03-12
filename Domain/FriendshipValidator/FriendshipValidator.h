//
// Created by Leti on 21.05.2022.
//

#ifndef SOCIALNETWORK_FRIENDSHIPVALIDATOR_H
#define SOCIALNETWORK_FRIENDSHIPVALIDATOR_H

#include <utility>

#include "../../Service/UserService/UserService.h"
#include "../Friendship/Friendship.h"

class FriendshipValidator {
public:
    UserService s;
    explicit FriendshipValidator(UserService s) : s(std::move(s)) {}

    FriendshipValidator() = default;;
    ~FriendshipValidator()= default;
    void ValidateFriendship(const Friendship &f) {
        int nr = 0;
        for (int i = 0; i < s.getSize(); i++) {
            for (int j = 0; j < s.getSize(); j++) {
                if (f.getEmail1() == s.getAll()[i].getEmail() and f.getEmail2() == s.getAll()[j].getEmail()) {
                    nr++;
                }
            }
            if (nr == 0) { throw invalid_argument("Users not found!Try again!"); }
        }
    }
};

#endif //SOCIALNETWORK_FRIENDSHIPVALIDATOR_H

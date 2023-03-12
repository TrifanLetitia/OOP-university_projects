//
// Created by Leti on 21.05.2022.
//

#ifndef SOCIALNETWORK_USERVALIDATOR_H
#define SOCIALNETWORK_USERVALIDATOR_H


#include "../User/User.h"

class UserValidator {
public:
    explicit UserValidator() = default;;

    ~UserValidator() = default;

    virtual void ValidateUser(const User &u) {
        if (u.getAge() < 13) {
            throw invalid_argument("13 is the minimum age to manage your own SDToySocialNetwork Account!");
        }
    }
};

#endif //SOCIALNETWORK_USERVALIDATOR_H

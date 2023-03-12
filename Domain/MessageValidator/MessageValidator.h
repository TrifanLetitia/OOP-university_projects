//
// Created by Leti on 18.05.2022.
//

#ifndef SOCIALNETWORK_MESSAGEVALIDATOR_H
#define SOCIALNETWORK_MESSAGEVALIDATOR_H
#include <utility>

#include "../Message/Message.h"
#include "../../Service/UserService/UserService.h"

class MessageValidator {
public:
    UserService& s;
    explicit MessageValidator(const UserService& s1) : s(const_cast<UserService &>(s1)) {};
    ~MessageValidator()= default;
    virtual void ValidateMessage(const Message &r) {
        if (r.getId() < 0) { throw invalid_argument("Id must be a positive integer!"); }
        int nr = 0;
        int nr1 = 0;
        for (int i = 0; i < s.getSize(); i++) {
            if (s.getAll()[i].getEmail() == r.getEmail1()) {
                nr++;
            }
        }
        for(int i = 0; i < s.getSize(); i++){
            if(s.getAll()[i].getEmail() == r.getEmail2()){
                nr1++;
            }
        }
        if(nr == 0){throw invalid_argument("Invalid email! No user with given email!");}
        if(nr1 == 0){throw invalid_argument("Invalid email! No user with given email!");}
    }
};

#endif //SOCIALNETWORK_MESSAGEVALIDATOR_H
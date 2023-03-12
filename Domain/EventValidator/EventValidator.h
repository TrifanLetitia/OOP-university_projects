//
// Created by Leti on 22.05.2022.
//

#ifndef SOCIALNETWORK_EVENTVALIDATOR_H
#define SOCIALNETWORK_EVENTVALIDATOR_H

#include "../Event/Event.h"

class EventValidator {
public:
    explicit EventValidator() = default;;
    ~EventValidator() = default;
    virtual void ValidateEvent(const Event &u) {
        if (u.getId() < 0) { throw invalid_argument("Id must be a positive integer!"); }
    }
};

#endif //SOCIALNETWORK_EVENTVALIDATOR_H

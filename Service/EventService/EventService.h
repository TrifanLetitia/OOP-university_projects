//
// Created by Leti on 20.05.2022.
//

#ifndef SOCIALNETWORK_EVENTSERVICE_H
#define SOCIALNETWORK_EVENTSERVICE_H


#include "../../Repository/RepositoryFileEventCSV.h"
#include "../../Domain/EventValidator/EventValidator.h"

class EventService {
private:
    RepositoryFileEventCSV& repo;
    EventValidator EV;
public:
    explicit EventService(const RepositoryFileEventCSV& repo, EventValidator& EV);

    void addEvent(Event& e);

    List<Event> getAll();

    void deleteEvent(const Event &e);

    void updateEvent(int id, Event e);

    int getSize();

    bool search(const Event& e);

    void addParticipant(Event &e, const User& u);

    void deleteParticipant(const Event e, const User& u);

    static List<string> getParticipants(Event e);

};


#endif //SOCIALNETWORK_EVENTSERVICE_H

//
// Created by Leti on 20.05.2022.
//

#include "EventService.h"

EventService::EventService(const RepositoryFileEventCSV& repo, EventValidator& EV) : repo(const_cast<RepositoryFileEventCSV &>(repo)), EV(EV) {

}

void EventService::addEvent(Event& e) {
    int i = 0;
    int id = e.getId();
    while(i < repo.getSize()){
        if(repo.getAll()[i].getId() == id){
            id = rand() % 100;
        }
        i++;
    }
    for(int j = 0; j < repo.getSize(); j++){
        if(repo.getAll()[j].getId() == id){throw invalid_argument("There is already another event with this id!");}
    }
    e.setId(id);
    EV.ValidateEvent(e);
    repo.addEvent(e);
}

List<Event> EventService::getAll() {
    return repo.getAll();
}

int EventService::getSize() {
    return repo.getSize();
}

void EventService::deleteEvent(const Event &e) {
    repo.deleteEvent(e);
}

void EventService::addParticipant(Event &e, const User& u) {
    for(int i = 0; i < repo.getAll().Size(); i++){
        if(repo.getAll()[i].getId() == e.getId()){
            /*
            List<string>p = e.getParticipants();
            p.add(u.getEmail());
            Event e1(e.getId(), e.getCreator(), e.getEventName(), e.getDetails());
            e1.setParticipants(p);
            repo.updateEvent(e, e1);
             */
            repo.addParticipant(e, u);
        }
    }
}

void EventService::deleteParticipant(Event e, const User &u) {
    for(int i = 0; i < repo.getSize(); i++){
        if(repo.getAll()[i] == e){
            e.deleteParticipant(u.getEmail());
        }
    }
}

List<string> EventService::getParticipants(Event e) {
    return e.getParticipants();
}



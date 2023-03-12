//
// Created by Leti on 20.05.2022.
//

#include "RepositoryFileEvent.h"
List<Event> RepositoryFileEvent::list;
RepositoryFileEvent::RepositoryFileEvent(const string &fileName) {
    this->fileName = fileName;
}

void RepositoryFileEvent::addEvent(const Event &e) {
    if (elements.search(e)) {
        throw invalid_argument("This event already exists!");
    } else { elements.add(e); list.add(e);}
    saveToFile();
}

RepositoryFileEvent::~RepositoryFileEvent() = default;

List<Event> RepositoryFileEvent::getAll() {
    return elements.addToList(list);
}

int RepositoryFileEvent::getSize() {
    return elements.Size();
}

void RepositoryFileEvent::deleteEvent(const Event &e) {
    elements.removeElem(e);
    for(int i = 0; i < list.Size(); i++){
        if(list[i] == e){
            list.remove(i);
        }
    }
    saveToFile();
}

void RepositoryFileEvent::addParticipant(Event& e, const User &u) {
    for (int i = 0; i < elements.Size(); i++) {
        if (getAll()[i].getId() == e.getId()) {
           List<string> p = e.getParticipants();
           p.add(u.getEmail());
           Event e1(e.getId(), e.getCreator(), e.getEventName(), e.getDetails(), p);
           elements.removeElem(e);
           elements.add(e1);
           list.replace(i,e1);
        }
    }
    saveToFile();
}

void RepositoryFileEvent::updateEvent(const Event& e1, const Event& e) {
    elements.removeElem(e1);
    elements.add(e);
    saveToFile();
}

RepositoryFileEvent::RepositoryFileEvent()= default;

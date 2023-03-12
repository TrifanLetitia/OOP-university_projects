//
// Created by Leti on 20.05.2022.
//

#include "RepositoryFileEventCSV.h"

RepositoryFileEventCSV::RepositoryFileEventCSV(const string &fileName){
    this->fileName = fileName;
    loadFromFile();
}

void RepositoryFileEventCSV::saveToFile() {
    ofstream f(this->fileName);
    for (int i = 0; i < RepositoryFileEvent::getSize(); i++) {
        Event elem = RepositoryFileEvent::elements.addToList(list)[i];
        f << elem.toStringDelimiter(',') << endl;
    }
    f.close();
}

void RepositoryFileEventCSV::loadFromFile() {
    string line;
    ifstream f(this->fileName);
    while (std::getline(f, line)) {
        try {
            Event ob(line, ',');
            this->elements.add(ob);
        }
        catch(invalid_argument ex){
            cout << "some pb: " << ex.what() << endl;
            throw ex;
        }
    }
}

RepositoryFileEventCSV::RepositoryFileEventCSV()= default;

RepositoryFileEventCSV::~RepositoryFileEventCSV() = default;
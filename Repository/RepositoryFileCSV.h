//
// Created by Leti on 11.05.2022.
//

#ifndef SOCIALNETWORK_REPOSITORYFILECSV_H
#define SOCIALNETWORK_REPOSITORYFILECSV_H


#include <string>
#include <vector>
#include <fstream>

using namespace std;


#include "RepositoryFile.h"
#include "iostream"
template <class T>
class RepositoryFileCSV : public RepositoryFile<T>
{
public:
    explicit RepositoryFileCSV(const string& fileName);

    RepositoryFileCSV();

    void saveToFile();
    void loadFromFile();
    ~RepositoryFileCSV();
};

template<class T>
RepositoryFileCSV<T>::~RepositoryFileCSV()
= default;

template<class T>
void RepositoryFileCSV<T>::saveToFile()
{

    ofstream f(this->fileName);
    for (int i = 0; i < RepositoryFile<T>::getSize(); i++) {
        T elem = RepositoryFile<T>::getAll()[i];
        f << elem.toStringDelimiter(',') << endl;
    }
    f.close();
}

template<class T>
void RepositoryFileCSV<T>::loadFromFile()
{
    string line;
    ifstream f(this->fileName);
    while (std::getline(f, line)) {
        try {
            T ob(line, ',');
            this->elements.add(ob);
        }
        catch(invalid_argument ex){
            cout << "some pb: " << ex.what() << endl;
            throw ex;
        }
    }

}

template<class T>
RepositoryFileCSV<T>::RepositoryFileCSV(const string &fileName) {
    this->fileName = fileName;
    this->loadFromFile();
}

template<class T>
RepositoryFileCSV<T>::RepositoryFileCSV() = default;

#endif //SOCIALNETWORK_REPOSITORYFILECSV_H

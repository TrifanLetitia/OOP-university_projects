//
// Created by Leti on 11.05.2022.
//

#ifndef SOCIALNETWORK_REPOSITORYFILE_H
#define SOCIALNETWORK_REPOSITORYFILE_H


#include <string>
#include <vector>
#include <fstream>
#include "../TADList/List.h"

using namespace std;

template<class T>
class RepositoryFile {

protected:
    string fileName;
    List<T> elements;
public:
    RepositoryFile(const string &);

    RepositoryFile();

    virtual void saveToFile() = 0;

    virtual void loadFromFile() = 0;

    ~RepositoryFile();

    List<T> &getAll();

    T getElement(T& el);

    void add(const T &el);

    int getSize();

    void deleteEl(const T& el);

    void updateEl(int i, T el);

    void clearfile(const string &fileName);
};


template<class T>
RepositoryFile<T>::RepositoryFile(const string &name) {
    this->fileName = name;
}

template<class T>
RepositoryFile<T>::~RepositoryFile()
= default;


template<class T>
List<T> &RepositoryFile<T>::getAll() {
    return this->elements;
}

template<class T>
T RepositoryFile<T>::getElement(T& el) {
    int nr = 0;
    for (int i = 0; i < elements.Size(); i++) {
        if (elements[i] == el) {
            nr++;
            return elements[i];
        }
    }
    if(nr == 0) {
        throw invalid_argument("searched elem was not found!");
    }
}

template<class T>
void RepositoryFile<T>::add(const T &el) {
    this->elements.add(el);
    this->saveToFile();
}

template<class T>
int RepositoryFile<T>::getSize() {
    return this->elements.Size();
}

template<class T>
void RepositoryFile<T>::deleteEl(const T& el) {
    int nr = 0;
    for (int i = 0; i < elements.Size(); i++) {
        if (elements[i] == el) {
            nr++;
            elements.remove(i);
        }
    }
    if(nr == 0) {throw invalid_argument("searched elem was not found!");}
    this->saveToFile();
}

template<class T>
void RepositoryFile<T>::clearfile(const string &filename) {
    std::ofstream ofs;
    ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

template<class T>
void RepositoryFile<T>::updateEl(int i, T el) {
    elements.replace(i, el);
    saveToFile();
}

template<class T>
RepositoryFile<T>::RepositoryFile() = default;


#endif //SOCIALNETWORK_REPOSITORYFILE_H

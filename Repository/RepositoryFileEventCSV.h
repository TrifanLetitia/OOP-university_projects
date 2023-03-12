//
// Created by Leti on 20.05.2022.
//

#ifndef SOCIALNETWORK_REPOSITORYFILEEVENTCSV_H
#define SOCIALNETWORK_REPOSITORYFILEEVENTCSV_H

#include <fstream>
#include "RepositoryFileEvent.h"


class RepositoryFileEventCSV : public RepositoryFileEvent
{
public:
    RepositoryFileEventCSV();

    explicit RepositoryFileEventCSV(const string& fileName);
    void saveToFile() override ;
    void loadFromFile() override;
    ~RepositoryFileEventCSV();
};



#endif //SOCIALNETWORK_REPOSITORYFILEEVENTCSV_H

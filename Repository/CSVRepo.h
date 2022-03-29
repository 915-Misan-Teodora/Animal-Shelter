//
// Created by Misan on 4/20/2021.
//

#ifndef A67_915_MISAN_TEODORA_CSVREPO_H
#define A67_915_MISAN_TEODORA_CSVREPO_H

using namespace std;
#include "Repo.h"
#include "File.h"

class CsvRepo : public FileOption
{
public:

    void writeFile() override;

    void display() const override;
};

#endif //A67_915_MISAN_TEODORA_CSVREPO_H

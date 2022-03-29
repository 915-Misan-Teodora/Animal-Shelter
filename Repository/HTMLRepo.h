//
// Created by Misan on 5/5/2021.
//

#ifndef A67_915_MISAN_TEODORA_HTMLREPO_H
#define A67_915_MISAN_TEODORA_HTMLREPO_H

#include "File.h"

class HtmlRepo : public FileOption{
public:
    void writeFile() override;
    void display() const override;
};
#endif //A67_915_MISAN_TEODORA_HTMLREPO_H

#include "ClassifyData.h"
#include <utility>


ClassifyData::~ClassifyData() = default;

ClassifyData::ClassifyData(string description, AbstractDefaultIO *newDescription)
        : Commander(std::move(description), newDescription) {

}

void ClassifyData::execute() {

}



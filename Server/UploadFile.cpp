//
// Created by tal on 1/14/23.
//

#include "UploadFile.h"

#include <utility>

UploadFile::UploadFile(string description, AbstractDefaultIO *newDescription)
: Commander(std::move(description), newDescription) {

}

void UploadFile::execute() {

}

UploadFile::~UploadFile() = default;

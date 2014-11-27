#include "../lib/imports.h"
Result::Result(){
    this->matrix = NULL;
    this->description = "";
}

Result::Result(Matrix *matrix, std::string description){
    this->matrix = matrix;
    this->description = description;
}

void Result::setDescription(std::string description){
    this->description = description;
}

std::string Result::getDescription(){
    return this->description;
}

void Result::setMatrix(Matrix *matrix){
    this->matrix = matrix;
}

Matrix *Result::getMatrix(){
    return this->matrix;
}

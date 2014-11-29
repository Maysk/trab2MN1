#include "../lib/imports.h"


GaussTemplate::GaussTemplate(Matrix* independentTermsMatrix, Matrix* coefficientMatrix){
    this->independentTermsMatrix = independentTermsMatrix;
    this->coefficientMatrix = coefficientMatrix;
    this->results = new ListResults();
}

void GaussTemplate::setCoefficienMatrix(Matrix* matrix){
    this->coefficientMatrix = matrix;
}

Matrix *GaussTemplate::getCoefficienMatrix(){
    return this->coefficientMatrix;
}


void GaussTemplate::setIndependentTerms(Matrix* matrix){
    this->independentTermsMatrix = matrix;
}
Matrix *GaussTemplate::getIndependentTerms(){
    return this->independentTermsMatrix;
}

Matrix *GaussTemplate::getUnknownsMatrix(){
    return this->unknownsMatrix;
}


void GaussTemplate::retroSubstitutions(){
    Matrix *independentTerms = getIndependentTerms();
    Matrix *coefficients = getCoefficienMatrix();
    int numberOfLines = independentTerms->getHeight();

    Matrix *unknowns = new Matrix(numberOfLines,1);
    double unknown_k;
    double sum;

    unknown_k = coefficients->getValue(numberOfLines-1,0)/independentTerms->getValue(numberOfLines-1,numberOfLines-1);
    unknowns->setValue(2,0,unknown_k);
    for(int k=numberOfLines-2; k>=0; k--){
        sum = 0;
        for (int j=(k + 1); j <= numberOfLines-1; j++){
            sum = sum + independentTerms->getValue(k,j) * unknowns->getValue(j,0);
        }

        unknown_k = (coefficients->getValue(k,0) - sum)/independentTerms->getValue(k,k);
        unknowns->setValue(k,0,unknown_k);
    }
    this->unknownsMatrix = unknowns;
}

//TODO
void GaussTemplate::resetList(){
    delete results;
    this->results = new ListResults();
}

void GaussTemplate::saveOnList(std::string desc){
    Result* parcialResult = new Result(getIndependentTerms()->getCopy(), getCoefficienMatrix()->getCopy(), desc);
    results->push(parcialResult);
}


#include "../lib/imports.h"


GaussTemplate::GaussTemplate(Matrix* independentTermsMatrix, Matrix* coefficientMatrix){
    this->independentTermsMatrix = independentTermsMatrix;
    this->coefficientMatrix = coefficientMatrix;
    this->unknownsMatrix = NULL;
    this->results = new ListResults();
    this->executionTime = 0;
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

void GaussTemplate::beforeSolve(){
    Matrix* copy1 = getIndependentTerms()->getCopy();
    Matrix* copy2 = getCoefficienMatrix()->getCopy();
    this->independentTermsMatrixTemp = getIndependentTerms();
    this->coefficientMatrixTemp = getCoefficienMatrix();
    setIndependentTerms(copy1);
    setCoefficienMatrix(copy2);

    setExecutionTime(0);
    resetList();

}


void GaussTemplate::afterSolve(){
    delete getIndependentTerms();
    delete getCoefficienMatrix();
    setIndependentTerms(this->independentTermsMatrixTemp);
    setCoefficienMatrix(this->coefficientMatrixTemp);
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


void GaussTemplate::resetList(){
    delete results;
    this->results = new ListResults();
}

void GaussTemplate::saveOnList(std::string desc){
    Result* parcialResult = new Result(getIndependentTerms()->getCopy(), getCoefficienMatrix()->getCopy(), desc);
    results->push(parcialResult);
}


void GaussTemplate::setExecutionTime(long double executionTime){
    this->executionTime = executionTime;
}
long double GaussTemplate::getExecutionTime(){
    return this->executionTime;
}

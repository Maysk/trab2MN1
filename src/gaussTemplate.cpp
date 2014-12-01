#include "../lib/imports.h"


GaussTemplate::GaussTemplate(Matrix* independentTermsMatrix, Matrix* coefficientMatrix){
    this->independentTermsMatrix = independentTermsMatrix;
    this->coefficientMatrix = coefficientMatrix;
    this->unknownsMatrix = NULL;
    this->results = new ListResults();
    this->solvable = true;
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

    setSolvable(true);
    setExecutionTime(0);
    resetList();

}


void GaussTemplate::afterSolve(){
    delete getIndependentTerms();
    delete getCoefficienMatrix();
    setIndependentTerms(this->independentTermsMatrixTemp);
    setCoefficienMatrix(this->coefficientMatrixTemp);
}


void GaussTemplate::switchRows(Matrix *m, int line_i, int line_j){
    double aux;
    int width = m->getWidth();
    for(int k=0; k<width; k++){
        aux = m->getValue(line_i,k);
        m->setValue(line_i,k,m->getValue(line_j,k));
        m->setValue(line_j,k,aux);
    }
}


void GaussTemplate::retroSubstitutions(){
    Matrix *independentTerms = getIndependentTerms();
    Matrix *coefficients = getCoefficienMatrix();
    int numberOfLines = independentTerms->getHeight();

    Matrix *unknowns = new Matrix(numberOfLines,1);
    double unknown_k;
    double sum;

    unknown_k = coefficients->getValue(numberOfLines-1,0)/independentTerms->getValue(numberOfLines-1,numberOfLines-1);
    unknowns->setValue(numberOfLines-1,0,unknown_k);
    for(int k=numberOfLines-2; k>=0; k--){
        sum = 0;
        for (int j=(k + 1); j <= numberOfLines-1; j++){
            sum = sum + independentTerms->getValue(k,j) * unknowns->getValue(j,0);
        }

        unknown_k = (coefficients->getValue(k,0) - sum)/independentTerms->getValue(k,k);
        unknowns->setValue(k,0,unknown_k);
    }

    if (this->unknownsMatrix!=NULL){
        delete this->unknownsMatrix;
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


ListResults* GaussTemplate::getResults(){
   return this->results;
}

void GaussTemplate::pivoting(Matrix* A, Matrix* b, int numberOfLines, int k){
    double max = A->getValue(k,k);
    int index = k;


    for( int i = k+1; i < numberOfLines; i++){
        if ( fabs( A->getValue( i, k ) ) > fabs( max ) ){
            max = A->getValue( i, k );
            index = i;
        }

    }
    if(index!=k){
        std::ostringstream description;
        description<<"Operação realizada: L"<< k <<" <-> L"<< index <<"\n";
        saveOnList(description.str());
        switchRows(A,k,index);
        switchRows(b,k,index);
    }

}


bool GaussTemplate::isSolvable(){
    return this->solvable;
}


void GaussTemplate::setSolvable(bool s){
    this->solvable = s;
}

double GaussTemplate::getError(){
    Matrix *x = unknownsMatrix->getCopy();
    Matrix *CX = independentTermsMatrix->multipy(x);
    Matrix *residuo = coefficientMatrix->subtraction(CX);
    double maior = 0;
    for(int i = 0; i < residuo->getHeight(); i++)
        for(int j = 0; j < residuo->getWidth(); j++)
            if(fabs(maior) < fabs(residuo->getValue(i,j)))
                maior = residuo->getValue(i,j);
    return fabs(maior);


}

#include "../lib/imports.h"


GaussTemplate::GaussTemplate(Matrix* coefficientMatrix, Matrix* independentTermsMatrix){
    this->independentTermsMatrix = independentTermsMatrix;
    this->coefficientMatrix = coefficientMatrix;
    this->unknownsMatrix = NULL;
    this->results = new ListResults();
    this->solvable = true;
    this->executionTime = 0;
}

void GaussTemplate::setCoefficientMatrix(Matrix* matrix){
    this->coefficientMatrix = matrix;
}

Matrix *GaussTemplate::getCoefficientMatrix(){
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
    Matrix* copy2 = getCoefficientMatrix()->getCopy();
    this->independentTermsMatrixTemp = getIndependentTerms();
    this->coefficientMatrixTemp = getCoefficientMatrix();
    setIndependentTerms(copy1);
    setCoefficientMatrix(copy2);

    setSolvable(true);
    setExecutionTime(0);
    resetList();

}


void GaussTemplate::afterSolve(){
    delete getIndependentTerms();
    delete getCoefficientMatrix();
    setIndependentTerms(this->independentTermsMatrixTemp);
    setCoefficientMatrix(this->coefficientMatrixTemp);
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
    Matrix *coefficientsMatrix = getCoefficientMatrix();
    Matrix *independentTermsMatrix = getIndependentTerms();

    int numberOfLines = independentTermsMatrix->getHeight();

    Matrix *unknowns = new Matrix(numberOfLines,1);
    double unknown_k;
    double sum;

    unknown_k = independentTermsMatrix->getValue(numberOfLines-1,0)/coefficientsMatrix->getValue(numberOfLines-1,numberOfLines-1);
    unknowns->setValue(numberOfLines-1,0,unknown_k);
    for(int k=numberOfLines-2; k>=0; k--){
        sum = 0;
        for (int j=(k + 1); j <= numberOfLines-1; j++){
            sum = sum + coefficientsMatrix->getValue(k,j) * unknowns->getValue(j,0);
        }

        unknown_k = (independentTermsMatrix->getValue(k,0) - sum)/coefficientsMatrix->getValue(k,k);
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
    Result* parcialResult = new Result(getCoefficientMatrix()->getCopy(), getIndependentTerms()->getCopy(), desc);
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
    Matrix *CX = coefficientMatrix->multipy(x);
    Matrix *residuo = independentTermsMatrix->subtraction(CX);
    double maior = 0;
    for(int i = 0; i < residuo->getHeight(); i++)
        for(int j = 0; j < residuo->getWidth(); j++)
            if(fabs(maior) < fabs(residuo->getValue(i,j)))
                maior = residuo->getValue(i,j);
    return fabs(maior);


}

void GaussTemplate::multiplyRowByScalar(Matrix* A, Matrix* b, int line_i, double scalar){
    int numberOfColumns = A->getWidth();
    double newValue;

    for(int j = line_i; j <= numberOfColumns; j++ ){
        newValue = A->getValue( line_i, j ) * scalar;
        A->setValue( line_i, j, newValue );
    }

    b->setValue( line_i, 0, b->getValue(line_i,0) * scalar);
}

void GaussTemplate::addRowByOtherRowMultipliedByScalar(Matrix *A, Matrix *b, int line_i, int line_j, double scalar){
    int numberOfColumns = A->getWidth();
    double newValue;

    for(int k = line_j; k <= numberOfColumns; k++ ){
        newValue = A->getValue(line_i, k ) - scalar * A->getValue( line_j, k );
        A->setValue( line_i, k, newValue );
    }

    newValue = b->getValue( line_i, 0 ) - scalar * b->getValue( line_j, 0 );
    b->setValue( line_i, 0, newValue );
}

#include "../lib/imports.h"

GaussJordan::GaussJordan(Matrix* independentTermsMatrix, Matrix* coefficientMatrix)
    :GaussTemplate(independentTermsMatrix, coefficientMatrix){}


void GaussJordan::resolveSytem(){
    int numberOfLines;
    double multiplier;
    double newValue_aij;
    double newValue_bi;

    int i, j, k;

    beforeSolve();

    Matrix* coefficients = getCoefficienMatrix();
    Matrix* independentTerms = getIndependentTerms();

    numberOfLines = independentTerms->getHeight();

    for( k = 0; k < numberOfLines; k++ ){
        saveOnList("Operação realizada nesse ponto");

        independentTerms->printMatrix();
        coefficients->printMatrix();

        if( independentTerms->getValue(k,k) == 0 ){
            pivoting( independentTerms, coefficients, numberOfLines, k );

        }


        if( k < numberOfLines-1 ){
            for( j = k + 1; j < numberOfLines; j++ ){
                multiplier = independentTerms->getValue( k, j ) / independentTerms->getValue( k, k );
                independentTerms->setValue( k, j, multiplier );
            }
        }

        newValue_bi = coefficients->getValue(k,0) / independentTerms->getValue( k, k );

        coefficients->setValue( k, 0, newValue_bi );
        independentTerms->setValue( k, k, 1 );

        for( i = 0; i < numberOfLines; i++ ){
            if( i != k ){
                if( k < numberOfLines-1 ){
                    for( j = k + 1; j < numberOfLines; j++ ){

                        newValue_aij = independentTerms->getValue( i, j ) -
                                independentTerms->getValue( i, k ) * independentTerms->getValue( k, j );
                        independentTerms->setValue( i, j, newValue_aij );
                    }
                }

                newValue_bi = coefficients->getValue( i, 0 ) -
                        independentTerms->getValue( i, k ) * coefficients->getValue( k, 0 );
                coefficients->setValue( i, 0, newValue_bi );
                independentTerms->setValue( i, k, 0 );
            }
        }


    }
    retroSubstitutions();
    afterSolve();
}


void GaussJordan::pivoting(Matrix* A, Matrix* b, int numberOfLines, int k){
       double max = A->getValue(k,k);
       int index = k;
       for( int i = 0; i < numberOfLines; i++){
           if( i != k ){
               if ( fabs( A->getValue( i, k ) ) > fabs( max ) ){
                    max = A->getValue( i, k );
                    index = i;
               }

           }
       }
       double temp1, temp2;
       for( int j = 0; j < numberOfLines; j++ ){
            temp1 = A->getValue( k, j );
            A->setValue( k, j, A->getValue( index, j) );
            A->setValue( index, j, temp1 );
       }
       temp2 = b->getValue( k, 0 );
       b->setValue( k, 0, b->getValue( index, 0) );
       b->setValue( index, 0, temp2);
}

class Gauss : public GaussTemplate{
    Matrix* coefficientMatrixTemp;
    Matrix* independentTermsMatrixTemp;
public:
    Gauss(Matrix* independentTermsMatrix, Matrix* coefficientMatrix);

    void beforeSolve();
    void resolveSytem();
    void afterSolve();
};

class GaussJordan : public GaussTemplate{
    Matrix* coefficientMatrixTemp;
    Matrix* independentTermsMatrixTemp;
public:
    GaussJordan(Matrix* independentTermsMatrix, Matrix* coefficientMatrix);

    void beforeSolve();
    void resolveSytem();
    void afterSolve();
};

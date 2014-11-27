class Gauss : public GaussTemplate{
    Matrix* coefficientMatrix;
    Matrix* independentTermsMatrix;
public:
    Gauss(Matrix* independentTermsMatrix, Matrix* independentTermsMatrix);

    void beforeSolve();
    void resolveSytem();
    void afterSolve();
};

class GaussJordan : public GaussTemplate{
    Matrix* coefficientMatrixTemp;
    Matrix* independentTermsMatrixTemp;
public:
    GaussJordan(Matrix* independentTermsMatrix, Matrix* coefficientMatrix);

    void resolveSytem();

    void pivoting(Matrix* A, Matrix* b, int numberOfLines, int k);
};

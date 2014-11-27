class GaussTemplate {
    Matrix* coefficientMatrix;
    Matrix* independentTermsMatrix;
    Matrix* unknownsMatrix;

public:

    GaussTemplate(Matrix* independentTermsMatrix, Matrix* independentTermsMatrix);

    void setCoefficienMatrix(Matrix *matrix);
    Matrix *getCoefficienMatrix();

    void setIndependentTerms(Matrix* matrix);
    Matrix *getIndependentTerms();

    Matrix *getUnknownsMatrix();

    void retroSubstitutions();
    void saveOnList();

    void beforeSolve() = 0;
    void resolveSytem() = 0;
    void afterSolve() = 0;

};

class GaussTemplate {
    Matrix* coefficientMatrix;
    Matrix* independentTermsMatrix;
    Matrix* unknownsMatrix;

public:

    GaussTemplate(Matrix* independentTermsMatrix, Matrix* coefficientMatrix);

    void setCoefficienMatrix(Matrix *matrix);
    Matrix *getCoefficienMatrix();

    void setIndependentTerms(Matrix* matrix);
    Matrix *getIndependentTerms();

    Matrix *getUnknownsMatrix();


    void retroSubstitutions();
    void saveOnList();

    virtual void beforeSolve() = 0;
    virtual void resolveSytem() = 0;
    virtual void afterSolve() = 0;

};

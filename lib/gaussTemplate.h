class GaussTemplate {
    Matrix* coefficientMatrix;
    Matrix* independentTermsMatrix;
    Matrix* unknownsMatrix;
    ListResults* results;
    long double executionTime;

public:

    GaussTemplate(Matrix* independentTermsMatrix, Matrix* coefficientMatrix);

    void setCoefficienMatrix(Matrix* matrix);
    Matrix *getCoefficienMatrix();


    void setIndependentTerms(Matrix* matrix);
    Matrix *getIndependentTerms();

    Matrix *getUnknownsMatrix();

    void setExecutionTime(long double executionTime);
    long double getExecutionTime();

    void retroSubstitutions();

    void resetList();
    void saveOnList(std::string desc);

    virtual void beforeSolve() = 0;
    virtual void resolveSytem() = 0;
    virtual void afterSolve() = 0;


};

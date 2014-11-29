class GaussTemplate {
    Matrix* coefficientMatrix;
    Matrix* independentTermsMatrix;
    Matrix* unknownsMatrix;
    ListResults* results;
    long double executionTime;

    //Atributos que nao possuem getter or setters.
    Matrix* coefficientMatrixTemp;
    Matrix* independentTermsMatrixTemp;

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

    void beforeSolve();
    void afterSolve();

    virtual void resolveSytem() = 0;


};

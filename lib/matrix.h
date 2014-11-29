
class Matrix{
    int width;
    int height;
    double **content;

    bool validatePosition(int line, int colunm);

public:
    Matrix(int height, int width);
    ~Matrix();

    void setValue(int line, int column, double newValue);
    double getValue(int line, int column);

    int getHeight();
    int getWidth();

    Matrix* getCopy();
    void printMatrix();

};

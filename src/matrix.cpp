#include "../lib/imports.h"

Matrix::Matrix(int height, int width){
    content = new double*[height];
        for(int i=0; i < height; i++){
            content[i] = new double[width];
            for(int j=0; j < width; j++){
                content[i][j] = 0;
            }
    }
    this->width = width;
    this->height = height;
}

Matrix::~Matrix(){
    for(int i=0; i < this->height ;i++){
        delete [] content[i];
    }
    delete [] content;
}


bool Matrix::validatePosition(int line, int colunm){
    bool isValid = true;
    if(line<0 || line >= this->height)
        isValid = false;
    if(colunm<0 || colunm>=this->width)
        isValid = false;
    return isValid;
}

void Matrix::setValue(int line, int column, double newValue){
    if(validatePosition(line, column))
        this->content[line][column] = newValue;
}
double Matrix::getValue(int line, int column){
    return this->content[line][column];
}

int Matrix::getHeight(){
    return this->height;
}
int Matrix::getWidth(){
    return this->width;
}


Matrix* Matrix::getCopy(){
    Matrix* copy = new Matrix(this->getHeight(),this->getWidth());

    for(int i = 0; i<this->getHeight();i++){
        for(int j = 0; j<this->getWidth();j++){
            copy->setValue(i,j,this->getValue(i,j));
        }
    }
    return copy;
}

void Matrix::printMatrix(){
    for(int i = 0 ; i < getHeight() ; i++){
        for(int j = 0 ; j < getWidth() ; j++)
            cout << getValue(i,j) << "  ";
        cout << endl;
    }
}


Matrix* Matrix::multipy(Matrix *m){
    Matrix *result = new Matrix(this->getHeight(),m->getWidth());
    if(this->getWidth() == m->getHeight()){
        for(int i = 0; i < this->getHeight() ; i++ )
            for(int j = 0 ; j < m->getWidth(); j++)
                for(int w = 0 ; w < this->getWidth() ; w++)
                    result->setValue(i,j, result->getValue(i,j) + (this->getValue(i,w) * m->getValue(w,j)));
    }
    return  result;
}

Matrix* Matrix::subtraction(Matrix *m){
    Matrix *result = new Matrix(this->getHeight(),this->getWidth());
    if((this->getWidth() == m->getWidth()) && (this->getHeight() == m->getHeight()) ){
        for(int i = 0; i < this->getHeight() ; i++ )
            for(int j = 0 ; j < this->getWidth(); j++){
                result->setValue(i,j,this->getValue(i,j) - m->getValue(i,j));
            }
    }
    return  result;
}

std::string Matrix::toString(){

    int w = this->getWidth();
    int h = this->getHeight();

    QString  coef="";


    for (int i = 0; i < h;i++){

        coef.append("L"+QString::number(i)+": ");

        for(int j = 0; j < w;j++){
            coef.append(QString::number(this->getValue(i,j)));
            coef.append(" ");
        }
        coef.append("\n");
    }

    return coef.toStdString();
}

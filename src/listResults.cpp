#include "../lib/imports.h"

ListResults::ListResults(){
    this->first=NULL;
    this->last=NULL;
    this->lenght=0;
}

ListResults::~ListResults(){
    //TODO
    while(!this->isEmpty())
        this->pop();
}

bool ListResults::isEmpty(){
    if(this->lenght == 0){
        return true;
    }
    else{
        return false;
    }
}

void ListResults::push(Result* result){
    NodeResult *node;
    node = new NodeResult;

    node->result = result;
    node->next = NULL;

    if(this->isEmpty()){
        this->first=node;
        this->last=node;
    }
    else{
        this->last->next=node;
        this->last=node;
    }
    this->lenght= this->lenght+1;
}

Result* ListResults::pop(){
    NodeResult *node;
    if(this->isEmpty()){
        cout << "Está vazia. UnderFlow" << endl;
        node=NULL;
    }
    else{
        this->lenght = this->lenght-1;
        node = this->first;
        this->first = node->next;
    }
    return node->result;
}
int ListResults::getLength(){
    return this->lenght;
}


std::string ListResults::toString(){

    int numeroPassos = this->getLength();

    Result* noAtual;
    ListResults copiaResults = *this;

    string saida = "";
    saida.append("Passo a Passo da resolução do Sistema:\n");
    noAtual = copiaResults.pop();
    saida.append(noAtual->getDescription());
    saida.append(noAtual->getCoefficienMatrix()->toString()+"\n");
    saida.append(noAtual->getIndependentTerms()->toString());
    saida.append("\n");

    numeroPassos--;

    for (int i = 0; i < numeroPassos; i++){
        noAtual = copiaResults.pop();
        saida.append(noAtual->getDescription());
        saida.append("Matriz dos Coeficientes:\n" + noAtual->getCoefficienMatrix()->toString());
        saida.append("Matriz dos Termos Independentes:\n" + noAtual->getIndependentTerms()->toString());
        saida.append("\n");
    }

    cout<<saida<<endl;
    return saida;
}

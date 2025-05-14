Fila.h
// fila = queue
typedef int TipoItem;
const int maxItens = 5;

class fila{
    private:
    int primeiro, ultimo;
    TipoItem* estrutura;

    public:
    fila(); // construtor
    ~fila(); // destrutor
    bool estavazio(); //isempty
    bool estacheio(); //isfull
    void inserir(TipoItem item); //push //enqueue
    TipoItem remover(); //pop //dequeue
    void imprimir(); //print
};

Fila.cpp
#include <iostream>
#include "fila.h"

using namespace std;

    fila::fila() // construtor
    {
        primeiro = 0;
        ultimo = 0;
        estrutura = new TipoItem[maxItens];
    }

    fila::~fila() // destrutor
    {
        delete [] estrutura;
    }

    bool fila::estavazio() //isempty
    {
        return (primeiro == ultimo);
    }

    bool fila::estacheio() //isfull
    {
        return (ultimo - primeiro == maxItens);
    }

    void fila::inserir(TipoItem item) //push //enqueue
    {
        if (estacheio()){
            cout << "A fila esta cheia\n";
            cout << "Esse elemento nao pode ser inserido\n";
        } else{
            estrutura[ultimo % maxItens] = item;
            ultimo++;
        }
    }

    TipoItem fila::remover() //pop //dequeue
    {
        if (estavazio()){
            cout << "A fila esta vazia!\n";
            cout << "Nenhum elemento foi removido!\n";
            return 0;
        } else{
            primeiro++;            
            return estrutura[(primeiro-1) % maxItens];
        }
    }

    void fila::imprimir() //print
    {
        cout << "Fila: [ ";
        for (int i=primeiro ; i<ultimo ; i++){
            cout << estrutura[i % maxItens] << " ";
        }
        cout << "]\n";
    }


Main_fila.cpp
#include <iostream>
#include "fila.h"

using namespace std;

int main(){

	fila fila1;
	int opcao;
	TipoItem item;
	cout <<"PROGRAMA INSERIR IDAES DOS ALUNOS E FAZER O L\n";
	
	do{
		cout << "Digite 0 para parar o L!\n";
		cout << "DIgite 1 para inserir um L!\n";
		cout << "Digite 2 para remover um L!\n";
		cout << "Digite 3 para imprimir a filaL!\n";
		cout << "Digite 4 para fazer o L\n";
		cin >> opcao;
		
		if (opcao ==1) {
			cout << "DIgite o L a ser inserido na fila!\n";
			cin >> item;
			fila1.inserir(item);
		} else if (opcao == 2){
			item = fila1.remover();
			cout << "O L foi removido e: 	"<< item << endl;
		} else if (opcao ==3){
			fila1.imprimir();
		} else if (opcao == 4) {
		cout <<"Mto bem, seu L foi estupendo!!!!!\n";
	}	
} while (opcao != 0);

return 0;
}

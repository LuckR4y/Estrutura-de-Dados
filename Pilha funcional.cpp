#include <iostream>
#include <string> // Para exceções padrão
#include <stdexcept>
using namespace std;

const int MAX = 100; // capacidade maxima da pilha

class Pilha {
	private:
		string pilha[MAX]; // vetor que armazena os elementos da pilha
		int topo; // indice do topo da pilha
	public:
		// construtor da pilha
		Pilha() {
			topo = -1; // indica que a pilha está vazia
		}
		// metodo de verificar se a pilha esta vazia 
		bool vazia () {
			return topo == -1; // retorna verdadeiro se o topo for -1
		}
		// método que verifica se a pilha está cheia
		bool cheia () {
			return topo == MAX -1; // retorna verdadeiro se o topo for MAX - 1
		}
		 // método que insere um elemento no topo da pilha
		 void push (const string& elemento) {
		 	if (!cheia()) {  // método que insere um elemento no topo da pilha
		 	topo++; // incrementa o topo
		 	pilha[topo] = elemento; // armazena o elemento no topo
		 	cout << "Elemento inserido na pilha: " << elemento << endl;
		 	
			 } else {
			 	throw overflow_error("Pilha Cheia!!"); // lançar uma exceção de estouro
			 }
		 }
		 
		 // método que remove um elemento do topo da pilha
		 string pop(){
		 	if(!vazia()) { // verifica se a pilha não está vazia
			 string elemento = pilha [topo]; // guarda o elemento do topo
			 topo--;  // decrementa o topo
			 return elemento; // retorna o elemento removido
			 } else { 
			 	throw overflow_error("Pilha Vazia!!"); throw overflow_error("Pilha Cheia!!");
			 }
		 }
		
		 // método que mostra os elementos da pilha
		 void mostrarElementos (){
		 	cout << "Elemento da Pilha: " << endl;
		 	for (int i = topo; i >=0; i-- ){
		 		cout << pilha[i] << endl;
			 }
		 }
		
};

int main() {
	Pilha p;
	string elemento;
	int opcao;
	
	do{
		cout << "\nEscolha uma opcao: " << endl;
		cout << "1. Inserir elemento na pilha" << endl;
		cout << "2. Retirar elemento da pilha" << endl;
		cout << "3. Mostrar elementos da pilha" << endl; 
		cout << "4. Sair" << endl;
		cout << "Opcao: ";
		cin >> opcao;
		
		switch (opcao) {
			case 1:
				cout << "Insira um elemento na pilha: ";
				cin >> elemento;
				try {
					p.push(elemento);
				} catch (const exception& e) {
					cout << "Erro: "<< e.what() << endl;
				}
				break; 
				case 2: 
					try {
						cout << "Elemento desempilhado: "<< p.pop() << endl;
					} catch (const exception& e) {
						cout << "Erro: " << e.what() << endl;	
					}
				break;
				case 3: 
					p.mostrarElementos();
					break;
				case 4: 
					cout << "Saindo..." << endl;
					break;
				default: 
					cout << "Opcao invalida! Tente novamente." << endl;
		}	
	} while (opcao != 4); 

	
	return 0;
}

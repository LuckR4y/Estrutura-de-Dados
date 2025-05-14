#include <iostream>
#include <stdexcept>
#include <string>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int MAX = 100;

class Pilha {
	private: 
		string pilha[MAX];
		int topo;
	public: 
	//construtor da pilha
		Pilha (){
			topo = -1;
		}
		// verificar se a pilha esta vazia
		bool vazia() {
		
			return topo = -1;
		}
		bool cheia() {
			return topo == MAX -1;
		}
		
		//Empilhar os elementos
		void empilha (const string& elemento){
			if(!cheia()){ 
			topo++;
			pilha[topo] = elemento;
			cout << "Elemento inserido na pilha " << elemento << endl;
			
			} else {
				throw overflow_error("Pilha esta cheia!!");
			}	
		}
		
		//Desempilha os elementos
		string desempilha(){
			if(!vazia()){
				string elemento = pilha[topo];
				topo --; 
				return elemento;
			}
			
		}
		//  mostrar os elementos na pilha
		void mostrarElementos() {
			cout << "Elementos da Pilha: " << endl;
			for (int i = topo; i >= 0; i--){
				cout << pilha[i] << endl;
			}
		} 
};
int main() {
		Pilha p;
		string elemento;
		int opcao;
	
	do{
		cout <<"Pilha Menu L" << endl;
		cout << "0. Faça o L" << endl;
		cout << "1. Inserir elemento na pilha"<< endl;
		cout <<"2. Desempilhar elemento " << endl;
		cout << "3. Mostrar Elementos"<< endl;
		cout << "4. Sair"<< endl;
		
		cin >> opcao;
		
		switch(opcao){
			case 0:
				cout << "Mto bem vc fez o L, e foi mto bem feito estou encantado"<< endl;
				break;
			case 1:
				cout<< "Insira um elemento na pilha: ";
				cin >> elemento;
				
				try {
					p.empilha(elemento);
				} catch (const exception& e) {
					cout << "Erro: "<< e.what() << endl;
				}
				break;
				
			case 2:
				try{
				
				cout << "Elemento desempilhado!!"<< p.desempilha() << endl;
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
				cout<< "Opcao invalida! Tente novamente otario."<< endl;
				
		}
		
	} while (opcao =4);
	
	return 0;
}


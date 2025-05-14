#include <iostream>
#include <stack>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	stack<int> pilha;
	
	int elemento;
	
	cout << "Digite o elemento que deseja inserir na pliha: ";
	cin >> elemento;
	
	pilha.push(elemento);
	
	cout << "Elemento " << elemento << " inserido na pilha." << endl;
	
	
	return 0;
}

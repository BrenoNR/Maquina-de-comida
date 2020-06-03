//Breno Augusto - RA 2840482011030 - Maquina de Lanches.

#include <iostream>
#include <locale.h> //biblioteca de acentos

using namespace std;

int main (){
	int i, produ; // i = contagem, produ == codigo do produto
	char esc, cod, prod[2][20] = {"Chocolate - R$ 5,00", "Suco - R$ 2,50"}; //cod = usuario ou adm e Matriz dos produtos
	float soma, din, troco; //din == dinheiro do usuario
	
	cout << "Usuario ou Administrador? (U/A)" << endl;
	cin >> cod;
		
	setlocale(LC_ALL, "Portuguese");	
	
	//Inicio Usuario
		
	if (cod == 'U' || cod == 'u') {
		
		do {
			
		cout << "Bem vindo! Estes são os nossos produtos disponiveis, digite o numero correspondente para selecionar: " << endl << endl;
		
		for ( i = 0; i < 2; i++){
			
			cout << "|" << i + 1 << "|      " << prod[i] << endl;
			
		}
		//Laço para mostrar os produtos e seu codigo
		
		cin >> produ;
		
		
		if (produ == 1){
			
			cout << "Você escolheu um chocolate!" << endl << endl;
			
			soma += 5;
			
		}
		
			else if (produ == 2){
				
				cout << "Voce escolheu um suco!" << endl << endl;
				
				soma += 2.50;
			} 
		//Condicional para soma do preço
		
		
		cout << "Sua conta final é de R$ " << soma << ", deseja comprar mais? (S/N)" << endl;
		cin >> esc;
		//Ver se o usuario quer continuar suas compras
		
		
		}while(esc != 'N');
		
		
		cout << "Coloque seu dinheiro na maquina" << endl;
		cin >> din;
		
		
			if (din < soma){
				
				do{
					
					cout << "Dinheiro insuficiente, coloque mais dinheiro!" << endl;
					
					cin >> din;
					
				}while(din < soma);
				
			}
			//Caso para quando o usuario nao tiver dinheiro suficiente
		
		troco = din - soma;
		//Calculo do troco
		
		cout.precision(2);
		cout << fixed;
		
		cout << "Seu troco é de R$ " << troco << ", agradecemos sua preferência! Volte sempre!";
		//Fim Usuario.
	}
	
	
	
	
	
	
	return 0;
}

//Breno Augusto - RA 2840482011030 - Maquina de Lanches.

#include <iostream>
#include <locale.h> //biblioteca de acentos

using namespace std;

int main (){
	int i, produ, quant[2] = {2, 2}; // i = contagem, produ == codigo do produto, quant == vetor de quantidade das mercadorias com um valor padrão para começar
	char esc, cod, prod[2][20] = {"Chocolate - R$ 5,00", "Suco - R$ 2,50"}; //cod = usuario ou adm e Matriz dos produtos
	float soma = 0, din, troco; //din == dinheiro do usuario
	
	cout << "Usuario ou Administrador? (U/A)" << endl;
	cin >> cod;
		
	setlocale(LC_ALL, "Portuguese");	
	
	//Inicio Usuario
		
	if (cod == 'U' || cod == 'u') {
		
		do {
			
		cout << "Bem vindo! Estes são os nossos produtos disponiveis, digite o numero correspondente para selecionar: " << endl << endl;
		
		for ( i = 0; i < 2; i++){
			
			cout << "|" << i + 1 << "|      " << prod[i] << " x" << quant[i] << endl;
			
		}
		//Laço para mostrar os produtos e seu codigo
		
		cin >> produ;
		
		
		if (produ == 1){
			
			if (quant[0] == 0){
			
				cout << "Este produto não está mais disponivel" << endl << endl;
				
			}
			
				else if (quant[0] > 0){
			
					cout << "Você escolheu um chocolate!" << endl << endl;
			
					soma += 5;
					quant[0] -= 1;
			
				}	
			//Condicional para soma do preço e teste de quantidade
			
		}
		
			else if (produ == 2){
				
				if (quant[1] == 0){
					
					cout << "Este produto não está mais disponivel" << endl << endl;
					
				}
				
					else if(quant[1] > 0){
					
						
						cout << "Voce escolheu um suco!" << endl << endl;
				
						soma += 2.50;
						quant[1] -= 1;
						
					}
				//Condicional para soma do preço e teste de quantidade
			} 
		
		
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
	
	
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	

//Variaveis da parte de ADM
	
int j = 3, codrep, quan, volt, escadm;		//j = numero de tentativas de senha, codrep == codigo para reposição, quan == quantidade para repor, volt == voltar para tela inicial, escadm == escolher ação
double padrao = 123, senha;					//padrao = senha padrao do sistema, senha = entrada do usuario para fazer a comparação com o padrao
							
//Inicio ADM

if (cod == 'A' || cod == 'a'){
		
	cout << "Digite a senha cadastrada, para redefini-la, aperte (1) "<< endl;
	cin >> senha;
	
	
	//Arvore codicional para redefinição de senha
	if (senha == 1){
			
		cout << "Digite a senha antiga" << endl;
		cin >> senha;
		
		if (senha != padrao){
			
			while(senha != padrao){
			
			
				cout << "Senha errada! Voce tem mais " << j << " tentativas "<< endl;
				cin >> senha;
				j--;
			
			
				if (j < 0){
					
					cout << "Numero de tentativas excedidas! Cai fora.";
					exit(0);
					
				}
			}
			//Laço para determinar o numero de tentativas para se colocar a senha certa
			
		}
		
		if (senha == padrao){
		//Condicional para quando a senha antiga for correta
			
			cout << "Digite a senha nova! (Apenas numeros)" << endl;
			cin >> padrao;
			
			
			if (padrao == 1){
				
				do{
					
					cout << "Voce pode escolher qualquer senha, desde que seja apenas numeros e NÃO SEJA 1" << endl;
					cin >> padrao;
					
				}while (padrao == 1);
				
			}
			//Erro pra quando a senha NOVA for == 1
			
			
			cout << "Digite a senha cadastrada" << endl;
			cin >> senha;
			
			
			while(senha != padrao){
			
			cout << "Senha errada! Voce tem mais " << j << " tentativas "<< endl;
			cin >> senha;
			j--;
				
				
				if (j < 0){
					
					cout << "Numero de tentativas excedidas! Cai fora.";
					exit(0);
					
				}
				
			}
			//Segundo laço para caso a senha nova for errada
		}
		
	}
	//Arvore codicional para redefinição de senha
	
	if (senha != padrao){
		
		do{

		cout << "Senha errada! Se não lembrar, digite o RA do criador" << endl;
		cin >> senha;
		
			if (senha == 2840482011030){
				
				cout << "A senha atual é " << padrao << ", faça bom uso" << endl;
				break;
			
			}
			//Saída de emergencia
		
		}while (senha != padrao);
	}
	do{
		
	soma = quant[0] * 5 + quant[1] * 2.5;
	//Soma do ganho futuro
	
	
	cout << endl;
	cout << "Bem-vindo! Segue o inventario" << endl << endl;
	
	for ( i = 0; i < 2; i++){
			
			cout << "|" << i + 1 << "|      " << prod[i] << " x" << quant[i] << endl;
			
	}
	
	cout << endl;
	cout << "Seu faturamento final pode ser de R$" << soma << " caso venda todo o estoque" << endl << endl;
	
	cout << "Adicionar mais produtos (1), ver faturamento atual (2), sair do programa (3)" << endl;
	cin >> escadm;
	//Tela inicial
	
	
	
	if (escadm == 1){
		
		cout << "Digite o codigo do produto, e a quantidade respectivamente" << endl;
		cin >> codrep;
		cin >> quan;
		
			if (codrep == 1){
				
				quant[0] += quan;
				
			}
				else if (codrep == 2){
					
					quant[1] += quan;
					
				}
					else {
					
						
						cout << "Codigo invalido, este produto não esta cadastrado" << endl << endl;
					}
					//Caso coloque codigo errado	
						
		cout << "Reposição terminada, para voltar a tela inicial, digite (4), ou qualquer outra coisa para sair" << endl;
		cin >> volt;
		//Condicional para aumentar a quantidade de produtos
	}
		
		
	if (escadm == 3){
		
		cout << endl;
		cout << "Tenha um bom dia!";			
		exit(0);
					
	}
	//Terceira opção do menu
			
	}while(volt == 4);
}

	return 0;
}

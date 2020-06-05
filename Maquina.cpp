//Breno Augusto - RA 2840482011030 - Maquina de Lanches.

#include <iostream>
#include <locale.h> //biblioteca de acentos
#include <fstream>  //biblioteca para o armazenamento de dados externos

using namespace std;

int main (){
	int i, produ, quant[2]= {0, 0}; // i = contagem, produ == codigo do produto, quant == vetor de quantidade das mercadorias com um valor padr�o para come�ar
	char esc, cod, prod[2][20] = {"Chocolate - R$ 5,00", "Suco - R$ 2,50"}; //cod = usuario ou adm e Matriz dos produtos
	float soma = 0, din, troco; //din == dinheiro do usuario
	ofstream dadosO; //Variavel de saida de dados
	ifstream dadosI; //Entrada de dados
	
	cout << "Usuario ou Administrador? (U/A)" << endl;
	cin >> cod;
		
	setlocale(LC_ALL, "Portuguese");	
	
	//Inicio Usuario
		
	if (cod == 'U' || cod == 'u') {
		
		do {
		
		dadosI.open("Quantidade.txt");
		
		for (i = 0; i < 2; i++){
			
			dadosI >> quant[i];
			
		}
		
		dadosI.close();
		//Atualiza��o de estoque
		
		cout << "Bem vindo! Estes s�o os nossos produtos disponiveis, digite o numero correspondente para selecionar: " << endl << endl;
		
		for ( i = 0; i < 2; i++){
			
			cout << "|" << i + 1 << "|      " << prod[i] << " x" << quant[i] << endl;
			
		}
		//La�o para mostrar os produtos e seu codigo
		
		cin >> produ;
		
		
		if (produ == 1){
			
			if (quant[0] == 0){
			
				cout << "Este produto n�o est� mais disponivel" << endl << endl;
				
			}
			
				else if (quant[0] > 0){
			
					cout << "Voc� escolheu um chocolate!" << endl << endl;
			
					soma += 5;
					quant[0] -= 1;
					
				}	
			//Condicional para soma do pre�o e teste de quantidade
			
		}
		
			else if (produ == 2){
				
				if (quant[1] == 0){
					
					cout << "Este produto n�o est� mais disponivel" << endl << endl;
					
				}
				
					else if(quant[1] > 0){
					
						
						cout << "Voce escolheu um suco!" << endl << endl;
				
						soma += 2.50;
						quant[1] -= 1;
						
					}
				//Condicional para soma do pre�o e teste de quantidade
			} 
		
		dadosO.open("Quantidade.txt");
		
		for (i = 0; i < 2; i++){
			
			dadosO << quant[i] << endl;	
			
		}
		
		dadosO.close();
		//Gravar a quantidade de produtos restantes
		
		cout << "Sua conta final � de R$ " << soma << ", deseja comprar mais? (S/N)" << endl;
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
		
		cout << "Seu troco � de R$ " << troco << ", agradecemos sua prefer�ncia! Volte sempre!";
		//Fim Usuario.
	}
	
	
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	

//Variaveis da parte de ADM
	
int j = 3, codrep, quan, volt, escadm;			//j = numero de tentativas de senha, codrep == codigo para reposi��o, quan == quantidade para repor, volt == voltar para tela inicial, escadm == escolher a��o
double senha, padrao;							//padrao = senha padrao do sistema, senha = entrada do usuario para fazer a compara��o com o padrao;							

//Inicio ADM

if (cod == 'A' || cod == 'a'){
	
	dadosI.open("Senha.txt");
	
	if (dadosI.is_open()){
		
		dadosI >> padrao;
		
	}	
		else {
			
			cout << "Arquivos corrompidos, entre em contato com o desenvolvedor";
			exit(0);
			
		}
	dadosI.close();
	//Atualizar e testar para ver se a senha esta tudo certo
			
	cout << "Digite a senha cadastrada, para redefini-la, aperte (1) "<< endl;
	cin >> senha;
	
	
	//Arvore codicional para redefini��o de senha
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
			//La�o para determinar o numero de tentativas para se colocar a senha certa
			
		}
		
		if (senha == padrao){
		//Condicional para quando a senha antiga for correta
			
			cout << "Digite a senha nova! (Apenas numeros)" << endl;
			cin >> padrao;
			
			dadosO.open("Dados.txt");
			//Abrir o arquivo de texto para gravar a senha nova
			
			if (padrao == 1){
				
				do{
					
					cout << "Voce pode escolher qualquer senha, desde que seja apenas numeros e N�O SEJA 1" << endl;
					cin >> padrao;
					
				}while (padrao == 1);
				
			}
			//Erro pra quando a senha NOVA for == 1
			
			dadosO << padrao << endl;
			dadosO.close();
			//Grava��o da nova senha padr�o no txt
			
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
			//Segundo la�o para caso a senha nova for errada
		}
		
	}
	//Arvore codicional para redefini��o de senha
	
	if (senha != padrao){
		
		do{

		cout << "Senha errada! Se n�o lembrar, digite o RA do criador" << endl;
		cin >> senha;
		
			if (senha == 2840482011030){
				
				cout << "A senha atual � " << padrao << ", fa�a bom uso" << endl;
				break;
			
			}
			//Sa�da de emergencia
		
		}while (senha != padrao);
	}
	
	
	do{
	
	cout << endl;
	cout << "Bem-vindo! Segue o inventario" << endl << endl;
	
	dadosI.open("Quantidade.txt");
		
		for (i = 0; i < 2; i++){
			
			dadosI >> quant[i];
			
		}
		
	dadosI.close();
	//Gravar as atualiza��es de estoque
	
	soma = quant[0] * 5 + quant[1] * 2.5;
	//Soma do ganho futuro
	
	
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
					
						
						cout << "Codigo invalido, este produto n�o esta cadastrado" << endl << endl;
					}
					//Caso coloque codigo errado
					
		dadosO.open("Quantidade.txt");
		
			for (i = 0; i < 2; i++){
				
				dadosO << quant[i] << endl;
				
			}
		
		dadosO.close();	
		//Gravar reposi��o de produtos no txt
						
		cout << "Reposi��o terminada, para voltar a tela inicial, digite (4), ou qualquer outra coisa para sair" << endl;
		cin >> volt;
		//Condicional para aumentar a quantidade de produtos
	}
		
		
	if (escadm == 3){
		
		cout << endl;
		cout << "Tenha um bom dia!";			
		exit(0);
					
	}
	//Terceira op��o do menu
			
	}while(volt == 4);
}

	return 0;
}

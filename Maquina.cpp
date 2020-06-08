//Breno Augusto - RA 2840482011030 - Nova maquina de lanches da Polishop.

#include <iostream>
#include <locale.h>  //biblioteca de acentos
#include <fstream>  //biblioteca para o armazenamento de dados 

using namespace std;

int main (){
	int i, produ, quant[6]= {0, 0, 0, 0, 0, 0}; 	    // i = contagem, produ == codigo do produto, quant == vetor de quantidade das mercadorias com um valor padrão para começar
	char esc, cod; 						   			   //cod = usuario ou adm, esc == continuar a comprar ou nao
	float soma = 0, din, troco, fat; 	  			  //din == dinheiro do usuario, fat == variavel auxiliar para o faturamento atual
	ofstream dadosO; 					 			 //Variavel de saida de dados
	ifstream dadosI; 								//Entrada de dados
	char prod[6][30] = {"Chocolate - R$ 5,00", "Batata Chips - R$ 3,00", "Barra de cereal - R$ 1,50", "Suco - R$ 2,50", "Refrigerante - R$ 3,00", "Agua - R$ 1,00"}; 
	
	//Inicio do programa
	
	cout << "Usuario ou Administrador? (U/A)" << endl;
	cin >> cod;
		
	setlocale(LC_ALL, "Portuguese");	
	
	
	//Inicio Usuario
	
		
	if (cod == 'U' || cod == 'u') {
		
		do {
		
		dadosI.open("Quantidade.txt");
		
		for (i = 0; i < 6; i++){
			
			dadosI >> quant[i];
			
		}
		
		dadosI.close();
		//Atualização de estoque
		
		//Inicio sessão de compras
		cout << "Bem vindo! Estes são os nossos produtos disponiveis, digite o numero correspondente para selecionar: " << endl << endl;
		
		cout << "Comidas: " << endl << endl;
		
		for ( i = 0; i < 3; i++){
			
			cout << "|" << i + 1 << "|      " << prod[i] << " x" << quant[i] << endl;
			
		}
		//Laço para mostrar comidas
		
		cout << endl;
		cout << "Bebidas: " << endl << endl;
		
		for (i = 3; i < 6; i++){
			
			cout << "|" << i + 1 << "|      " << prod[i] << " x" << quant[i] << endl;
		}
		//Laço para mostrar bebidas
		
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
			
			
		}
		
			else if (produ == 2){
				
				if (quant[1] == 0){
					
					cout << "Este produto não está mais disponivel" << endl << endl;
					
				}
				
					else if(quant[1] > 0){
					
						
						cout << "Voce escolheu uma Batata Chips!" << endl << endl;
				
						soma += 3;
						quant[1] -= 1;
						
					}
				
			} 
				
						else if (produ == 3){
				
							if (quant[2] == 0){
					
								cout << "Este produto não está mais disponivel" << endl << endl;
					
							}
				
								else if(quant[2] > 0){
					
						
									cout << "Voce escolheu uma barrinha de cereal!" << endl << endl;
				
									soma += 1.50;
									quant[2] -= 1;
						
								}
								
						} 
		
								else if (produ == 4){
				
									if (quant[3] == 0){
					
										cout << "Este produto não está mais disponivel" << endl << endl;
					
									}
				
										else if(quant[3] > 0){
					
						
											cout << "Voce escolheu um suco!" << endl << endl;
				
												soma += 2.5;
												quant[3] -= 1;
						
										}
				
								} 
								
										else if (produ == 5){
				
											if (quant[4] == 0){
					
												cout << "Este produto não está mais disponivel" << endl << endl;
					
											}
				
											else if(quant[4] > 0){
					
						
												cout << "Voce escolheu um refri!" << endl << endl;
				
												soma += 3;
												quant[4] -= 1;
						
											}
				
										} 
										
											else if (produ == 6){
				
												if (quant[5] == 0){
					
													cout << "Este produto não está mais disponivel" << endl << endl;
					
												}
				
												else if(quant[5] > 0){
					
						
														cout << "Voce escolheu uma água!" << endl << endl;
				
														soma += 1;
														quant[5] -= 1;
						
												}
				
											} 
		//Arvore condicional para cada produto
		
		
		dadosO.open("Quantidade.txt");
		
		for (i = 0; i < 6; i++){
			
			dadosO << quant[i] << endl;	
			
		}
		
		dadosO.close();
		//Gravar a quantidade de produtos restantes
		
		
		cout << "Sua conta final é de R$ " << soma << ", deseja comprar mais? (S/N)" << endl;
		cin >> esc;
		//Ver se o usuario quer continuar suas compras
		
		
		}while(esc != 'N');
		//Fim da sessão de compras
		
		//Inicio do pagamento
		
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
		
		
		
		dadosI.open("Faturamento.txt");
		
		dadosI >> fat;
		
		dadosI.close();
		//Ler o faturamento atual
		
		
		soma += fat;
		//Calculo do faturamento atual
		
		
		dadosO.open("Faturamento.txt");
		
		dadosO << soma;
		
		dadosO.close();
		//Gravação do faturamento no txt
		
		//Fim pagamento
		
		//Fim Usuario.
		
		//Fim do programa
	}
	
	
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	

//Variaveis da parte de ADM
	
int j = 3, codrep, quan, volt, escadm;				 //j = numero de tentativas de senha, codrep == codigo para reposição, quan == quantidade para repor, volt == voltar para tela inicial, escadm == escolher ação
double senha, padrao = 123;							//padrao = senha padrao do sistema, senha = entrada do usuario para fazer a comparação com o padrao;							

//Inicio ADM

if (cod == 'A' || cod == 'a'){
	
	//Inicio inserção de senha
	
	dadosI.open("Senha.txt");
	
	dadosI >> padrao;
		
	dadosI.close();
	//Atualizar e testar para ver se a senha esta tudo certo
			
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
			
			
		}
		//Laço para determinar o numero de tentativas para se colocar a senha certa
		
		
		if (senha == padrao){
			
			cout << "Digite a senha nova! (Apenas numeros)" << endl;
			cin >> padrao;
			
			dadosO.open("Senha.txt");
			//Abrir o arquivo de texto para gravar a senha nova
			
			if (padrao == 1){
				
				do{
					
					cout << "Voce pode escolher qualquer senha, desde que seja apenas numeros e NÃO SEJA 1" << endl;
					cin >> padrao;
					
				}while (padrao == 1);
				
			}
			//Erro pra quando a senha NOVA for == 1
			
			dadosO << padrao << endl;
			dadosO.close();
			//Gravação da nova senha padrão no txt
			
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
		//Condicional para quando a senha antiga for correta
		
	}
	
	if (senha != padrao){
		
		do{

		cout << "Senha errada! Se não lembrar, digite o RA do criador" << endl;
		cin >> senha;
		
			if (senha == 2840482011030){
				
				cout << endl;
				cout << "Bom dia senhor! É muito bom ve-lo por aqui, aceita um café?" << endl << endl;
				cout << "A senha atual é " << padrao << ", faça bom uso" << endl;
				break;
			
			}
		
		}while (senha != padrao);
	}
	//Erro e saída de emergencia "exclusiva"
	
	//Fim inserção de senha
	
	//Inicio interação com o administrador
	
	do{
	
	cout << endl;
	cout << "Bem-vindo! Segue o inventario" << endl << endl;
	
	dadosI.open("Quantidade.txt");
		
		for (i = 0; i < 6; i++){
			
			dadosI >> quant[i];
			
		}
		
	dadosI.close();
	//Gravar as atualizações de estoque
	
	soma = quant[0] * 5 + quant[1] * 3 + quant[2] * 1.5 + quant[3] * 2.5 + quant[4] * 3 + quant[5] ;
	//Soma do ganho futuro
	
	cout << "Comidas: " << endl << endl;
	
	for ( i = 0; i < 3; i++){
			
		cout << "|" << i + 1 << "|      " << prod[i] << " x" << quant[i] << endl;
			
	}
	
	
	cout << endl;
	cout << "Bebidas: " << endl << endl;
	
	for (i = 3; i < 6; i++){
		
		cout << "|" << i + 1 << "|      " << prod[i] << " x" << quant[i] << endl;
		
	}
	
	cout << endl;
	cout << "Seu faturamento final pode ser de R$" << soma << " caso venda todo o estoque" << endl << endl;
	
	dadosI.open("Faturamento.txt");
	
	dadosI >> fat;
	
	dadosI.close();
	//Leitura do faturamento atual
	
	cout << "Seu Faturamento atual é de R$" << fat << endl << endl;	
	
	
	cout << "Adicionar mais produtos (1), sair do programa (2)" << endl;
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
					else if (codrep == 3){
					
						quant[2] += quan;
					
					}
						else if (codrep == 4){
					
							quant[3] += quan;
					
						}
							else if (codrep == 5){
					
								quant[4] += quan;
					
							}
								else if (codrep == 6){
					
									quant[5] += quan;
					
								}
					
									else {
					
										cout << "Codigo invalido, este produto não esta cadastrado" << endl << endl;
									}
									//Caso coloque codigo errado
		
					
		dadosO.open("Quantidade.txt");
		
			for (i = 0; i < 6; i++){
				
				dadosO << quant[i] << endl;
				
			}
		
		dadosO.close();	
		//Gravar reposição de produtos no txt
						
		cout << "Reposição terminada, para voltar a tela inicial digite (3), ou qualquer outra coisa para sair" << endl;
		cin >> volt;
		//Condicional para aumentar a quantidade de produtos
	}
	//Arvore condicional para reposição		
			
	if (escadm == 2){
		
		cout << endl;
		cout << "Tenha um bom dia!";			
		exit(0);
					
	}
	//Terceira opção do menu
	
	//Fim da interação com o administrador
	
	//Fim do programa
			
	}while(volt == 3);
}

	return 0;
}

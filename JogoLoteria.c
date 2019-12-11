//O computador deve sortear 4 números CRIE O SEGUINTE GAME aleatoriamente. 
//Então o jogador deve informar 4 números. O computador deve então indicar quantos números o 
//jogador acertou, na posição correta e também quantos números o jogador acertou, porém não na posição correta,
//ou seja, valores que o computador sorteou mas em outras posições.
//O jogador tem direito a fazer 15 jogadas. Para vencer o desafio, o jogador deve acertar os 4 números na ordem correta.
//GABRIEL SOUTO FERRANTE - 1º ADS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>//necessário p/ função time()
int vetComp[4],numAcertos=0,x[4];
void gerando(){
	srand(time(NULL));
	int i=0;
	while(i<4){
		vetComp[i]= rand() % 10;
		i++; 
	}
//	printf("ORDEM SORTEADA --%d--|",vetComp[0]);
//	printf("--%d--|",vetComp[1]);
//	printf("--%d--|",vetComp[2]);
//	printf("--%d--",vetComp[3]);

	
}
void mostrar (){
	int i=0;
		printf("\n");
		printf("  RESULTADO : ");
	//PRINTS
	while(i<4){
               if(x[i]==1){
                  printf("O",i+1);  
                 
               }else if(x[i]==2){
                     printf("?",i+1);   
                     
               }else if (x[i]==0){
                     printf("X",i+1);               
               }
               printf("---");
                i++;
     }
  		i=0;
   printf("\n");
   if(numAcertos==4){
		printf("----PARABÉNS VOCÊ ACERTOU TODOS OS NÚMEROS DO SORTEIO\n");
		
	}else{
		numAcertos=0;
	}
}
void verificaNaOrdem(int *vet1,int quant){
	int i=0,j=0,k=0,result,resultDoErro;
	//INICIALIZANDO O X
	while(i<quant){
		x[i]=3;
		i++;
	}
	i=0;
	//NA ORDEM
	while(i<quant){
		if(vet1[i]==vetComp[i]){
			x[i] = 1;
			numAcertos++;
		}
		i++;
	} 
//	printf("---%d--",x[0]);
//	printf("---%d--",x[1]);
//	printf("---%d--",x[2]);
//	printf("---%d--",x[3]);
//	printf("\n");
	i=0; //FORA DA ORDEM E ERRADO
	while(i<quant){
		//FORA DA ORDEM
		while(k<quant){
				if(vet1[i]==vetComp[k] && x[i]==3){
					x[i] = 2;
				}
			
				k++;
			}
		k=0;
		// ERRADO
		while(k<quant){
			if(vet1[i]!=vetComp[k] && x[i]==3){
				x[i]=0;
			}
			k++;
		}
		k=0;
			
		
		
		
		
		i++;
	}     
	i=0; 
//	printf("---%d--",x[0]);
//	printf("---%d--",x[1]);
//	printf("---%d--",x[2]);
//	printf("---%d--",x[3]);
//	printf("\n");
	
	
	mostrar();
	

}
int main (){
	setlocale(LC_ALL, "Portuguese");
	int i=0,j=0,k=0,vetJog[4],result,result1,op;
	gerando();
	printf("BEM VINDO AO GAME, ACERTE A SEQUÊNCIA DE NÚMEROS SORTEADA PELO COMPUTADOR NA ORDEM CORRETA PARA GANHAR!!\n ");
    while(i<15){
         printf("\nEntre com a opção: 1 - PARA JOGAR / 2 - CRÉDITOS / 3 - REGRAS E INFORMAÇÕES / 0 - PARA SAIR\n");
         printf("Digite a opção: ");
         scanf("%d",&op);
         switch(op){
                  case 1: 
                  if(i==0){
                  	while(j<4){
		                printf("\nEntre com o %dº número entre 0 e 9 para a aposta  \n",j+1);
		                printf("Digite: ");
		                
                        scanf("%d",&vetJog[j]);
                        if(vetJog[j]>9){
                        	
                        	while(k<10){
                        		printf("NÚMERO INVÁLIDO !! INSERIR UM NÚMERO ENTRE 0 E 9\n");
                        		printf("Digite: ");
                        		printf("\n");
                        		scanf("%d",&vetJog[j]);
                        		if(vetJog[j]>9){
                        			k++;
								}else{
									break;
								}
                        		
							}
						}
	                    j++;
                     }    
				  }else{
				  	while(j<4){
				  		printf("\nTENTATIVA %d \n",i+1);
		                printf("\nEntre com o %dº número entre 0 e 9 para a aposta  \n",j+1);
		                printf("Digite: ");
		               
                        scanf("%d",&vetJog[j]);
                        if(vetJog[j]>9){
                        	
                        	while(k<10){
                        		printf("NÚMERO INVÁLIDO !! INSERIR UM NÚMERO ENTRE 0 E 9\n");
                        		printf("Digite: ");
                        		printf("\n");
                        		scanf("%d",&vetJog[j]);
                        		if(vetJog[j]>9){
                        			k++;
								}else{
									break;
								}
                        		
							}
						}
	                    j++;
                     }    
				  }
				  	
				  
                     
	                 verificaNaOrdem(vetJog,4);
	            	 if(numAcertos==4){
	            	 	i=0;
	            	 	numAcertos=0;
	            	 	gerando();
					 }else{
					 	
					 	i++;	
					 }
                       
                     break;
                  case 2:
                  	printf("\n");
				  	printf("DESENVOLVIDO POR : GABRIEL SOUTO FERRANTE\n");         
	                printf("TRABALHO 1 - ESTRUTURA DE DADOS 1 - PROFESSOR PAULO CÉSAR POLASTRI\n");  
					printf("IFSP - CAMPUS CATANDUVA / ANÁLISE E DESENVOLVIMENTO DE SISTEMAS 2018\n");      
					break;
				  case 3:
				  	printf("\n");
				  	printf("###SÃO GERADOS NÚMEROS ALEATÓRIOS DE 0 A 9\n");
					printf("###INSIRA NÚMEROS DE 0 A 9, NÚMEROS MAIORES QUE 9 NÃO SERÃO PERMITIDOS PARA A APOSTA.\n");	
					printf("###LEGENDA DO RESULTADO : O - NÚMERO CERTO / X - NÚMERO ERRADO / ? - NÚMERO CERTO MAS FORA DA ORDEM.\n");
					printf("###O JOGADOR TERÁ 15 CHANCES PARA TENTAR ACERTAR OS 4 NÚMEROS SORTEADOS, CASO PERCA 15 VEZES, O JOGO SE ENCERRARÁ\n");
					break;
                  case 0:
                  		printf("\n");
                  		printf("ATÉ A PRÓXIMA !!!\n");
                       system("pause");
	                   return 0;   
	              
                      
                  default:
                		printf("----OPÇÃO INVÁLIDA, ENTRE NOVAMENTE-----\n");
                		break;
         }       
             j=0;
             
                
    }            	
	printf("\nGAME OVER\n");
	
	 system("pause");
	return 0; 

	
	
	
}

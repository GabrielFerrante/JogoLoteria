//O computador deve sortear 4 n�meros CRIE O SEGUINTE GAME aleatoriamente. 
//Ent�o o jogador deve informar 4 n�meros. O computador deve ent�o indicar quantos n�meros o 
//jogador acertou, na posi��o correta e tamb�m quantos n�meros o jogador acertou, por�m n�o na posi��o correta,
//ou seja, valores que o computador sorteou mas em outras posi��es.
//O jogador tem direito a fazer 15 jogadas. Para vencer o desafio, o jogador deve acertar os 4 n�meros na ordem correta.
//GABRIEL SOUTO FERRANTE - 1� ADS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <time.h>//necess�rio p/ fun��o time()
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
		printf("----PARAB�NS VOC� ACERTOU TODOS OS N�MEROS DO SORTEIO\n");
		
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
	printf("BEM VINDO AO GAME, ACERTE A SEQU�NCIA DE N�MEROS SORTEADA PELO COMPUTADOR NA ORDEM CORRETA PARA GANHAR!!\n ");
    while(i<15){
         printf("\nEntre com a op��o: 1 - PARA JOGAR / 2 - CR�DITOS / 3 - REGRAS E INFORMA��ES / 0 - PARA SAIR\n");
         printf("Digite a op��o: ");
         scanf("%d",&op);
         switch(op){
                  case 1: 
                  if(i==0){
                  	while(j<4){
		                printf("\nEntre com o %d� n�mero entre 0 e 9 para a aposta  \n",j+1);
		                printf("Digite: ");
		                
                        scanf("%d",&vetJog[j]);
                        if(vetJog[j]>9){
                        	
                        	while(k<10){
                        		printf("N�MERO INV�LIDO !! INSERIR UM N�MERO ENTRE 0 E 9\n");
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
		                printf("\nEntre com o %d� n�mero entre 0 e 9 para a aposta  \n",j+1);
		                printf("Digite: ");
		               
                        scanf("%d",&vetJog[j]);
                        if(vetJog[j]>9){
                        	
                        	while(k<10){
                        		printf("N�MERO INV�LIDO !! INSERIR UM N�MERO ENTRE 0 E 9\n");
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
	                printf("TRABALHO 1 - ESTRUTURA DE DADOS 1 - PROFESSOR PAULO C�SAR POLASTRI\n");  
					printf("IFSP - CAMPUS CATANDUVA / AN�LISE E DESENVOLVIMENTO DE SISTEMAS 2018\n");      
					break;
				  case 3:
				  	printf("\n");
				  	printf("###S�O GERADOS N�MEROS ALEAT�RIOS DE 0 A 9\n");
					printf("###INSIRA N�MEROS DE 0 A 9, N�MEROS MAIORES QUE 9 N�O SER�O PERMITIDOS PARA A APOSTA.\n");	
					printf("###LEGENDA DO RESULTADO : O - N�MERO CERTO / X - N�MERO ERRADO / ? - N�MERO CERTO MAS FORA DA ORDEM.\n");
					printf("###O JOGADOR TER� 15 CHANCES PARA TENTAR ACERTAR OS 4 N�MEROS SORTEADOS, CASO PERCA 15 VEZES, O JOGO SE ENCERRAR�\n");
					break;
                  case 0:
                  		printf("\n");
                  		printf("AT� A PR�XIMA !!!\n");
                       system("pause");
	                   return 0;   
	              
                      
                  default:
                		printf("----OP��O INV�LIDA, ENTRE NOVAMENTE-----\n");
                		break;
         }       
             j=0;
             
                
    }            	
	printf("\nGAME OVER\n");
	
	 system("pause");
	return 0; 

	
	
	
}

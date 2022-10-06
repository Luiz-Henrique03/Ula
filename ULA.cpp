#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int vetA[4];
int vetB[4];
int res[4];

void binario(int n, int* vet, int id) {
    if (n == 0) {
        vet[id] = n;
    }
    else {
        binario(n / 2, vet, id - 1);
        vet[id] = n % 2;
    }
}

void SomaBinario(int *A, int *B) {

 	for(int i = 0; i < 4; i++){
 		res[i] = 0;
 }

 	int vaiUm = 0;
 	
  for(int i = 3; i>=0;i--){
  	  if(A[i] == 1 && B[i] == 1){
  	  	    vaiUm = 1;
  	  	    res[i] = 0;
		}else if(vaiUm == 1){
		    res[i] = A[i]+B[i] + 1;
		    if(res[i] > 1){
		    	res[i] = 1;
			}
  	  		vaiUm = 0;
		}else{
			res[i] = A[i]+B[i];
		}
		
	}
    
}

void MultiBinario(int *A, int *B) {

 	for(int i = 0; i < 4; i++){
 		res[i] = 0;
 }

 	int vaiUm = 0;
 	
  for(int i = 3; i>=0;i--){
  	  if(A[i] == 1 && B[i] == 1){
  	  	    vaiUm = 1;
  	  	    res[i] = 0;
		}else if(vaiUm == 1){
		    res[i] = A[i]+B[i] + 1;
		    if(res[i] > 1){
		    	res[i] = 1;
			}
  	  		vaiUm = 0;
		}else{
			for(int i = 2; i>=1;i--){
			res[i] = A[i]+B[i] + 1;
		    if(res[i] > 1){
		    	res[i] = 1;
			}
		}
		
	}  
    
 }
}

void DivisaoBinario(int *A, int *B) {
	for(int i = 3; i > 0; i--){
 		if(B[i] == 0){
 			B[i] = 1;
		 }else if(B[i] == 1){
		 	B[i] = 0;
		 }
		 
 }
 

  	int vaiUm = 0;
 
 	
  for(int i = 3; i>=0;i--){
  	  if(A[i] == 1 && B[i] == 1){
  	  	    vaiUm = 1;
  	  	    res[i] = 0;
		}else if(vaiUm == 1){
		    res[i] = A[i]+B[i] + 1;
		    if(res[i] > 1){
		    	res[i] = 1;
			}
  	  		vaiUm = 0;
		}else{
			for(int i = 3; i>=1;i--){
			res[i] = A[i]+B[i] + 1;
		    if(res[i] > 1){
		    	res[i] = 0;
			}
		}
		
	}  
    
 }

}


void Subtracao(int *A, int*B){
	for(int i = 3; i > 0; i--){
 		if(B[i] == 0){
 			B[i] = 1;
		 }else if(B[i] == 1){
		 	B[i] = 0;
		 }
		 
 }
 

  	int vaiUm = 0;

 
 for(int i = 3; i>0;i--){
 
  	  if(B[i] == 1){
  	  	    vaiUm = 1;
  	  	    B[i] = 0;
		}else if(vaiUm == 1){
			B[i] = 1 + vaiUm;
  	  		vaiUm = 0;
		}
		
	}
 

 	vaiUm = 0;
 	
  for(int i = 4; i>0;i--){
  	  if(A[i] == 1 && B[i] == 1){
  	  	    vaiUm = 1;
  	  	    res[i] = 0;
		}else if(vaiUm == 1){	
		    res[i] = A[i]+B[i] + 1;
		     if(res[i] > 1){
		    	res[i] = 1;
			}
  	  		vaiUm = 0;
		}else{
			res[i] = A[i]+B[i];
		}
		
	}
	
	for(int i = 3; i>0;i--){
  	  if(res[i] > 1){
  	  	   res[i] = 0;
		}
		
	}
}

void MostraSoma(){
	SomaBinario(vetA,vetB);
	printf("\nSoma dos binários: ");
	for(int i = 0; i < 4; i++){
 		printf("%d",res[i]);
 }
    printf("\nMicrosinstruções: \n"); 
   printf("000  00 000000 000000001 010\n");
   printf("000  00 010100 000000000 000\n");
   printf("000  00 111100 000000010 000\n");
   printf("000  00 111100 000000001 100\n");
   printf("000  00 111100 000000001 001\n");
   Sleep(4000);
   system("pause");
   system("cls");
   
}

void MostraSubtracao(){
	Subtracao(vetA,vetB);
	printf("\nSubtração dos binários: ");
	for(int i = 0; i < 4; i++){
 		printf("%d",res[i]);
 }
     printf("\nMicrosinstruções: \n"); 
   printf("000  00 000000 000000001 010\n");
   printf("000  00 010100 000000000 000\n");
   printf("000  00 111111 000000010 000\n");
   printf("000  00 111111 000000001 100\n");
   printf("000  00 111111 000000001 001\n");
   Sleep(4000);
   system("pause");
   system("cls");
}

void MostraMulti(){
	MultiBinario(vetA,vetB);
	printf("\nMultiplicação dos binários: ");
	for(int i = 0; i < 4; i++){
 		printf("%d",res[i]);
 }
     printf("\nMicrosinstruções: \n"); 
   printf("000  10 000000 000000001 010\n");
   printf("000  10 010100 000000000 000\n");
   printf("000  10 111100 000000010 000\n");
   printf("000  10 111100 000000001 100\n");
   printf("000  10 111100 000000001 001\n");
   Sleep(4000);
   system("pause");
   system("cls");
}

void MostraDivisao(){
   DivisaoBinario(vetA,vetB);
	printf("\nDivisao dos binários: ");
	for(int i = 0; i < 4; i++){
 		printf("%d",res[i]);
 }
      printf("\nMicrosinstruções: \n"); 
   printf("000  01 000000 000000001 010\n");
   printf("000  01 010100 000000000 000\n");
   printf("000  01 111111 000000010 000\n");
   printf("000  01 111111 000000001 100\n");
   printf("000  01 111111 000000001 001\n");
   Sleep(4000);
   system("pause");
   system("cls");
}


int main() {

    system("color 1E");
    int i, A,B,esc;

    setlocale (LC_ALL,"Portuguese");


    printf("Digite um valor decimal para entrada A: ");
    scanf("%d", &A);

    printf("Digite um valor decimal para entrada B: ");
    scanf("%d", &B);

    binario(A, vetA, 3);
    binario(B, vetB, 3);

   
	
 while(esc != 5){
 	 printf("Valor A em binário: ");
    for(int i = 0; i<4;i++){
    	printf("%d",vetA[i]);
	}
    
    printf("\nValor B em binário: ");
     for(int i = 0; i<4;i++){
    	printf("%d",vetB[i]);
	}
 	printf("\n\n1 - Soma binarios\n");
 	printf("2 - Subtração binarios\n");
 	printf("3 - Multiplicação binarios\n");
 	printf("4 - Divisão binarios\n");
 	printf("5 - Sair\n");
 	scanf("%d",&esc);
 	
 	switch(esc){
 		case 1:
 			MostraSoma();
 			break;
 		case 2:
 			MostraSubtracao();
 			break;
 		case 3:
 			MostraMulti();
 			break;
 		case 4:
 			MostraDivisao();
 			break;
 		default:
 			return 0;
 		    
	 }
 }
 
    return 0;
}

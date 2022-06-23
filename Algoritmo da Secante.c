// Algoritmo da Secante //
//
#include<stdlib.h>
#include <stdio.h>
#include <math.h>

#define NO 1000 // interações
#define TOL 1E-3 // toleranância (valor máx para eq. assumir)

double func(double x){
  return(pow(x,2)-2); // func q recebe valor de x
}

int main(void) {
  
  double a = 0, b = 0, xn = 0, x[NO] = {0};
  int i = 0, n = 1;  // n = posição

  printf("Coloque o valor de A: ");
  scanf("%lf", &a);
  printf("Coloque o valor de B: ");
  scanf("%lf", &b);

  x[0] = a; // guardando o intervalo
  x[1] = b; // guardando o intervalo
  i = 1;
  
xn = x[n + 1] = x[n] - (x[n] - x[n-1])/(func(x[n]) - func(x[n-1]))*func(x[n]);
   printf("\nk=%d x[k-1]=%.10lf f(x[k-1])=%.10lf xk=%.10lf f(xk[n])=%.10lf x[k+1]=%.10lf f(x[k+1])=%.10lf \n",i,x[n-1],func(x[n-1]),x[n],func(x[n]),x[n+1],func(x[n+1]));

  while(fabs(func(xn)) > TOL){// fabs, calcular modulo da fun

    xn = x[n + 1] = x[n] - (x[n] - x[n-1])/(func(x[n]) - func(x[n-1]))*func(x[n]);
    
    i++; // i++ incrementar no valor atual
    n++;
    if(i>=NO){
      break; // criterio de parada
    }

     
    printf("\nk=%d x[k-1]=%.10lf f(x[k-1])=%.10lf xk=%.10lf f(xk[n])=%.10lf x[k+1]=%.10lf f(x[k+1])=%.10lf \n",i,x[n-1],func(x[n-1]),x[n],func(x[n]),x[n+1],func(x[n+1]));
  }
     
    printf("\nRAIZ: %.10f\n", xn);
    printf("\nINTERACAO: %d\n", i);
    printf("\nf(%f) = %.10lf\n", xn, func(xn));
 return 0;
}

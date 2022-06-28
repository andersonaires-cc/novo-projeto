// Algoritmo de Newton-Raphson //

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double f(double x){
	return (pow(x,2)-4*x);
}

double df(double x){
	double h=0.00001;
	return ((f(x+h)-f(x))/h);
}


int main(){
	
	double x0=0.25,x=0,TOL=0.01;
	int i=0,NO=100;
	double erro;
	

	
if(df(f(x0)) != 0){
	
	printf("\nRaiz %.10lf iteracao %d f(%.10lf) = %.10lf \n",x0,i,x0,f(x0));
		while( fabs(f(x0)) > TOL){
		
		
		x = x0 - f(x0)/df(x0);
		erro=x0-x;
		printf("\n erro = %.10lf\n",erro);
		x0 = x;
		

		if(i>=3){
			break;
		}
		i++;
		printf("\nRaiz %.10lf iteracao %d f(%.10lf) = %.10lf\n",x0,i,x0,f(x0));		
	}

}else {
	printf("\nDerivada da funcao == 0\n");
}
	printf("\n erro = %.10lf\n",erro);
   	printf("\nRAIZ: %.10f\n", x0);
    printf("\nINTERACAO: %d\n", i);
    printf("\nf(%f) = %.10f\n", x0, f(x0));
	return 0;
}

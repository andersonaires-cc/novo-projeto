// Algoritmo da  Falsa Posição //

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

 
double func(double z){
	double h;
	h=(pow(z,2)-2);  // função //
	return h;
}

int main(){
	
	double a=0,b=0,c=0,m=0;
	int cont=0;
	double x;
	double e=0.0001,e2=0.001; // tolerancia//
	
	printf("Funcao x^3+x^2-x\n");

	printf("\nEntre com o intervalo [a,b]\n\n");
	
	printf("Entre com o valor a ");
	scanf("%lf",&a);
	printf("\n");
	printf("Entre com o valor b ");
	scanf("%lf",&b);
	printf("\n");
	
	
	m=(a*func(b)-b*func(a))/(func(b)-func(a));
	c=a-m;	
	printf("\nPonto medio %lf\n",func(m));
	printf("\nErro %lf\n",fabs(c));
	
	printf("\nf(a)= %lf\n", func(a));
	printf("\nf(b)= %lf\n", func(b));
	printf("\nf(a)*f(b)= %lf\n", func(a)*func(b));
	
if(func(a)*func(b) < 0){ // verifica se no intervalo contém pelo menos uma raiz //
	printf("\nk=%d a=%.10lf f(a)=%.10lf b=%.10lf f(b)=%.10lf Ponto medio(%.10lf) funcao(%.10lf)=%.10lf \n",cont,a,func(a),b,func(b),m,m,func(m));
	while( fabs(c) > e){ // critério de parada quando o erro absoluto for menor que a tolerancia //

		if(func(a)*func(m) < 0){
			b=m;
		}
		if(func(a)*func(m) > 0){
			a=m;
		}
		
		m=(a*func(b)-b*func(a))/(func(b)-func(a));
		c=a-m;
		
	
		cont++;
		printf("\nk=%d a=%.10lf f(a)=%.10lf b=%.10lf f(b)=%.10lf Ponto medio = %.10lf funcao(%.10lf)=%.10lf erro = %.10lf\n",cont,a,func(a),b,func(b),m,m,func(m),fabs(c));
	}
	printf("\nRaiz aproximada de x= %.10lf\n", m);

}if(func(a)*func(b) > 0){
	printf("\nIntervalo nao aplicavel\n");
}if(func(a)*func(b) == 0){
	if(func(a)==0){
		printf("\n F(a) = %.1lf raiz \n", func(a));
	}if(func(b)==0){
		printf("\n F(b) = %.1lf raiz \n", func(b));
	}
}
	printf("\nRAIZ: %.10f\n", m);
    printf("\nINTERACAO: %d\n", cont);
    printf("\nf(%f) = %.10f\n", m, func(m));
	return 0;
}

#include <stdio.h>
#include <math.h>

int main(void){
	int f = 0;//Чтобы зациклить выполнение программы
	double h = 0;//Для сравнение с e(штука что проверяет зацыкленость на лям)
	while(f++ < 1000000){ 

		double e = 0.0000001; 

		//fib values
		double fn[2] = {1,2};//устанавливаем значения fib. на 4 проход(по варианту)	
		double answer = 0;

		//fakt
		double answerfak = 1 * 2;

		//kvad
		double kv = 4 * 4;
		double i = 3;
		do{
			//fib		
			answer = fn[0] + fn[1];
			fn[0] = fn[1];
			fn[1] = answer;

			//fak
			answerfak = answerfak * i;	

			//kvad
			kv = kv * 4;

			h = (answer * kv * sqrt(i++)) / answerfak;
		}while (h > e);
	}
}

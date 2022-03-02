#include <stdio.h>

void order(double *sm, double *bg)
	{
		double Numbers;

		if (*sm > *bg)
		{
			Numbers = *sm;
			*sm = *bg;
			*bg = Numbers;
		}


	}


int main(int argc, char const *argv[])
{
	double number1, number2, number3;

printf("Enter your first number:");
	scanf("%lf", &number1);

printf("Enter your second number:");
	scanf("%lf", &number2);

printf("Enter yout third number:");
	scanf("%lf", &number3);

order (&number1, &number2);
order (&number1, &number3);
order (&number2, &number3);

printf("Your numbers in accending order are: %0.2lf %0.2lf %0.2lf\n", number1, number2, number3);

return 0;
}
 
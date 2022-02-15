#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
int age, RHR;
char gender, fitness;
double INTEN, MHR, THR;
  
printf ("Enter your age\n "); 
	scanf ("%d", &age); 
printf ("Enter your resting heart\n"); 
	scanf ("%d", &RHR);
printf ("Enter your gender: 'm' for male and 'f' for female: \n");
	scanf ("%c", &gender);
  
getchar ();
printf ("Enter your fitness level: low 'l', medium is 'm', or high is 'h': \n"); 
	scanf ("%c", &fitness);
  
getchar ();
switch (gender)
    {
	case 'M':
	case 'm':
MHR = 203.7 / (1 + exp (0.033 * (age - 104.3)));     
break;   
	case 'F':   
	case 'f':
MHR = 190.2 / (1 + exp (0.0453 * (age - 107.5)));   
break;   
}
 
switch (fitness)
    {
	case 'L':   
	case 'l': 
INTEN = 0.55;     
break;
	case 'M': 
	case 'm':
INTEN = 0.65;  
break;  
	case 'H':   
	case 'h':
INTEN = 0.80;     
break;
}
THR = (MHR - RHR) * INTEN + RHR;
printf ("Your training heart rate is %f ", THR);
return (0);
}

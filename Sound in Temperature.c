#include <stdio.h>
#include <math.h>

 double 
spsound (double Xa) 
{
double spsound;
spsound = 1086 * sqrt ((5 * Xa) / 247);
return (spsound);

}

double 
tempfar (double Xa) 
{
double tempfar;
tempfar = (Xa * (9 / 5)) + 32;
return (tempfar);
}

int main(int argc, char const *argv[])
{
double tcel, variable, tfar, finans;
printf ("Enter the temperatre in degrees celsius: ");
scanf ("%lf", &tcel);
tfar = tempfar (tcel);
variable = spsound (tfar);
finans = variable * 1.09728;
printf 
    ("The speed of sound through %0.2lf degrees celcius environment is approximately %0.2lf km/hr",
tcel, finans);
return 0;
}



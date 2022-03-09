/******************************/
/*       Sarim Shahwar        */
/******************************/

#include <stdio.h>

void
Moon (double Plan1, double *a, double *b) 
{
    double minimumDis, maximumDis;
    minimumDis = 363104;
    *a = minimumDis / Plan1; 
    maximumDis = 405696;
    *b = maximumDis / Plan1; 
}
void
Mars (double Plan2, double *c, double *d)
{
    double minimumDis, maximumDis;
        minimumDis = 54600000;
    *c = minimumDis / Plan2; 
        maximumDis = 401000000;
    *d = maximumDis / Plan2; 
}
void
Venus (double Plan3, double *e, double *f)
{
    double minimumDis, maximumDis;
        minimumDis = 38000000;
    *e = minimumDis / Plan3; 
        maximumDis = 261000000;
    *f = maximumDis / Plan3; 
}

int main(int argc, char const *argv[])

{
    int option;
    double Plan1, Plan2, Plan3, a, b, c, d, e, f;
printf("\nWelcome to the prorgam. This program calculates the time it takes to travel to certain planets!");
    printf ("\nEnter '1' to go to the moon: \nEnter '2' to go to the mars: \nEnter '3' to go to the venus: \nEnter '4' to exit the program: \n"); 
        scanf ("%d", &option);

    if (option == 1)
    {
        printf ("Enter the traveling speed in km/h: ");
            scanf ("%lf", &Plan1);
        Moon (Plan1, &a, &b);
            printf ("The maximum time will be %0.2lf hours \nand the minimum time will be %0.2lf hours", b, a);
    }

    else if (option == 2)
    {
        printf ("Enter the traveling speed in km/h: ");
            scanf ("%lf", &Plan2);
        Mars (Plan2, &c, &d);
            printf ("The maximum time will be %0.2lf hours \nand the minimum time will be %0.2lf hours", d, c);
    }

    else if (option == 3)
    {
        printf ("Enter the traveling speed in km/h: ");
            scanf ("%lf", &Plan3);
        Venus (Plan3, &e, &f);
            printf ("The maximum time will be %0.2lf hours \nand the minimum time will be %0.2lf hours", f, e);
    }

    else if (option == 4)
    {
        printf ("\nYou have exited the program");
    }

return (0);
}
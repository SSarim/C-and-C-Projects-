#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
float bmi, weight, height;
printf("Enter your wieght in kilograms: ");
    scanf("%f", &weight);
printf("Enter your height in meters: ");
    scanf("%f", &height);
bmi = (weight) / (height * height);
printf("Your BMI value is %.1f, and you are ", bmi);
    if ( bmi < 18.5) {
printf("Underweight");
}
    else if ( bmi >= 18.5 && bmi <= 24.9 ) {
printf("Normal");
}
    else if ( bmi >= 25 && bmi <= 29.9 ) {
printf("Overweight");
}
    else if (bmi >= 30){
printf("Obese");
}
    else {
printf("Wrong entry\n");
}
return (0);
}

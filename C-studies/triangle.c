#include <stdio.h>
#include <math.h>

int main() {
    double a;
    double b;
    double hyp;

    printf("Enter the measure of the side A in centimeters: ");
    scanf("%lf", &a);

    printf("\nEnter the measure of the side B in centimeters: ");
    scanf("%lf", &b);

    hyp = sqrt(pow(a, 2) + pow(b, 2));

    if (hyp - (int) hyp != 0) {
        printf("The measure of the Hypotenusa is %.2lf centimeters", hyp);
    }
    
    else {
        printf("The measure of the Hypotenusa is %d centimeters", (int) hyp);
    }
    
    return 0;
}
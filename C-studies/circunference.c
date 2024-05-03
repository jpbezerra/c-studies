#include <stdio.h>
#include <math.h>

int main() {
    const double PI = 3.14;
    double radius;

    printf("What is the radius (in centimeters) of the circle? ");
    
    scanf("%lf", &radius);

    double circunference = 2 * PI * radius;
    double area = PI * pow(radius, 2);

    printf("\nThe circunference of the circle is: %.2lf centimeters", circunference);
    printf("\nThe area of the circle is: %.2lf centimeters", area);

    return 0;
}
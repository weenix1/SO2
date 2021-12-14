/*
  Program: integrals.c
  Course:  SOL1 WS2020
  Excerise: 1,lab4
  Author: Eberechukwu Faustina Nwaobiora, Muhammad Asad
  Date:  06.01.2021
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

 /*
  excerise 1a
  f(x) for the rectangle
  which is the height of the rectangle
  */
double f(double x) {
	return cos(M_PI * x);
}
//excerise 1a
double area(double left_x, double right_x) {
	double x;
	x = (left_x + right_x) / 2;//the middle point
	double width = right_x - left_x;//width of the rectangle
	double area = width * f(x);//area of rectangle = length * width
	return area;// return the area
}
//excerise 1b
double integral(double left_x, double right_x, int steps) {
	//declaring local variables
	double sum = 0;
	double x1, x2;
	//obtaning the width of the rectangle
	double width = (right_x - left_x) / steps;
	//using a for loop to get the sum of the area of the rectangle
	for (int i = 0; i < steps; i++) {
		x1 = left_x + width * i;//value of left_x at each loop
		x2 = width + x1;//value of right_x at each loop
		//we call the area to calculate area of each rectangle
		//then add it to the sum for each loop
		sum += area(x1, x2);
	}
	//return the sum of all area of the rectangle
	return sum;
}


int main() {
	//assigning the area function call to result to store the value returned
	double result = area(-0.5, 0.5);
	//displaying the value of area returned 
	printf("%lf\n", result);
	//assigning the integral function call to ans to store the value returned
	double ans = integral(-0.5, 0.5, 10);
	//displaying the value of integral returned 
	printf("%lf\n", ans);
}
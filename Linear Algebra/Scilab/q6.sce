clear;clc;
n=3
A=[1 1;1 -1;-2 4];
disp('The given matrix ')
disp(A,'A=');
b=[1;2;4];
disp('The given matrix ')
disp(b,'b=');
x = (A'*A)\(A'*b);
disp(x, 'x=');
C = x(1,1);
D = x(2,1);
disp('The line of best fit is b=C + Dt');
disp(C, 'C=');
disp(D, 'D=');


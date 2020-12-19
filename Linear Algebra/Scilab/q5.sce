clear;clc;
n=3
A=[1 1 -1; 0 2 -3; 1 -1 2];
disp('The given matrix is ')
disp(A,'A=');
[m,n]=size(A);
disp(m,'m=');
disp(n,'n=');
[v,pivot]=rref(A);
disp(rref(A));
disp(v);
r=length(pivot);
disp(r,'rank=')
cs=A(:,pivot);
disp(cs,'Column Space = ');
ns=kernel(A);
disp(ns,'Null Space = ');
rs=v(1:r,:)';
disp(rs,'Row Space = ')
lns=kernel(A');
disp(lns,'Left Null Space = ');

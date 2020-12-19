/*
LU Decomposition of a matrix
Find the triangular factors L and U for the matrix 
A = 2  -3   3
    1   6   9
    6   3   6
*/
//disp('LU Decomposition of a matrix')
//disp('Find the triangular factors L and U for the matrix ')
//num=input("Enter n value ")
/*
disp("Enter elements for matrix A")
for i=1:num
    for j=1:num
        A(i,j)=input("Enter element ")
    end
end
*/
disp('LU Decomposition')
A=[1 1 2; 3 2 5; 4 7 3]
num = 3
U=A;
disp('Matrix A')
disp(A)
m=det (U ( 1,1) );
n=det (U (2,1) );
a=n/m;
U(2,:)=U(2,:)-U(1,:)/(m/n)
n=det(U(3,1));
b=n/m;
U(3,:)=U(3,:)-U(1,:)/(m/n)
m=det(U(2,2));
n=det(U(3,2));
c=n/m;
L=[1 ,0 ,0; a ,1 ,0; b ,c ,1]
disp(L,'Lower triangular matrix L')
U(3,:)=U(3,:)-U(2,:)/(m/n)
disp(U,'Upper triangular matrix U')


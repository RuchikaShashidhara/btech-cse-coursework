clc;clear
// Inverse of a matrix
//A = [1 0 0;1 1 1;0 0 1];
//n = length(A(1,:));
/*
n=input("Enter n value ")

disp("Enter elements for matrix A")
for i=1:n
    for j=1:n
        A(i,j)=input("Enter element ")
    end
end
*/
n=3
A = [2 4 1;-1 1 -1;1 4 0];
disp(A, "Matrix A : ")
Aug = [A,eye(n,n)];
for j=1:n-1
    for i=j+1:n
        Aug(i,j:2*n) = Aug(i,j:2*n)-Aug(i,j)/Aug(j,j)*Aug(j,j:2*n);
    end
end
for j=n:-1:2
    Aug(1:j-1,:)=Aug(1:j-1,:)-Aug(1:j-1,j)/Aug(j,j)*Aug(j,:);
end
for j=1:n
    Aug(j,:)=Aug(j,:)/Aug(j,j);
end
B=Aug(:,n+1:2*n);
disp(B,"Inverse of A is ");

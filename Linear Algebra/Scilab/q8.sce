clc; clear;
A = [1,6,1;1,2,0;6,3,5];
disp(A,"The matrix A")
lam = poly(0,'lam');
lam = lam;
charMat = A-lam*eye(3,3);
disp(charMat,"The characteristic matrix is:");
charPoly = poly(A,'lam');
disp(charPoly,'The characteristic ploynomial is');
lam =spec(A)
disp(lam,'The eigen values of A are')
function[x,lam]=eigenvectors(A)
    [n,m]=size(A);
    lam=spec(A)';
    x=[];
    for k=1:3
        B=A-lam(k)*eye(3,3);
        C=B(1:n-1,1:n-1);
        b=-B(1:n-1,n);
        y=C\b;
        y=[y;1];
        y=y/norm(y);
        x=[x y]; 
    end
endfunction
get('eigenvectors')
[x,lam]= eigenvectors(A)
disp(x,'The eigen vectors of A are');

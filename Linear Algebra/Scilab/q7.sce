clear;clc;
A = [1 1 -2; 1 -1 4; 1 2 7]
disp(A,'A = ');
[m,n] = size(A);
for k=1:n
    V(:,k) = A(:,k);
    for j=1:k-1
        R(j,k) = V(:,j)'*A(:,k);
        V(:,k) = V(:,k) - R(j,k)*V(:,j);
    end
    R(k,k) = norm(V(:,k));
    V(:,k) = V(:,k)/R(k,k);
end
disp(V,'Q = ');

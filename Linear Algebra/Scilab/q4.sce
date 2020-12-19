clc;clear;
n=3
a=[1 2 3;4 5 6;7 8 9]
//a=[2 1 0 1;-1 0 2 1;3 1 -1 4]
disp('The given matrix is ')
disp(a)
a(2,:)=a(2,:)-(a(2,1)/a(1,1))*a(1,:)
a(3,:)=a(3,:)-(a(3,1)/a(1,1))*a(1,:)
a(3,:)=a(3,:)-(a(3,2)/a(2,2))*a(2,:)
a(1,:)=a(1,:)/a(1,1)
a(2,:)=a(2,:)/a(2,2)
disp('After Gaussian Elimination')
disp(a)
for i=1:n
    for j=i:n
        if(a(i,j)<>0)
            disp('is a pivot element',j,'column')
            break
        end
    end
end

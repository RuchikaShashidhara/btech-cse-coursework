clear; clc;
A = [4 8 3; 9 2 7; 3 1 2]
disp(A,'A = ');
u0 = [0 0 1]';
disp(u0,'The initial vector is');
v = A*u0;
a = max(u0);
disp(A,'First approximation to eigen value is ');
while abs(max(v)-a)>0.002
    disp(v,'current eigen vector is');
    a = max(v);
    disp(a,'Current eigen value is');
    u0 = v/max(v);
    v = A*u0;
end
format('v',4);
disp(max(v),'The largest eigen value is: ');
format('v',5);
disp(u0,'The corresponding eigen vector is: ');

function [ v, f, n, L, M, VV, CotWeight,Laplace_Matrix,L_unweight,b_E,e2v] = cotlp( filename,K)
%UNTITLED �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
if nargin==1
    K=3;
end
[v, f, n, II, JJ, SS, AA, vv, cotweight,a,b,c,d] = meshlp(filename,K);
if nargout==1
v = v';
else
    v=v';
n = n';
W=sparse(II, JJ, SS);
L=W;
A=AA;
Atmp = sparse(1:length(A),1:length(A),1./A);
M=sparse(1:length(A),1:length(A),A);
%L = sparse(diag(1./ A)) * W;
% L = Atmp * W;
VV=vv;
CotWeight=cotweight';

end


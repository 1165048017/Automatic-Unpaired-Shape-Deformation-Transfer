function [ meanv, radius ] = vermean( v )
%MEAN �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
[dim,vnum] = size(v);
meanv = mean(v,2);
vnew = v-repmat(meanv,1,vnum);
radius = max(sqrt(sum(vnew.*vnew,1)));
end


function [ vout ] = scalevwithmean( vin,meanv, radius )
%SCALEV �˴���ʾ�йش˺�����ժҪ
%   �˴���ʾ��ϸ˵��
%[ meanv, radius ] = vermean( vin );
if size(meanv,1) == size(vin,1)
[dim,vnum] = size(vin);
vout = vin - repmat(meanv,1,vnum);    
else
[vnum,dim] = size(vin);
vout = vin - repmat(meanv',vnum,1);    
end
vout = vout/(2*radius);
end


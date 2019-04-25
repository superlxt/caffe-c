clc
close all
clearvars

file_path = 'G:\xueguanxin\0710\940-30ms\roi\';
p = dir([file_path,'*.bmp']);
for idx_img = 1:numel(p)
    name = strcat(file_path,p(idx_img).name);
    img = imread(name);
%     img = img/255;
   % img = imresize(img,[150,200]);%…Ë÷√Õº∆¨¥Û–°; 
%     imwrite(img,'1.tiff');
%
    imwrite(img,['G:\xueguanxin\train\',num2str(idx_img+250),'.png']);
end

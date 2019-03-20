clear;
clc;
%输出原图
I = imread('E:\\1.jpg');
J = im2double(I); %增强
%imshow(J);
%title('原始图像1');
%拉普拉斯
h = [-1,-1,-1;-1,8,-1;-1,-1,-1]; %拉普拉斯算子
J1 = imfilter(J,h); %滤波
%imshow(J1);
%title('拉普拉斯操作后图像2');
%原图和图2相加得到锐化后的图像
J2 = imadd(J,J1);
%imshow(J2);
%title('锐化后的图像');
%Sobel梯度操作
hx = [-1,-2,-1;0,0,0;1,2,1]; %生产sobel垂直梯度模板
hy = [-1,0,1;-2,0,2;-1,0,1]; %生产sobel水平梯度模板
gradx = filter2(hx,J,'same');
gradx = abs(gradx); %计算图像的sobel垂直梯度
grady = filter2(hy,J,'same');
grady = abs(grady); %计算图像的sobel水平梯度
J3 = gradx + grady;
%imshow(J3,[]);
%title('sobel梯度处理后的图像4');

%5*5均值滤波器
h1 = fspecial('average',5);
J4 = imfilter(J3,h1);
%imshow(J4,[]);
%title('平滑后的sobel图像5');

%将拉普拉斯图像与平滑后的梯度图像进行点乘
J5 = J2.*J4;
%imshow(J5);
%title('图3*图5');
%图6与原图相加得到锐化图像
J6 = J + J5;
%imshow(J6);
%title('图6*原图得锐化图像');
%幂率变换
gamma = 0.5;
c = 1;
J7 = c.*J6.^gamma;
imshow(J7,[]);
title('幂率变换');

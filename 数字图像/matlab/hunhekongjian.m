clear;
clc;
%���ԭͼ
I = imread('E:\\1.jpg');
J = im2double(I); %��ǿ
%imshow(J);
%title('ԭʼͼ��1');
%������˹
h = [-1,-1,-1;-1,8,-1;-1,-1,-1]; %������˹����
J1 = imfilter(J,h); %�˲�
%imshow(J1);
%title('������˹������ͼ��2');
%ԭͼ��ͼ2��ӵõ��񻯺��ͼ��
J2 = imadd(J,J1);
%imshow(J2);
%title('�񻯺��ͼ��');
%Sobel�ݶȲ���
hx = [-1,-2,-1;0,0,0;1,2,1]; %����sobel��ֱ�ݶ�ģ��
hy = [-1,0,1;-2,0,2;-1,0,1]; %����sobelˮƽ�ݶ�ģ��
gradx = filter2(hx,J,'same');
gradx = abs(gradx); %����ͼ���sobel��ֱ�ݶ�
grady = filter2(hy,J,'same');
grady = abs(grady); %����ͼ���sobelˮƽ�ݶ�
J3 = gradx + grady;
%imshow(J3,[]);
%title('sobel�ݶȴ�����ͼ��4');

%5*5��ֵ�˲���
h1 = fspecial('average',5);
J4 = imfilter(J3,h1);
%imshow(J4,[]);
%title('ƽ�����sobelͼ��5');

%��������˹ͼ����ƽ������ݶ�ͼ����е��
J5 = J2.*J4;
%imshow(J5);
%title('ͼ3*ͼ5');
%ͼ6��ԭͼ��ӵõ���ͼ��
J6 = J + J5;
%imshow(J6);
%title('ͼ6*ԭͼ����ͼ��');
%���ʱ任
gamma = 0.5;
c = 1;
J7 = c.*J6.^gamma;
imshow(J7,[]);
title('���ʱ任');

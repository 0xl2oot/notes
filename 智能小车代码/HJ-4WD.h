/*****************HJ-4WD慧净四驱蓝牙智能小车专用头文件*****************
*  平台：HJ-4WD/HJ-E/HL-1智能小车 + Keil U4 + STC89C52
*  名称：
*  公司：慧净电子科技有限公司
*  淘宝：http://shop37031453.taobao.com       
*  网站：www.hjmcu.com	智能小车专用网站：WWW.HLMCU.COM
*  编写：慧净
*  日期：2008-8-08
*  交流:智能车QQ:1526248688  开发板QQ:398115088
*  晶振:11.0592MHZ
*  说明：免费开源，不提供源代码分析，有问题直接到慧净论坛交流
*  论坛：http://hjdz.haotui.com 
*  免费结缘：5星好评赠送18个资料包，追加评价后再加送20G资料，网上网盘下载
*  视频教程：本小车配套详细视频教程，有需要请到慧净网站免费下载
******************************************************************/
#ifndef _LED_H_
#define _LED_H_


	//定义小车驱动模块输入IO口 
	sbit IN1=P1^0;
	sbit IN2=P1^1;
	sbit IN3=P1^2;
	sbit IN4=P1^3;
	sbit IN5=P1^4;
	sbit IN6=P1^5;
	sbit IN7=P1^6;
	sbit IN8=P1^7;	

	//蜂鸣器接线定义
	sbit BUZZ=P3^2;

	//HJ-4WD小车底盘4路传感器接线定义
	#define Left_1_led        P3_7	 //P3_7接四路寻迹模块接口第一路输出信号即中控板上面标记为OUT1
	#define Left_2_led        P3_6	 //P3_6接四路寻迹模块接口第二路输出信号即中控板上面标记为OUT2	
	#define Right_1_led       P3_5	 //P3_5接四路寻迹模块接口第三路输出信号即中控板上面标记为OUT3
	#define Right_2_led       P3_4	 //P3_4接四路寻迹模块接口第四路输出信号即中控板上面标记为OUT4

	//HJ-4WD小车驱动接线定义
	#define Left_moto_go      {P1_4=1,P1_5=0,P1_6=1,P1_7=0;}    //左边两个电机向前走
	#define Left_moto_back    {P1_4=0,P1_5=1,P1_6=0,P1_7=1;}    //左边两个电机向后转
	#define Left_moto_Stop    {P1_4=0,P1_5=0,P1_6=0,P1_7=0;}    //左边两个电机停转                     
	#define Right_moto_go     {P1_0=1,P1_1=0,P1_2=1,P1_3=0;}	//右边两个电机向前走
	#define Right_moto_back   {P1_0=0,P1_1=1,P1_2=0,P1_3=1;}	//右边两个电机向后走
	#define Right_moto_Stop   {P1_0=0,P1_1=0,P1_2=0,P1_3=0;}	//右边两个电机停转  

//延时函数	
void delay(unsigned int k)
{    
	 unsigned int x,y;
	 for(x=0;x<k;x++) 
	   for(y=0;y<2000;y++);
}
/************************************************************************/
//全速前进函数 如果看不明白，请看慧净电子51智能小车视频教程
void  run(void)
{    
	 IN1=1;	 	 
	 IN2=0;	 
	 IN3=1;	 
	 IN4=0; 
	 IN5=1;	 	 
	 IN6=0;	 
	 IN7=1;	 
	 IN8=0;
	 //P1=0X55;
}
/*********************************************************************/		 
/************************************************************************/
//全速后退函数 如果看不明白，请看慧净电子51智能小车视频教程
void  backrun(void)
{
	 IN1=0;	 	 
	 IN2=1;	 
	 IN3=0;	 
	 IN4=1; 
	 IN5=0;	 	 
	 IN6=1;	 
	 IN7=0;	 
	 IN8=1;
}
/*********************************************************************/	
/************************************************************************/
//全速左转函数 如果看不明白，请看慧净电子51智能小车视频教程
void  leftrun(void)
{
	 IN1=1;	 	 
	 IN2=0;	 
	 IN3=1;	 
	 IN4=0; 
	 IN5=0;	 	 
	 IN6=1;	 
	 IN7=0;	 
	 IN8=1;
}
/*********************************************************************/	
/************************************************************************/
//全速右转函数 如果看不明白，请看慧净电子51智能小车视频教程
void  rightrun(void)
{
	 IN1=0;	 	 
	 IN2=1;	 
	 IN3=0;	 
	 IN4=1; 
	 IN5=1;	 	 
	 IN6=0;	 
	 IN7=1;	 
	 IN8=0;
}
/*********************************************************************/	
/************************************************************************/
//电机停止转动函数 如果看不明白，请看慧净电子51智能小车视频教程
void  stop(void)
{
	 IN1=0;	 	 
	 IN2=0;	 
	 IN3=0;	 
	 IN4=0; 
	 IN5=0;	 	 
	 IN6=0;	 
	 IN7=0;	 
	 IN8=0;
	 //P1=0X00;
}
/*********************************************************************/	

#endif
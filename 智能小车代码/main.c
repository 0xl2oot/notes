/*****************HJ-4WD慧净四驱蓝牙智能小车例程*****************
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
	//注意程序只做参考之用，要达到最理想的效果，还需要同学们细心调试。
//控制板跳线帽接法 
//J6-1 P1.0至P1.7 IO口处跳线帽全部接上 	 
//J6-2 驱动使能EN1 NE2 EN3 NE4全部接线。
//J6-3 PWM控制全部不接跳线帽
#include <AT89X52.H>		  //包含51单片机头文件，内部有各种寄存器定义
#include <HJ-4WD_PWM.H>		  //包含HJ-4WD蓝牙智能小车驱动IO口定义等函数
    
//主函数
void main(void)
{	
		 
	unsigned char i;
    P1=0X00;	  //小车停止

	TMOD=0X01;
    TH0= 0XFc;		  //1ms定时
    TL0= 0X18;
    TR0= 1;
    ET0= 1;
	EA = 1;


	while(1)	//无限循环
	{ 
	 
			 //有信号为0  没有信号为1
			  //传感器定义 R是右(right),L是左(left)	  小车对着自己看时 分的左右
		if(Left_B_led==1&&Right_B_led==1)	 //前面无物体时
		{



					  			//有信号为0  没有信号为1

              if(Left_X_led==0&&Right_X_led==0)	 //白线

			  run();

			  else
			 {			  
				               if(Left_X_led==0&&Right_X_led==1)	    //左边检测到红外
			 	 {
			
				 Left_moto_go;						   //左边两个电机正转
				 Right_moto_Stop;
				 
			     }
			   
				 			    if(Right_X_led==0&&Left_X_led==1)		//右边检测到红外
				  {	  
		
			      Right_moto_go;					   //右边两个电机正转

				  Left_moto_Stop;
				  }
			}	 





			  }
			 


			  else
			 {			  
				               if(Left_B_led==0&&Right_B_led==1)	    //左边检测到红外
			 	 {
			
				 Left_moto_go;						   //左边两个电机正转
				 Right_moto_Stop;
				 
			     }
			   
				 			    if(Right_B_led==0&&Left_B_led==1)		//右边检测到红外
				  {	  
		
			      Right_moto_go;					   //右边两个电机正转

				  Left_moto_Stop;
				  }
			}
			
	 }
}
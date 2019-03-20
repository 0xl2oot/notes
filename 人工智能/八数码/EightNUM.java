package shiyan;
import javax.swing.JOptionPane;
import java.util.Random;
import java.util.Vector;
import java.util.Date;
import java.util.Calendar;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class EightNUM implements ActionListener,ItemListener
{
    private class MyPanel extends JPanel //画图
    {
    	private String[][] goles=new String[][]{{"1","2","3"},{"8"," ","4"},{"7","6","5"}};
    	public void paintComponent(Graphics g)
    	{
    		super.paintComponent(g);
    		g.setColor(Color.white);
    		g.fillRect(0, 0, this.getWidth(), this.getHeight());
    		g.setColor(Color.black);
    		for(int i=0;i<4;i++)
    		{
    			g.drawLine(30, i*50+30, 180, i*50+30);
    			g.drawLine(i*50+30, 30, i*50+30, 180);
    			g.drawLine(300, i*50+30, 450, i*50+30);
    			g.drawLine(i*50+300, 30, i*50+300, 180);
    		}
    		   for(int i=0;i<3;i++)
    			   for(int j=0;j<3;j++)
    			   {
    				   if(a1[i][j]==0)
    					   g.drawString(" ",50+j*50, 60+i*50);
    				   else
    				      g.drawString(String.valueOf(a1[i][j]),50+j*50,60+i*50);
    			   }
    		for(int i=0;i<3;i++)
    			for(int j=0;j<3;j++)
    			{
    				g.drawString(goles[i][j],320+j*50,60+i*50);
    			}
    	}
    }
    private class MyThread implements Runnable//线程控制
    {
    	boolean canrun=true;
    	Thread th=new Thread(this);
    	int p=getWay.size()-1;
    	public void run()
    	{
    		while(this.canrun)
    		{
    		     try
    		     {
    			     th.sleep(1000);
    		     }
    		     catch(Exception e){}
    		     ArrayState me=(ArrayState)getWay.get(p);
    		     p--;
    		     a1=me.a;
    		     if(isgole(a1))
    		     {
    		    	 this.canrun=false;
    		    	 bn.setEnabled(true);
    		    	 ways.setEnabled(true);
    			     mp.repaint();
    			     break;
    		     }
    		     else 
    		     {
    			     mp.repaint();
    		     }
    		}
    	}
    }
    private class ArrayState//记录状态
    {
    	int[][] a=new int[3][3];
    	int x=0,y=0,l=0,d=0,label=0;
    	ArrayState father=null;
    	private void Arraycopy(int[][] copya)
        {
        	for(int i=0;i<3;i++)
        		for(int j=0;j<3;j++)
        			this.a[i][j]=copya[i][j];
        }
    	public ArrayState(int[][] a,int x,int y,int l,int label,int d)
    	{
    		Arraycopy(a);
    		this.x=x;
    		this.y=y;
    		this.l=l;
    		this.label=label;
    		this.d=d;
    	}
    }
    private class winClose extends WindowAdapter
    {
    	public void windowClosing(WindowEvent e)
    	{
    		fff=true;
    		jilumf.dispose();
    	}
    }
    private JFrame mf=null,jilumf=null;
    private JTextArea panel00=null;
    private JComboBox ways=null;
    private int[][] a1=new int[3][3];
    private ArrayState copya1=null;
    private int[][] goless=new int[][]{{1,2,3},{8,0,4},{7,6,5}};
    private MyPanel mp=null;
    private Container con=null;
    private JButton bn=null;
    private JLabel ml=null;
    private int x=0,y=0,label=0,yy=0;
    private Vector vec=null,closeV=null,getWay=null,midV=null;
    private boolean firstrun=false,runb=true,canjilu=true,fff=true,lll=true;
    private  MyThread ob=null;
    private Thread me=null;
    public EightNUM()
    {
    	vec=new Vector();
    	closeV=new Vector();
    	getWay=new Vector();
    	midV=new Vector();
    	mf=new JFrame(" 八数码 ");
    	panel00=new JTextArea();
    	mp=new MyPanel();
    	mp.setSize(500, 220);
    	mp.setLocation(0, 0);
    	con=mf.getContentPane();
    	con.setLayout(null);
    	bn=new JButton("初始");
    	bn.addActionListener(this);
    	bn.setLocation(65, 240);
    	bn.setSize(80, 40);
    	ml=new JLabel("目标");
    	ml.setBounds(360, 240, 100, 40);
    	ways=new JComboBox(new String[]{"深度优先","宽度优先","深宽结合","运行记录"});
    	ways.setMaximumRowCount(4);
    	ways.addItemListener(this);
    	ways.setBounds(210, 240, 80, 40);
    	con.add(bn);
    	con.add(ml);
    	con.add(mp);
    	con.add(ways);
    	mf.setBounds(50, 50, 500, 350);
    	mf.setVisible(true);
    	mf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    	initArray();
		mp.repaint();
    }
    public void initArray()//初始化数组a1
    {
    	int[] a=new int[9];
    	Random rn=new Random();
    	a[0]=rn.nextInt(9);
    	int i=0,j=0;
    	for(i=1;i<9;i++)
    	{
    		a[i]=rn.nextInt(9);
    		for(j=0;j<i;j++)
    		{
    			if(a[j]==a[i])
    			{
    				i--;
    				break;
    			}
    		}
    	}
    	for(i=0;i<3;i++)
    		for(j=0;j<3;j++)
    		{
    			a1[i][j]=a[i*3+j];
    			if(a1[i][j]==0)
    			{
    				x=i;
    				y=j;
    			}
    		}
    }
    public boolean isgole(int[][] a1)//判断当前数组是否为目标
    {
    	for(int i=0;i<3;i++)
    		for(int j=0;j<3;j++)
    		{
    			if(a1[i][j]!=goless[i][j])
    				return false;
    		}
    	return true;
    }
    public int nearA(int v,int x,int y)//计算当前数组到达目标数组所差距离
    {
    	for(int i=0;i<3;i++)
    		for(int j=0;j<3;j++)
    		{
    			if(v==goless[i][j])
    				return Math.abs(x-i)+Math.abs(y-j);
    		}
    	return 0;
    }
    public int nearDeg(int[][] a)//计算当前数组到达目标数组所差距离
    {
    	int l=0;
    	for(int i=0;i<3;i++)
    		for(int j=0;j<3;j++)
    		{
    			if(a[i][j]!=goless[i][j]&&a[i][j]!=0)
    				l+=nearA(a[i][j],i,j);
    		}
    	return l;
    }
    public void getMin()
    {
    	ArrayState mystate=null,nextstate=null;
    	mystate=(ArrayState)closeV.get(0);
		for(int j=1;j<closeV.size();j++)
		{
			nextstate=(ArrayState)closeV.get(j);
			if(mystate.l<nextstate.l)
			{
				midV.add(nextstate);
				closeV.remove(j);
				j--;
			}
		}
    }
    public void sort()//根据当前数组到目标数组的距离排序,结果放到closeV
    {
    	ArrayState mystate=null,nextstate=null;
    	for(int i=0;i<closeV.size()-1;i++)
    	{
    		mystate=(ArrayState)closeV.get(i);
    		for(int j=i+1;j<closeV.size();j++)
    		{
    			nextstate=(ArrayState)closeV.get(j);
    			if(mystate.l>nextstate.l)
    			{
    				closeV.set(i, nextstate);
    				closeV.set(j, mystate);
    				mystate=nextstate;
    			}
    		}
    	}
    }
    public void Arraycopy(int[][] copya,int[][] a1)//数组复制
    {
    	for(int i=0;i<3;i++)
    		for(int j=0;j<3;j++)
    			copya[i][j]=a1[i][j];
    }
    public ArrayState Wfirst()
    {
    	ArrayState amy=null;
    	int[][] acopy=null;
    	int l=0;
    	closeV.add(vec.get(0));
    	while(true)
    	{
    	   amy=(ArrayState)closeV.get(0);
    	   acopy=amy.a;
 		   if(this.isgole(acopy))
 			 return amy;
 		   this.NUMstart(acopy, amy);
 		   this.sort();
 		   closeV.remove(0);
    	   l++;
     	   if(l==1000000)
     		   break;
    	}
    	return null;
    }
    public ArrayState WDFirst()
    {
    	ArrayState amy=null;
    	int[][] acopy=null;
    	long l=0;
    	while(true)
    	{
    		while(true)
    		{
    			yy=0;
    			for(int i=0;i<vec.size();i++)
    			{
    				amy=(ArrayState)vec.get(i);
    				acopy=amy.a;
    				if(this.isgole(acopy))
    					return amy;
    				if(amy.d<50)
    					this.NUMstart(acopy, amy);
    			}
    			if(amy.d>=50)
    			{
    				yy=1;
    				break;
    			}
    			this.sort();
    			this.getMin();
    			vec.removeAllElements();
    			for(int i=0;i<closeV.size();i++)
    				vec.add(closeV.get(i));
    			closeV.removeAllElements();
    			l++;
    		}
    		  for(int v=0;v<vec.size();v++)
    			  midV.add(vec.get(v));
  			  vec.removeAllElements();
  			  closeV.removeAllElements();
  			  for(int m=0;m<midV.size();m++)
  			  {
  				  closeV.add(midV.get(m));
  			  }
  			  midV.removeAllElements();
  			  this.sort();
  	    	  this.getMin();
  	    	  for(int i1=0;i1<closeV.size();i1++)
  	    		   vec.add(closeV.get(i1));
  	    	   closeV.removeAllElements();
    		if(l==100000L)
    			break;
    	}
    	return null;
    }
    public ArrayState extendArray()//数组扩展
    {
    	ArrayState amy=null;
    	int[][] acopy=null;
    	long l=0;
    	while(true)
    	{
    	   for(int i=0;i<vec.size();i++)
    	   {
    		  amy=(ArrayState)vec.get(i);
    		  acopy=amy.a;
    		  if(this.isgole(acopy))
    			return amy;
    		  this.NUMstart(acopy, amy);
    	   }
    	   this.sort();
    	   this.getMin();
    	   vec.removeAllElements();
    	   for(int i=0;i<closeV.size();i++)
    		   vec.add(closeV.get(i));
    	   closeV.removeAllElements();
    	   l++;
    	   if(l==100000L)
    		   break;
    	}
    	return null;
    }
    public void NUMstart(int[][] a1,ArrayState ob)//当前状态扩展后可的的状态
    {
    	int a=0;
    	int[][] copya=new int[3][3];
    	int x1=0,y1=0;
    	ArrayState ob1=null;
    	x=ob.x;
    	y=ob.y;
    	label=ob.label;
    	if(((x-1)>=0)&&label!=2)
    	{			
    		this.Arraycopy(copya,a1);
    		copya[x][y]=a1[x-1][y];
    		copya[x-1][y]=0;
    		  x1=x-1;
    		  y1=y;
    		  a=nearDeg(copya);
    		  if(ways.getSelectedIndex()==1||ways.getSelectedIndex()==2)
    			  a+=(ob.d+1);
    		  ob1=new ArrayState(copya,x1,y1,a,1,ob.d+1);
    		  ob1.father=ob;
    		  closeV.add(ob1);
    	}
        if(((x+1)<=2)&&label!=1)
    	{
        	this.Arraycopy(copya,a1);
    		copya[x][y]=a1[x+1][y];
    		copya[x+1][y]=0;
    		  x1=x+1;
    		  y1=y;
    		  a=nearDeg(copya);
    		  if(ways.getSelectedIndex()==1||ways.getSelectedIndex()==2)
    			  a+=(ob.d+1);
    		  ob1=new ArrayState(copya,x1,y1,a,2,ob.d+1);
    		  ob1.father=ob;
    		  closeV.add(ob1);  		
    	}
        if(((y-1)>=0)&&label!=4)
		{
        	this.Arraycopy(copya,a1);
    		copya[x][y]=a1[x][y-1];
    		copya[x][y-1]=0;
    		  x1=x;
    		  y1=y-1;
    		  a=nearDeg(copya);
    		  if(ways.getSelectedIndex()==1||ways.getSelectedIndex()==2)
    			  a+=(ob.d+1);
    		  ob1=new ArrayState(copya,x1,y1,a,3,ob.d+1);
    		  ob1.father=ob;
    		  closeV.add(ob1);
    		
		}
		if(((y+1)<=2)&&label!=3)
		{
			this.Arraycopy(copya,a1);
    		copya[x][y]=a1[x][y+1];
    		copya[x][y+1]=0;
    		  x1=x;
    		  y1=y+1;
    		  a=nearDeg(copya);
    		  if(ways.getSelectedIndex()==1||ways.getSelectedIndex()==2)
    			  a+=(ob.d+1);
    		  ob1=new ArrayState(copya,x1,y1,a,4,ob.d+1);
    		  ob1.father=ob;
    		  closeV.add(ob1);   		
		}	
    }
    public boolean canreach(int[][] newstate)//根据奇偶性判断当前状态是否可达目标态
    {
    	int[] a=new int[8];
    	int t=0;
    	for(int i=0;i<3;i++)
    		for(int j=0;j<3;j++)
    			if(newstate[i][j]!=0)
    				a[t++]=newstate[i][j];
    	t=0;
    	for(int i=1;i<8;i++)
    	{
    		for(int j=0;j<i;j++)
    			if(a[i]<a[j])
    				t++;
    	}
    	if(t%2!=0)
    		return true;
    	return false;
    }
    public void itemStateChanged(ItemEvent e)
    {
    	int num=ways.getSelectedIndex();
    	if(firstrun==true)
    	{
    	  vec=new Vector();
    	  closeV=new Vector();
    	  getWay=new Vector();
    	  vec.add(copya1);
    	  this.Arraycopy(a1, copya1.a);
    	  x=copya1.x;
    	  y=copya1.y;
    	  label=0;
    	  mp.repaint();
    	  if(num==0&&lll)
    	  {
    		  bn.setText("运行");
    		  runb=false;
    	  }
    	  else if(num==1&&lll)
    	  {
    		  bn.setText("运行");
    		  runb=false;
    	  }
    	  else if(num==2&&lll)
    	  {
    		  bn.setText("运行");
    		  runb=false;
    	  }
    	}
    	if(num==3&&fff==true)
    	{
    		fff=false;
    		jilumf=new JFrame("运行结果分析");
        	Container connn=jilumf.getContentPane();
        	connn.add(new JScrollPane(panel00));
        	jilumf.addWindowListener(new winClose());
        	jilumf.setSize(300,300);
        	jilumf.setVisible(true);
    	}
    }
    public void JiLu(int indexs,long timeb)
    {
    	if(indexs==0)
    	{
    		panel00.append("\n深度优先: "+timeb+"ms");
    	}
    	else if(indexs==1)
    	{
    		panel00.append("\n宽度优先: "+timeb+"ms");
    	}
    	else if(indexs==2)
    	{
    		panel00.append("\n深宽结合: "+timeb+"ms");
    	}
    	panel00.append("\n");
    }
    public void actionPerformed(ActionEvent e)
    {
    	if(bn.getText()=="初始")
    	{
    		lll=true;
    		firstrun=true;
    		initArray();
    		mp.repaint();
    		if(!this.canreach(a1))
    		{
    		    JOptionPane.showMessageDialog(this.mf, "不可到达，请重新初始化");
    		    firstrun=false;
    		}
    		else
    		{
    			ArrayState asta=new ArrayState(a1,x,y,0,label,0);
    			copya1=new ArrayState(a1,x,y,0,label,0);
    			runb=true;
        		asta.father=null;
        		vec.add(asta);
    			bn.setText("运行");
    		}
    	}
    	else if(bn.getText()=="运行")
    	{
    		bn.setText("重置");
    		ArrayState mubiao=null;
    		int isrun=0;
    		isrun=0;
    		Date adate=new Date();
    		long timeb=adate.getTime();
    		switch(ways.getSelectedIndex())
    		{
    		  case 0:mubiao=this.extendArray();timeb=(new Date()).getTime()-timeb;break;
    		  case 1:mubiao=this.Wfirst();timeb=(new Date()).getTime()-timeb;break;
    		  case 2:mubiao=this.WDFirst();timeb=(new Date()).getTime()-timeb;break;
    		  case 3:break;
    		}
    		if(mubiao==null) 
    			{
    			    JOptionPane.showMessageDialog(this.mf, "问题有解，但此法很难到达，请重新初始化");
    			    isrun=1;
    			}
    		while(mubiao!=null)
    		{
    			this.getWay.add(mubiao);
    			mubiao=mubiao.father;
    		}
    		if(isrun!=1)
    		{
    			if(canjilu)
    			{
    				canjilu=false;
    				panel00.append("\n");
    				panel00.append("\n");
    				panel00.append("\n");
    				for(int b1=0;b1<3;b1++)
    				{
    					for(int b2=0;b2<3;b2++)
    					{
    						panel00.append(String.valueOf(a1[b1][b2])+"    ");
    					}
    					panel00.append("\n");
    				}
    				panel00.append("目标：\n");
    				panel00.append("1    2    3  \n");
    				panel00.append("8         4  \n");
    				panel00.append("7    6    5  \n");
    				//开始记录程序
    			}
    		  JiLu(ways.getSelectedIndex(),timeb);
    		  runb=true;
    		  ob=new MyThread();
    		  me=new Thread(ob);
    		  me.start();
    		  bn.setEnabled(false);
    		  ways.setEnabled(false);
    		}
    	}
    	else if(bn.getText()=="重置")
    	{
    		lll=false;
    		canjilu=true;
    		bn.setText("初始");
    		label=0;
    		me=null;
    		firstrun=false;
    		ways.setSelectedIndex(0);
    	}
    }
    public static void main(String[] args)
    {
    	new EightNUM();
    }
}

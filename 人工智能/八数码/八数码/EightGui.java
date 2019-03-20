import java.awt.Button;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
//界面层
public class EightGui extends JFrame
{
	public static void main(String[]args)
	{
		Base test=new Base();
	}
}
class Base extends JFrame  
{
	JFrame J1;
	JPanel left,right,bottom,up;
	//大BUG,java中JButton竟然和Button不一样。Button可以实现按钮文本自动变化
    Button[] button;
	JButton[] tool;
	JLabel label,bfs,dfs,astart,slide,area,b1,b2,b3;
	String route;
	static int position=8;
	Base()
	{
		J1=new JFrame();
		up=new JPanel();
		up.setLayout(null);
		up.setPreferredSize(new Dimension(500,200));
		up.setBounds(0, 420, 500,200);
		label=new JLabel("路线:");
		label.setFont(new Font("宋体", 1, 18)); 
		label.setBounds(20,20,120,20);
		area=new JLabel();
		area.setBounds(20,30,480,60);
		up.add(area);
		b1=new JLabel();b2=new JLabel();b3=new JLabel();
		bfs=new JLabel("广度优先时间");
		bfs.setFont(new Font("宋体", 1, 15)); 
		bfs.setBounds(20,90,120,20);
		b1.setBounds(20,100,120,50);
		dfs=new JLabel("深度优先时间");
		dfs.setFont(new Font("宋体", 1, 15)); 
		dfs.setBounds(150,90,120,20);
		b2.setBounds(150,100,120,50);
		astart=new JLabel("A Star 时间");
		astart.setFont(new Font("宋体", 1, 15)); 
		astart.setBounds(290,90,120,20);
		b3.setBounds(290,100,120,50);
		up.add(label);up.add(bfs);
		up.add(dfs);up.add(astart);
		up.add(b1);up.add(b2);up.add(b3);
		left=new JPanel(new GridLayout(3,3));
		left.setPreferredSize(new Dimension(400,400));
		left.setBounds(20,20,400,400);
		right=new JPanel();
		right.setPreferredSize(new Dimension(100,400));
		right.setLayout(null);
		right.setBounds(450,20,100,400);
		button=new Button[9];
		Opchoice t =new Opchoice();
		for(int i=0;i<9;i++)
		{
			if(i==8)
				button[i]=new Button(" ");
			else
				button[i]=new Button(String.valueOf(i+1));
			left.add(button[i]);
		    button[i].setFont(new Font("TimesRoman",1,40));
		    button[i].setForeground(Color.DARK_GRAY);
		    button[i].setFocusable(false);
		    button[i].addKeyListener(t);
		}
		tool=new JButton[6];
		int x=10,y=10;
		String[]op=new String[]{"初始化","广度优先","深度优先","A Star","自动移动","退出程序"};
		for(int i=0;i<op.length;i++)
		{
			tool[i]=new JButton(op[i]);
			tool[i].setBounds(x,y+i*60,88,40);
			tool[i].setContentAreaFilled(false); 
			tool[i].setFocusable(false);
			tool[i].addActionListener(t);
			right.add(tool[i]);
		}
		bottom=new JPanel();
		bottom.setLayout(null);
		bottom.add(up);
		bottom.add(left);
		bottom.add(right);
		J1.add(bottom);
		J1.setTitle("八数码问题");
		J1.setSize(620,650);
		J1.setVisible(true);
		Toolkit kit = Toolkit.getDefaultToolkit();  
        Dimension screenSize = kit.getScreenSize();  
        int screenWidth = screenSize.width/3;  
        int screenHeight = screenSize.height/3;  
        int height = J1.getHeight();  
        int width = J1.getWidth();  
        J1.setLocation(screenWidth-width/4, screenHeight-height/4);  
		J1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	int[] getchess()
	{
		int[]start=new int[9];
		
		for(int i=0;i<9;i++)
		{
			if(button[i].getLabel()==" ")
			{
				start[i]=0;
			}
			else
				start[i]=Integer.valueOf(button[i].getLabel());
		}
		return start;
	}
	void move(int pos)
	{
		int x=position/3;
		int y=position%3;
		switch(pos)
		{
			case KeyEvent.VK_UP:
				if(x!=0)
				{
					button[position].setLabel(button[position-3].getLabel());
					button[position-3].setLabel(" ");
					position-=3;
				}
				break;
			case KeyEvent.VK_DOWN:
				if(x!=2)
				{
					button[position].setLabel(button[position+3].getLabel());
					button[position+3].setLabel(" ");
					position+=3;
				}
				break;
			case KeyEvent.VK_LEFT:
				if(y!=0)
				{
					button[position].setLabel(button[position-1].getLabel());
					button[position-1].setLabel(" ");
					position-=1;
				}
			    break;
			case KeyEvent.VK_RIGHT:
				if(y!=2)
				{
					button[position].setLabel(button[position+1].getLabel());
					button[position+1].setLabel(" ");
					position+=1;
				}
		}		
	}
	class Opchoice implements ActionListener,KeyListener
	{
		public void actionPerformed(ActionEvent e)
		{
			
			String event=e.getActionCommand();
			if(event=="初始化")
			{
				int a[]=new int[9];
				do 
				{
					int k=0;
					Random random=new Random();
					Set<Integer>set=new HashSet<Integer>();
					while(set.size()<8)
					{
						int n=random.nextInt(8)+1;
						if(!set.contains(n))
						{
							set.add(n);
							a[k++]=n;
						}
					}
					a[k]=0;
				}while(!EightNumberBfs.solve(a));
				for(int i=0;i<9;i++)
				button[i].setLabel(String.valueOf(a[i]));
				button[8].setLabel(" ");
				position=8;
			}
			else if(event=="广度优先")
			{
				int[]start=getchess();
				long startTime=System.currentTimeMillis();   //获取开始时间         
				int begin=EightNumberBfs.bfs(start);
				String res=EightNumberBfs.outpath(begin);
				route = res;
				area.setText("<html>"+route+"</html>");
				long endTime=System.currentTimeMillis(); //获取结束时间
				long ans=endTime-startTime;
				String time=String.valueOf(ans)+"ms";
				b1.setText(time);
			}
			else if(event=="深度优先")
			{
				int[]start=getchess();
				long startTime=System.currentTimeMillis();   
				String dm=JOptionPane.showInputDialog(null,"请设置搜索深度:\n");
				String res=EightNumberDfs.getans(start,Integer.parseInt(dm));
				route = res;
				area.setText("<html>"+route+"</html>");
				long endTime=System.currentTimeMillis(); 
				long ans=endTime-startTime;
				String time=String.valueOf(ans)+"ms";
				b2.setText(time);
			}
			else if(event=="A Star")
			{
				int[]start=getchess();
				long startTime=System.currentTimeMillis();   
				String res=EightNumberA.getans(start);
				route = res;
				area.setText("<html>"+route+"</html>");
				long endTime=System.currentTimeMillis(); 
				long ans=endTime-startTime;
				String time=String.valueOf(ans)+"ms";
				b3.setText(time);
			}
			else if(event=="自动移动")
			{
				 String ans=route;
				 for(int i=0;i<ans.length();i++)
				 {
					 if(ans.charAt(i)=='\n')
						 break;
					 else
					 {
						 switch(ans.charAt(i)) {  
			                case '上':  
			                    move(KeyEvent.VK_UP);  
			                    break;  
			                case '下':  
			                    move(KeyEvent.VK_DOWN);  
			                    break;  
			                case '左':  
			                    move(KeyEvent.VK_LEFT);  
			                    break;  
			                case '右':  
			                    move(KeyEvent.VK_RIGHT);  
			                    break;  
			                }  
			                try {  
			                    Thread.sleep(500);  
			                } catch (InterruptedException e1) {  
			                    e1.printStackTrace();  
			                }  
					 }
				 }
			}
			else if(event=="退出程序")
			{
				System.exit(0);  
				return;	 
			}
		}
		public void keyPressed(KeyEvent e)
		{
			move(e.getKeyCode());
			if(success())
			{
				JOptionPane.showMessageDialog(J1,"太棒了，你成功啦！");
			}
		}
		public void keyReleased(KeyEvent e) {};
		public void keyTyped(KeyEvent e) {}
	}
	boolean success()
	{
		for(int i=0;i<8;i++)
		{
			if(button[i].getLabel()==" ")
				return false;
			else if(Integer.valueOf(button[i].getLabel())!=i+1)
				return false;
		}
		return true;
	}
}

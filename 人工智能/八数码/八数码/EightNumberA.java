import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
//估计函数，把牌移动到目标位置所需移动的距离的总和
//f(n)=g(n)+h(n),g代表初始节点到当前节点的代价，h代表到目标节点的估计代价
//利用优先队列对节点的f排序
//记录一下:调了一天的BUG,最后问题竟然出现在1.java的对象之间的赋值拷贝,2.java和c++的优先队列返回值不同！！！
class Node	
{
	public int[][]chess=new int[3][3];
	public int h,g;
	public int x,y;//记录空格的位置
	public int codenum;//记录此状态对应的哈希值
	Node(){};
	public void set(int[]a)
	{
		int k=0;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				this.chess[i][j]=a[k++];
				if(chess[i][j]==0)
				{
					this.x=i;
					this.y=j;
				}
			}
		}
//		System.out.println(x+"+"+y);
	}
}

public class EightNumberA {
	static int[]goal= {1,2,3,4,5,6,7,8,0};
	static int goalnum;
	static int[]index= {0,0,1,2,3,4,5,6,7};
	static int max=999999;
	static int[][] dir={{-1,0},{1,0},{0,-1},{0,1}};
	static int[]code={1,1,2,6,24,120,720,5040,40320};
	static boolean[]visit=new boolean[max];
	static String dic="上下左右";//记录走的方向
	static int pre[]=new int[max]; 
	static int path[]=new int[max];
	static String ans;
	static int sum=0;
	public static Comparator<Node> compare = new Comparator<Node>(){
        public int compare(Node a, Node b) {
            return (a.g+a.h)-(b.g+b.h);
        }
    };
    //得到康托展开，计算在全排列中的位置，在visit数组中进行标记
    public static int kangtuo(Node a)
    {
    	int[]temp=new int[9];
    	int k=0;
    	for(int i=0;i<3;i++)
    	{
    		for(int j=0;j<3;j++)
    		{
    			temp[k++]=a.chess[i][j];
    		}
    	}
    	int cnt;
    	int sumHash=0;
    	for(int i=0;i<9;i++)
    	{
    		cnt=0;
    		for(int j=0;j<i;j++)
    		{
    			if(temp[j]>temp[i])
    				cnt++;
    		}
    		sumHash+=cnt*code[i];
    	}
    	return sumHash;
    }
    //定义估计函数(曼哈顿距离)
    public static int costf(Node temp)
    {
    	int cost=0;
    	for(int i=0;i<3;i++)
    	{
    		for(int j=0;j<3;j++)
    		{
    			if(temp.chess[i][j]!=0)
    			{
    				cost+=Math.abs(i-(temp.chess[i][j]-1)/3)+Math.abs(j-(temp.chess[i][j]-1)%3);
    			}
    		}
    	}
    	return cost;
    }
    public static String printpath(int p)
    {
    	StringBuffer respath=new StringBuffer();
		while(p!=-1)
		{
			respath.insert(0,dic.charAt(path[p]));
			p=pre[p];
		}
		return respath.toString();
    }
    //a星算法
    public static void Astart(int[]start)
    {
    	Arrays.fill(visit, false);
    	Node end=new Node();
    	end.set(goal);
    	goalnum=kangtuo(end);
    	Node begin=new Node();
    	begin.set(start);
    	begin.codenum=kangtuo(begin);
    	begin.g=0;begin.h=costf(begin);
    	visit[begin.codenum]=true;
    	pre[begin.codenum]=-1;
    	Queue<Node>q=new PriorityQueue<>(compare);
    	q.add(begin);
    	int xx,yy,k;
    	while(!q.isEmpty())
    	{
    		sum++;
    		Node a=q.poll();
    		String temp="";
    		for(int m=0;m<3;m++)
			{
				for(int n=0;n<3;n++)
					temp+=a.chess[m][n];
			}
//    		System.out.println("取元素"+temp);
    		for(int i=0;i<4;i++)
    		{
    			xx=a.x+dir[i][0];
    			yy=a.y+dir[i][1];
    			if(xx>=0&&xx<3&&yy>=0&&yy<3)
    			{
    				Node op=new Node();
    				for(int m=0;m<3;m++)
    				{
    					for(int n=0;n<3;n++)
    						op.chess[m][n]=a.chess[m][n];
    				}
    				op.chess[a.x][a.y]=a.chess[xx][yy];
    				op.chess[xx][yy]=a.chess[a.x][a.y];
    				k=kangtuo(op);
    				if(!visit[k])
    				{
    					visit[k]=true;
    					op.codenum=k;
    					op.x=xx;
    					op.y=yy;
    					op.g=a.g+1;
    					op.h=costf(op);
    					if(k!=begin.codenum)
    					{
    						pre[k]=a.codenum;
    						path[k]=i;
    					}	
    					if(k==goalnum)
    					{
//    						System.out.println(sum);
    						ans=printpath(k);
    						return;
    					}
    					q.add(op);
    					String temp1="";
    		    		for(int m=0;m<3;m++)
    					{
    						for(int n=0;n<3;n++)
    							temp1+=op.chess[m][n];
    					}
//    		    		System.out.println("放元素"+temp1);
    				}
    			}
    		}
    	}
    	
    }
    public static String getans(int[]s)
    {
//    	int[]s= {7,2,4,3,1,6,8,5,0};
//    	int[]s={4,7,2,8,3,5,6,1,0};
    	Astart(s);
    	StringBuffer fans=new StringBuffer();
    	for(int i=1;i<ans.length();i++)
    		fans.append(ans.charAt(i));
    	return fans.toString();
    }
}

import java.util.Arrays;
import java.util.Stack;
//有界深度优先搜索,给定一个搜索深度进行搜索
class dnode
{
	public int[][]chess=new int[3][3];
	public int x,y;//同记录空格位置
	public int step;//记录所走的步数
	public int code;
	dnode(){};
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
	}
}
public class EightNumberDfs {
	static int[]goal= {1,2,3,4,5,6,7,8,0};
	static int goalnum;
	static int max=999999;
	static int[][] dir={{-1,0},{1,0},{0,-1},{0,1}};
	static int[]code={1,1,2,6,24,120,720,5040,40320};
	static boolean[]visit=new boolean[max];
	static String dic="上下左右";//记录走的方向
	static int pre[]=new int[max]; 
	static int path[]=new int[max];
	static int deepth=0;
	static dnode goalnode;//目标节点
	static String ans;
	public static int hash(dnode a)
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
	public static boolean success(dnode temp)
	{
		goalnode=new dnode();
		goalnode.set(goal);
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(temp.chess[i][j]!=goalnode.chess[i][j])
					return false;
			}
		}
		return true;
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
	public static boolean dfs(dnode as,int dm)
	{
//		System.out.println("start");
		Stack<dnode> OPEN=new Stack();//open表
		Stack<dnode> CLOSED=new Stack();//close表
		dnode begin=new dnode();
		begin.chess=as.chess;
		begin.x=as.x;begin.y=as.y;
		begin.step=0;
		int hk=hash(begin);
		begin.code=hk;
		visit[hk]=true;
		pre[hk]=-1;
		OPEN.push(begin);
		int xx,yy,k;
		do
		{
			dnode a=OPEN.peek();
			OPEN.pop();
			if(a.code==goalnum)
			{
				ans=printpath(a.code);
				return true;
			}
			//在某一分支以到达最大搜索深度仍未搜索到答案，放弃该分支
			if(a.step==dm)
			{
				CLOSED.push(a);
				continue;
			}
			//拓展新的节点
			for(int i=0;i<4;i++)
			{
				xx=a.x+dir[i][0];
    			yy=a.y+dir[i][1];
    			if(xx>=0&&xx<3&&yy>=0&&yy<3)
    			{
    				dnode op=new dnode();
    				for(int m=0;m<3;m++)
    				{
    					for(int n=0;n<3;n++)
    						op.chess[m][n]=a.chess[m][n];
    				}
    				op.chess[a.x][a.y]=a.chess[xx][yy];
    				op.chess[xx][yy]=a.chess[a.x][a.y];
    				k=hash(op);
    				if(!visit[k])
    				{
    					visit[k]=true;
    					op.code=k;
    					op.x=xx;
    					op.y=yy;
    					op.step=a.step+1;
    					if(k!=begin.code)
    					{
    						pre[k]=a.code;
    						path[k]=i;
    					}
    					if(k==goalnum)
    					{
    						ans=printpath(k);
    						return true;
    					}
    					OPEN.push(op);
    				}
			   }
		   }
		}while(!OPEN.isEmpty());
		return false;
	}
	public static String getans(int[]start,int dm)
	{
		dnode end=new dnode();
		end.set(goal);
		goalnum=hash(end);
		Arrays.fill(visit, false);
		dnode begin=new dnode();
		begin.set(start);
		boolean res=dfs(begin,dm);
		if(res)
		{	
			StringBuffer fans=new StringBuffer();
    		for(int i=1;i<ans.length();i++)
    			fans.append(ans.charAt(i));
    		return fans.toString();
		}
		else
		{
			ans="已经到达搜索深度未能搜索到";
			return ans;
		}
	}
}
import java.util.Arrays;
public class EightNumberBfs {
	static int[]goal= {1,2,3,4,5,6,7,8,0};
	static int max=999999;
	static int pre[]=new int[max]; 
	static int path[]=new int[max];
	static int[]dx= {-1,1,0,0};
	static int[]dy= {0,0,-1,1};
	static int[][]chess=new int[max][9];
	static int[]dist=new int[max];
	static String dic="上下左右";//记录走的方向
	static int[]code=new int[max];
	static boolean[]visit=new boolean[max];
	//判断该状态是否有效
	public static boolean solve(int[]a)
	{
		int sum=0;
	    for(int i=0; i < 9; i++)  
	        for(int j=i+1; j < 9; j++)  
	            if(a[j] != 0 && a[i] != 0 && a[i] > a[j])  
	                sum++;
	    if(sum % 2 == 0) {
	    	return true;
	    }
	    return false;
	}
	public static void encode()
	{
		code[0] = 1;
		for(int i = 1; i < 9; i++) {
			code[i] = code[i-1] * i;
		}
		Arrays.fill(visit, false);
	}
	public static boolean decode(int s)
	{
		int c = 0;
		for(int i = 0; i < 9; i++) {
			int cnt = 0;
			for(int j = i+1; j < 9; j++) {
				if(chess[s][j] < chess[s][i]) {
					cnt++;
				}
			}
			c += code[8-i] * cnt;
		}
		if(visit[c]) {
			return false;
		}
		return visit[c] = true;
	}
	public static int bfs(int[]start)
	{
		chess[1]=Arrays.copyOf(start, start.length);
		int s=1,e=2;
		encode();
		decode(s);
		while(s<e)
		{
			if(Arrays.equals(chess[s],goal))
				return s;
			int p;
			for(p=0;p<9;p++)
			{
				if(chess[s][p]==0)
					break;
			}
			int x=p/3;int y=p%3;
			for(int i=0;i<4;i++)
			{
				int nx=x+dx[i];
				int ny=y+dy[i];
				int nz=nx*3+ny;
				if(nx<3&&nx>=0&&ny<3&&ny>=0)
				{
					chess[e] = Arrays.copyOf(chess[s], chess[s].length);
					chess[e][p]=chess[s][nz];
					chess[e][nz]=chess[s][p];
					dist[e]=dist[s]+1;
					if(decode(e)) 
					{
						pre[e]=s;
						path[e]=i;
						e++;
					}
				}
			}
			s++;
		}
		return 0;
	}
	public static String outpath(int p)
	{
		StringBuffer respath=new StringBuffer();
		while(p!=1)
		{
			respath.insert(0,dic.charAt(path[p]));
			p=pre[p];
		}
		return respath.toString();
	}
}
class test
{
	public static void main(String[]args)
	{
		int []start= {8,7,1,5,2,4,6,3,0};
		EightNumberBfs t=new EightNumberBfs();
		int begin=EightNumberBfs.bfs(start);
		String res=EightNumberBfs.outpath(begin);
//		System.out.println(res);
	}
}

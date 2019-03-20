package DataMining;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;
import org.apache.commons.io.FileUtils;

public class FP {

	private static LinkedList<LinkedList<Integer>> sourceItems = new LinkedList<>();	// 存原始数据
	private static Scanner scanner;
	private static LinkedHashMap<List<Integer>, Integer> frequentSets = new LinkedHashMap<List<Integer>, Integer>();	// 存频繁项集
	private static final double MIN_SUP = 0.001;	// 最小支持度
	private static int minSup;
	
	public static void main(String[] args) throws IOException {	
		readData();
		buildFPTree(sourceItems);
		// 打印频繁项集
		frequentSets.forEach((key, value) -> System.out.println(key + " : " + value));	
		// 打印频繁项集个数
		
		Integer count[] = {0, 0, 0, 0, 0, 0};
		for (Map.Entry<List<Integer>, Integer> entry : frequentSets.entrySet()) {  
			List<Integer> items = entry.getKey();
			count[items.size()]++; 
 		}  
		int i = 1;
		while(i < 6)
			System.out.println(count[i++]);
		
		System.out.println(frequentSets.size());
	}

	public static void readData() throws IOException {
		// 读入数据，使用 org.apache.commons.io.* 
		List<String> strLine =  FileUtils.readLines(new File("/Users/WYH/Coding/Java/Java/src/DataMining/retail.dat"), "UTF-8");
		for(int i = 0; i < strLine.size(); i++) {
			LinkedList<Integer> e = new LinkedList<>();
			scanner = new Scanner(strLine.get(i));
			while(scanner.hasNextInt()) {
				e.add(scanner.nextInt());
			}
			sourceItems.add(e);
		}
		minSup = (int) (MIN_SUP * sourceItems.size());
		System.out.println(minSup);
	}
	
	public static HashMap<Integer, Integer> getFrequency(LinkedList<LinkedList<Integer>> sourceItems) {
		// 获取频繁项
		HashMap<Integer, Integer> items = new HashMap<Integer, Integer>();
		for (List<Integer> list : sourceItems) {
            for (Integer s : list) {
                if (!items.containsKey(s)) {
                		items.put(s, 1);
                } else {
                		items.put(s, items.get(s) + 1);
                }
            }
        }
        return items;
    }
	
	public static void buildFPTree(LinkedList<LinkedList<Integer>> sourceItems) {
		HashMap<Integer, Integer> freqMapTemp = getFrequency(sourceItems);
		LinkedHashMap<Integer, Integer> freqMap = new LinkedHashMap<Integer, Integer>();	
		// 升序比较器
		Comparator<Map.Entry<Integer, Integer>> valueComparator = new Comparator<Map.Entry<Integer,Integer>>() {
	        public int compare(Entry<Integer, Integer> o1,
	                Entry<Integer, Integer> o2) {
	            return o1.getValue()-o2.getValue();
	        }
	    };
	    // map转换成list进行排序
	    List<Map.Entry<Integer, Integer>> list = new ArrayList<Map.Entry<Integer,Integer>>(freqMapTemp.entrySet());
	    // 排序，对频繁一项集进行排序
	    Collections.sort(list,valueComparator);
	    
	    Iterator<Entry<Integer, Integer>> it = list.iterator();
	    int i = 1;
		while (it.hasNext()) {
			Map.Entry<Integer, Integer> entry = (Map.Entry<Integer, Integer>) it.next();
			freqMap.put(entry.getKey(), i++);
		}
	    // 按照频繁一项集的顺序对原始数据进行排序，只排这一次即可，后面程序按照前的顺序不要打乱
		for(LinkedList<Integer> items : sourceItems) {
			Collections.sort(items, new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
            			return freqMap.get(o2) - freqMap.get(o1);
                }
            });
		}
		FPGrowth(sourceItems, null);
	}
	
	private static void FPGrowth(LinkedList<LinkedList<Integer>> cpb, LinkedList<Integer> postModel) {
		
		Map<Integer, Integer> freqMapTemp = getFrequency(cpb);
		// 降序比较器
		Comparator<Map.Entry<Integer, Integer>> valueComparator = new Comparator<Map.Entry<Integer,Integer>>() {
	        @Override
	        public int compare(Entry<Integer, Integer> o1,
	                Entry<Integer, Integer> o2) {
	            return o2.getValue()-o1.getValue();
	        }
	    };
	    // map转换成list进行排序
	    List<Map.Entry<Integer, Integer>> list = new ArrayList<Map.Entry<Integer,Integer>>(freqMapTemp.entrySet());
	    // 排序，此处不排序也可以，最初是为了调试程序方便，排了序
	    Collections.sort(list,valueComparator);
	    Map<Integer, TreeNode> headers = new LinkedHashMap<Integer, TreeNode>();
	    Iterator<Entry<Integer, Integer>> it = list.iterator();
		while (it.hasNext()) {
			Map.Entry<Integer, Integer> entry = (Map.Entry<Integer, Integer>) it.next();
			Integer name = entry.getKey();
            int cnt = entry.getValue();
            // 每一次递归时都有可能出现一部分模式的频数低于阈值
            if (cnt >= minSup) {
                TreeNode node = new TreeNode(name);
                node.setCount(cnt);
                headers.put(name, node);
            }
            else
            		break;
		}

        TreeNode treeRoot = buildSubTree(cpb, headers);
        // 如果只剩下虚根节点，则递归结束
        if ((treeRoot.getChildren() == null) || (treeRoot.getChildren().size() == 0)) {
        		return ;
        }
        
        for (TreeNode header : headers.values()) {
        		
            List<Integer> rule = new ArrayList<Integer>();
            rule.add(header.getName());
            if (postModel != null) {
                rule.addAll(postModel);
            }
            // 表头项+后缀模式，构成一条频繁模式（频繁模式内部也是按照一项集排序的），频繁度为表头项的计数
            frequentSets.put(rule, header.getCount());
            // 新的后缀模式：表头项+上一次的后缀模式（注意保持顺序，始终按一项集的顺序排列）
            LinkedList<Integer> newPostPattern = new LinkedList<Integer>();
            newPostPattern.add(header.getName());
            if (postModel != null) {
                newPostPattern.addAll(postModel);
            }
            // 新的数据集
            LinkedList<LinkedList<Integer>> newCPB = new LinkedList<LinkedList<Integer>>();
            TreeNode nextNode = header;
            
            while ((nextNode = nextNode.getNextHomonym()) != null) {
            		int counter = nextNode.getCount();
                //获得从虚根节点（不包括虚根节点）到当前节点（不包括当前节点）的路径，即一条条件模式基。注意保持顺序：父节点在前，子节点在后，即始终保持频率高的在前
                LinkedList<Integer> path = new LinkedList<Integer>();
                TreeNode parent = nextNode;
                while ((parent = parent.getParent()).getName() != null) {
                		// 虚根节点的name为null
                    path.push(parent.getName()); //往表头插入
                } 
                // 事务要重复添加counter次
	            if(path.size() != 0) {
                while (counter-->0) {
	            		newCPB.add(path);
	            }
	            }
            }
            FPGrowth(newCPB, newPostPattern);
        }
    }
		
	private static TreeNode buildSubTree(LinkedList<LinkedList<Integer>> cpb, Map<Integer, TreeNode> headers) {
		TreeNode root = new TreeNode();		//虚根节点
		for (List<Integer> item : cpb) {
			LinkedList<Integer> record = new LinkedList<Integer>(item);
			TreeNode subTreeRoot = root;
			TreeNode tmpRoot = null;
			if (root.getChildren() != null) {
				//延已有的分支，令各节点计数加1			
				while (!record.isEmpty() && (tmpRoot = subTreeRoot.findChild(record.peek())) != null) {
					tmpRoot.countIncrement(1);
					subTreeRoot = tmpRoot;
					record.poll();
				}
			}
			//长出新的节点
			addNodes(subTreeRoot, record, headers);
		}
		return root;
	}
	
	private static void addNodes(TreeNode ancestor, LinkedList<Integer> record, Map<Integer, TreeNode> headers) {
		 while (!record.isEmpty()) {
			 Integer item = (Integer) record.poll();	// 移除并返回队首元素
			 // 单个项的出现频数必须大于最小支持数，否则不允许插入FP树。达到最小支持度的项都在headers中。
			 // 每一次递归根据条件模式基本建立新的FPTree时，把要把频数低于minSup的排除在外，这也正是FPTree快的真正原因
			 if (headers.containsKey(item)) {
				 TreeNode leafnode = new TreeNode(item);
				 leafnode.setCount(1);
				 leafnode.setParent(ancestor);
				 ancestor.addChild(leafnode);

				 TreeNode header = headers.get(item);
				 TreeNode tail=header.getTail();
				 if(tail!=null){
					 tail.setNextHomonym(leafnode);
				 } else {
					 header.setNextHomonym(leafnode);
				 }
				 header.setTail(leafnode);
				 addNodes(leafnode, record, headers);
			 }
		 }
	 }
}



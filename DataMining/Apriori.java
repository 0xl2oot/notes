package DataMining;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

import org.apache.commons.io.FileUtils;

public class Apriori {

	private static List<List<Integer>> sourceItems = new ArrayList<>();
	private static Scanner scanner;
	private static HashMap<Integer, Integer> C1 = new HashMap<Integer, Integer>();
	private static ArrayList<HashMap<List<Integer>, Integer>> rankFrequentSets = new ArrayList<HashMap<List<Integer>, Integer>>();
	private static final double MIN_SUP = 0.01;
	private static double minSup;
	
	public static void main(String[] args) throws IOException {
		readData();
		findOneElementItems();
		obtainL1();
		
		int k = 2;
		int count = 0;
		while(obtainFrequentSet(k++) != null) {
			;
		}
		
		for(k = 0; k < rankFrequentSets.size(); k++) {
			HashMap<List<Integer>, Integer> map = rankFrequentSets.get(k);
			System.out.println(map.size());
			count += map.size();
		}
		System.out.println(count);
	}
	
	public static void readData() throws IOException {
		List<String> strLine =  FileUtils.readLines(new File("/Users/WYH/Coding/Java/Java/src/DataMining/retail.dat"), "UTF-8");
		for(int i = 0; i < strLine.size(); i++) {
			List<Integer> e = new ArrayList<>();
			scanner = new Scanner(strLine.get(i));
			while(scanner.hasNextInt()) {
				e.add(scanner.nextInt());
			}
			sourceItems.add(e);
		}
		minSup = MIN_SUP * sourceItems.size();
	}
	
	// 1项集 C1
	public static HashMap<Integer, Integer> findOneElementItems() {
        for (List<Integer> list : sourceItems) {
            for (Integer s : list) {
                if (!C1.containsKey(s)) {
                    C1.put(s, 1);
                } else {
                    C1.put(s, C1.get(s) + 1);
                }
            }
        }
        return C1;
    }
	
	// 频繁1项集 L1
	public static HashMap<List<Integer>, Integer> obtainL1() {
		HashMap<List<Integer>, Integer> items = new HashMap<>();
		for(Integer key : C1.keySet()) {
			int value = C1.get(key);
			if(value >= minSup) {
				List<Integer> item = new ArrayList<>();
				item.add(key);
				items.put(item, value);
			}
		}
		rankFrequentSets.add(0, items);
		items.forEach((key, value) -> System.out.println(key + " : " + value));
		return items;
	}
	
	// 连接产生k项集 Lk
	public static List<List<Integer>> link(int k) {
		List<List<Integer>> items = new ArrayList<>();
		HashMap<List<Integer>, Integer> map = rankFrequentSets.get(k - 2);
		Set<List<Integer>> keys = map.keySet();
		Iterator<List<Integer>> iterator = keys.iterator();
		
		if(k == 2) {
			for(int i = 0; i < keys.size(); i++) {
				List<Integer> item = iterator.next();
				Iterator<List<Integer>> iterator2 = keys.iterator();
				for (int j = 0; j < i + 1; j++) {
	                iterator2.next();
	            }
		        for (int j = i + 1; j < keys.size(); j++) {
		        		List<Integer> item2 = iterator2.next();
		        		List<Integer> instance = new ArrayList<>();
		        		instance.add(item.get(0));
		            	instance.add(item2.get(0));
		        		items.add(instance);
		        }
	        }	 
		}
		else {
			for(int i = 0; i < keys.size(); i++) {
				List<Integer> item = iterator.next();
				Iterator<List<Integer>> iterator2 = keys.iterator();
				for (int j = 0; j < i + 1; j++) {
					iterator2.next();
		        }
		        for (int j = i + 1; j < keys.size(); j++) {
		        		List<Integer> item2 = iterator2.next();
		        		if (linkable(item, item2)) {
		            		List<Integer> instance = new ArrayList<>();
		        			for (int n = 0; n < k - 1; n++) {
		        				instance.add(item.get(n));
		        			}
		        			instance.add(item2.get(k - 2));
		        			items.add(instance);
		            }
		        }	 
			}
		}		
		return items;
	}
	
	// 剪枝 产生 Ck
	public static HashMap<List<Integer>, Integer> obtainFrequentSet(int k) {
		List<List<Integer>> items = link(k);
		HashMap<List<Integer>, Integer> freSet = new HashMap<>();
		for (List<Integer> item : items) {
            int count = 0;
            for (List<Integer> source : sourceItems) {
                boolean flag = true;
                for (Integer s : item) {
                    if (!source.contains(s)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    count++;
                }
            }
            if (count >= minSup) {
                freSet.put(item, count);
            }
        }
        if (freSet.size() <= 0)
            return null;
        rankFrequentSets.add(k - 1, freSet);
        freSet.forEach((key, value) -> System.out.println(key + " : " + value));
		return freSet;
	}
	
	public static boolean linkable(List<Integer> item, List<Integer> item2) {
		for (int i = 0; i < item.size() - 1; i++) {
            if (!item.get(i).equals(item2.get(i)))
                return false;
        }
        return true;
	}
}



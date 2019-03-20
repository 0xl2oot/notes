package DataMining;

import java.util.ArrayList;
import java.util.List;

public class TreeNode {
    // 节点名称
    private Integer name;
    // 频数
    private Integer count;
    private TreeNode parent;
    private List<TreeNode> children;
    // 下一个节点（由表头项维护的那个链表）
    private TreeNode nextHomonym;
    // 末节点（由表头项维护的那个链表）
    private TreeNode tail;

    public TreeNode() {
    }

    public TreeNode(Integer name) {
        this.name = name;
    }

    public Integer getName() {
        return this.name;
    }

    public void setName(Integer name) {
        this.name = name;
    }

    public Integer getCount() {
        return this.count;
    }

    public void setCount(Integer count) {
        this.count = count;
    }

    public TreeNode getParent() {
        return this.parent;
    }

    public void setParent(TreeNode parent) {
        this.parent = parent;
    }

    public List<TreeNode> getChildren() {
        return this.children;
    }

    public void addChild(TreeNode child) {
        if (getChildren() == null) {
            List<TreeNode> list = new ArrayList<TreeNode>();
            list.add(child);
            setChildren(list);
        } else {
            getChildren().add(child);
        }
    }

    public TreeNode findChild(Integer name) {
        List<TreeNode> children = getChildren();
        if (children != null) {
            for (TreeNode child : children) {
                if (child.getName() == name) {
                    return child;
                }
            }
        }
        return null;
    }

    public void setChildren(List<TreeNode> children) {
        this.children = children;
    }

    public void printChildrenName() {
        List<TreeNode> children = getChildren();
        if (children != null) {
            for (TreeNode child : children)
                System.out.println(child.getName() + " ");
        } else
            System.out.print("null");
    }

    public TreeNode getNextHomonym() {
        return this.nextHomonym;
    }

    public void setNextHomonym(TreeNode nextHomonym) {
        this.nextHomonym = nextHomonym;
    }

    public void countIncrement(Integer n) {
        this.count += n;
    }

    public TreeNode getTail() {
        return tail;
    }

    public void setTail(TreeNode tail) {
        this.tail = tail;
    }

}
package Matrix_Exponentiation;
import java.util.*;
import java.lang.*;
import java.io.*;

public class MultipleOfThree {
  static int arr[];
  static BitSet tree[];

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    int n = s.nextInt();
    arr = new int[n];
    for (int i = 0; i < n; i++) {
      arr[i] = s.nextInt();
    }
    tree = new BitSet[4 * n + 1];
    buildTree(0, arr.length - 1, 1);
    int q = s.nextInt();
    for (int i = 0; i < q; i++) {
      int first = s.nextInt();
      int second = s.nextInt();
      int third = s.nextInt();
      if (first == 1) {
        update(0, arr.length - 1, third, second - 1, 1, arr[second - 1]);
      } else {
        BitSet tmp = query(0, arr.length - 1, second - 1, third - 1, 1);
        System.out.println(tmp.cardinality());
      }
    }
  }
  private static void buildTree(int ss, int se, int index) {
    if (ss == se) {
      tree[index] = new BitSet(1001);
      tree[index].set(arr[ss]);
      return;
    }
    int mid = (ss + se) / 2;
    buildTree(ss, mid, 2 * index);
    buildTree(mid + 1, se, (2 * index) + 1);
    BitSet first = (BitSet) tree[2 * index].clone();
    BitSet second = (BitSet) tree[2 * index + 1].clone();
    first.xor(second);
    tree[index] = new BitSet();
    tree[index] = (BitSet) first.clone();
    return;
  }
  private static void update(int ss, int se, int val, int i, int index, int prev) {
    if (se < i || i < ss) {
      return;
    }
    if (ss == se && ss == i) {
      tree[index].flip(val);
      tree[index].flip(arr[i]);
      arr[i] = val;
      return;
    }
    int mid = (ss + se) / 2;
    update(ss, mid, val, i, 2 * index, prev);
    update(mid + 1, se, val, i, (2 * index) + 1, prev);
    BitSet first = (BitSet) tree[2 * index].clone();
    BitSet second = (BitSet) tree[2 * index + 1].clone();
    first.xor(second);
    tree[index] = new BitSet();
    tree[index] = (BitSet) first.clone();
    return;
  }
  private static BitSet query(int ss, int se, int l, int r, int index) {
    if (l > se || r < ss) {
      return new BitSet(1001);
    }
    if (ss >= l && se <= r) {
      return tree[index];
    }
    int mid = (ss + se) / 2;
    BitSet f = query(ss, mid, l, r, 2 * index);
    BitSet s = query(mid + 1, se, l, r, (2 * index) + 1);
    BitSet first = (BitSet) f.clone();
    BitSet second = (BitSet) s.clone();
    first.xor(second);
    return first;
  }
}
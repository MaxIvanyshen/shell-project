package shell;

import java.util.List;
import java.util.ArrayList;

public class Lister {
  public void list() {
    List<Integer> list = new ArrayList<>(); 
    for(int i = 0; i < 5; i++) {
      list.add(i);
    }

    for(int i : list) {
      System.out.println(i);
    }
  }
}

import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

class Solution {
  public int[][] alpha;
  public List<String> answer= new ArrayList<>();
  public int customer;
  public Map<String, Integer> menu = new HashMap<String, Integer>();

  public void dfs(int dest, int depth, String str, int before, int num){
    if(dest == depth){
      if(menu.containsKey(str)){
        menu.replace(str, menu.get(str)+1);
      }
      else menu.put(str, 1);

      return;
    }

    for(int i=before+1;i<26;i++){
      if(alpha[num][i] == 1){

        dfs(dest, depth+1, str +  (char)('A' + i), i, num);
      }
    }

    return;
  }

  public void getCombine(int depth){
    menu.clear();

    for(int i=0;i<customer;i++){
      dfs(depth, 0, "", -1, i);
    }

    if(!menu.isEmpty()){
      List<Entry<String, Integer>> entries = new ArrayList<Entry<String, Integer>>(menu.entrySet());

      // 비교함수 Comparator를 사용하여 내림 차순으로 정렬
      Collections.sort(entries, new Comparator<Entry<String, Integer>>() {
        // compare로 값을 비교
        public int compare(Entry<String, Integer> obj1, Entry<String, Integer> obj2)
        {
          // 내림 차순으로 정렬
          return obj2.getValue().compareTo(obj1.getValue());
        }
      });

      int max_v = entries.get(0).getValue();
      if(max_v >= 2){
        for(Entry<String, Integer> entry : entries){
          if(max_v == entry.getValue()){
            answer.add(entry.getKey());
          }
        }
      }
    }


  }

  public String[] solution(String[] orders, int[] course) {
    customer = orders.length;
    alpha = new int[orders.length][26];
    for(int i=0;i<orders.length;i++){
      for(int j=0;j<orders[i].length();j++){
        alpha[i][orders[i].charAt(j) - 'A'] = 1;
      }
    }

    for(int i=0;i<course.length;i++){
      getCombine(course[i]);
    }

    Collections.sort(answer);
    int arrListSize = answer.size();
    String arr[] = answer.toArray(new String[arrListSize]);

    return arr;
  }
}
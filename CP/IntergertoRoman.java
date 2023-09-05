import java.util.*;
class IntergertoRoman {
    public static void main(String[] args) {
       HashMap<Integer, String> map = new HashMap<Integer, String>();
         map.put(1, "I");
            map.put(5, "V");
            map.put(10, "X");
            map.put(50, "L");
            map.put(100, "C");
            map.put(500, "D");
            map.put(1000, "M");

            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the number");
            int num = sc.nextInt();
            String str = "";
            int temp = num;
            int count = 0;
            while (temp > 0) {
                temp = temp / 10;
                count++;
            }
            int div = (int) Math.pow(10, count - 1);     //
            while (num > 0) {
                int rem = num / div;
                if (rem == 4) {
                    str = str + map.get(div) + map.get(div * 5);
                } else if (rem == 9) {
                    str = str + map.get(div) + map.get(div * 10);
                } else if (rem >= 5) {
                    str = str + map.get(div * 5);
                    for (int i = 0; i < rem - 5; i++) {
                        str = str + map.get(div);
                    }
                } else {
                    for (int i = 0; i < rem; i++) {
                        str = str + map.get(div);
                    }
                }
                num = num % div;
                div = div / 10;
            }
            System.out.println(str);
    }
}


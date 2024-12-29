import java.util.*;

public class rajesh{
    public static String[] map =  {".","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

    public static int main1(int x, int y, int z, int k){
        if (x == z || y == k){
            return 0;
        }

        if (x == z-1 && y == k-1){
            return 1;
        }
        int i = main1(x+1, y, z,k);
        int j = main1(x, y+1, z,k);
        return i + j;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // String x = sc.nextLine();
        System.out.println(main1(0,0,3,3));
        sc.close();
    }
}


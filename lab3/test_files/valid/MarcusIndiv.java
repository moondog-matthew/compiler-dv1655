public class BinaryTree{
    public static void main(String[] a){
	System.out.println(new BT().Start());
    }
}

class BT {

    public int Start(){
		int x;
        x = 10;
        boolean a;
        boolean b;
        
        while (x < 20) {
            a = b;
            if (x < 1) 
                x = x - 1;
            else 
                x = x + 1;
            b = false;
        }
        // while (x < 1) {
        //     a = b;  
        // }
        // if (x < 1) 
        //     while (x < 1) {
        //         a = b;  
        //     }
        // else 
        //     x = x + 1;


        x = x + 1;
        int y;
        y = 121;

        return 0;
    }

}
public class BinaryTree{
    public static void main(String[] a){
	    System.out.println(new BT().Start());
    }
}

class BT {

    public int Start(){
		int x;
        boolean a;
        boolean b;
        int i;
        int z;
        int easy;
        x = 10 / 5 * 50;
        x = x - 1;
        x = x / 9;
        x = x * 3;
        z = 1;
        easy = 65;

        i = this.Method1(x, 30, z, easy);
        if (!(100 < 50)) 
            System.out.println(easy);

        while (i < 20) {
            
            i = i + 2;
            if (i == 18) 
                System.out.println(18);
            else 
                if (x < 1) 
                    x = x - 1;
                else 
                    while (z < 10) {
                        if (i > 10) 
                            System.out.println(10);
                        else 
                            System.out.println(5);
                        z = z + 5;
                    }
        }


        // while (x < 20) {
        //     a = b;
        //     if (x < 1) 
        //         x = x - 1;
        //     else 
        //         x = x + 1;
        //     b = false;
        // }
        // while (x < 1) {
        //     a = b;  
        //     while (x > 10) {
        //         z = i;  
        //     }
        // }
        // if (x < 1) 
        //     while (x < 1) {
        //         a = b;  
        //     }
        // else 
        //     x = x + 1;
        
        // if (!(x < 1)) 
        //     x = x - 1;
        // else 
        //     if (x > 10) 
        //         a = b;
        //     else 
        //         b = a;

        // if (x < 10) 
        //     b = a;
        // else 
        //     a = b;
        System.out.println(i);
        return x;
    }

    public int Method1(int num, int num2, int num3, int num4){
		int x;
        x = 10;
        boolean a;
        boolean b;
        int i;
        int z;

        z = this.Method2();
        z = z + 1;
        System.out.println(z);
        // while (x < 20) {
        //     a = b;
        //     if (x < 1) 
        //         x = x - 1;
        //     b = false;
        // }
        
        return 54;
    }
    public int Method2(){        
        return 999;
    }
    

}
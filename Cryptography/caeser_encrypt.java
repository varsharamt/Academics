
import java.io.*;
import java.util.*;

public class caeser_encrypt {

    public static void main(String args[]) throws IOException {
    
        int i;
        char c;
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the plaintext:\n");
        String a=bf.readLine();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the key");
        int b=Integer.parseInt(br.readLine());
     
        for(i=0;i<a.length();i++) {
        
           if((int)a.charAt(i)>96&&(int)a.charAt(i)<123) {
           

              int result=b+(int)a.charAt(i);
              if(result>122) {
              
                 result-=26;
              }
              c=(char)result;
              System.out.print(c);
         
          }
          else {
           
              System.out.print(a.charAt(i));
         
          }    
        }
  }
}

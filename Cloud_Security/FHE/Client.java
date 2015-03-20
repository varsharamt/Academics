import java.net.*;
import java.io.*;
import java.util.*;
public class Client {
  public static void main(String args[]) {
    try {
      int p,q1,q2,r1,r2,n1,n2,i,j=0,sum,product,res1,res2;
      int binary1[] = new int[20];
      int binary2[] = new int[20];
      int cipher[] = new int[20];

      Socket s = new Socket("localhost",2345);
      OutputStream output = s.getOutputStream();
      DataOutputStream out = new DataOutputStream(output);
      InputStream ser = s.getInputStream();
      DataInputStream input =new DataInputStream(ser);
      Scanner sc = new Scanner(System.in);
      System.out.println("enter the value for p,q1,q2,r1,r2,n1,n2");
      p = sc.nextInt();
      q1 = sc.nextInt();
      q2 = sc.nextInt();
      r1 = sc.nextInt();
      r2 = sc.nextInt();
      n1 = sc.nextInt();
      n2 = sc.nextInt();

      while(n1 > 0){
        binary1[j] = n1%2;
        n1 = n1/2;
        j++;
      }

      while(n2 > 0){
        binary2[j] = n2%2;
        n2 = n2/2;
        j++;
      }
  
      for(i=0;i<10;i=i+2){
	      cipher[i]=(p*q1)+(2*r1)+(binary1[i]);
	      cipher[i+1]=(p*q2)+(2*r2)+(binary2[i]);
      }

      for(i=0;i<10;i=i+1){
        out.writeInt(cipher[i]);
      }
      sum=input.readInt();
      product=input.readInt();
      System.out.println("c1+c2: "+sum+"\n");
      System.out.println("c1*c2: "+product+"\n");
      res1=sum%p;
      if (res1%2==0)
        System.out.println("even,,,bit = zero\n");
      else
        System.out.println("odd,,,bit = one\n");
      res2=product%p;
      if (res2%2==0)
        System.out.println("even,,,bit=zero\n");
      else
       System.out.println("odd,,,bit=one\n");
    }
    catch(IOException e) {
       e.printStackTrace();
    }
  }
}

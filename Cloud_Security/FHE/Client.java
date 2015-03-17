import java.net.*;
import java.io.*;
import java.util.*;

public class Client {

   

    public static void main(String args[])throws IOException
    {   
        try
        {
	    int i,j=0,sum,product,res1,res2;
            int binary1[] = new int[25];
	    int binary2[] = new int[25];	
	    int cipher[] = new int[25];
            String host = "localhost";
            int port = 2345;
      	    Socket s = new Socket(host,port);
	    OutputStream outToServer = s.getOutputStream();
 	    DataOutputStream out = new DataOutputStream(outToServer);

	    InputStream ser = s.getInputStream();
            DataInputStream in =new DataInputStream(ser);
	    BufferedReader bufferRead = new BufferedReader(new InputStreamReader(System.in));
	    System.out.println("enter the value for p,q1,q2,r1,r2,n1,n2");
	    int p = Integer.parseInt(bufferRead.readLine());
            int q1 = Integer.parseInt(bufferRead.readLine());
	    int q2 = Integer.parseInt(bufferRead.readLine());	
 	    int r1 = Integer.parseInt(bufferRead.readLine());
            int r2 = Integer.parseInt(bufferRead.readLine());		
      	    int n1 = Integer.parseInt(bufferRead.readLine());
	    int n2 = Integer.parseInt(bufferRead.readLine());
		
	    while(n1 > 0){
                binary1[j++] = n1%2;
                n1 = n1/2;
            }
 	    while(n2 > 0){
                binary2[j++] = n2%2;
                n2 = n2/2;
            }
           
            for(i=0;i<10;i=i+2){
	       cipher[i]=(p*q1)+(2*r1)+(binary1[i]);
               cipher[i+1]=(p*q2)+(2*r2)+(binary2[i]);
            }	
	    for(i=0;i<10;i=i+1){
	     out.writeInt(cipher[i]);	  
	    }
             sum=in.readInt();
	     product=in.readInt();
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

      catch (Exception exception) {
            exception.printStackTrace();
      }
      finally {
            
         try {}
         catch(Exception e) {
                e.printStackTrace();
          }
      }
    } 
}

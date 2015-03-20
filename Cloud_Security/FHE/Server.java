import java.net.ServerSocket;
import java.net.Socket;
import java.net.*;
import java.io.*;
import java.util.Scanner;
public class Server {
  private ServerSocket serverSocket;
  public static void main(String[] args) {
    try {
      ServerSocket serverSocket = new ServerSocket(2345);
      Socket server = serverSocket.accept();
      System.out.println("Server Waiting!!!");
      int num[] = new int[20];
      int i;
      DataInputStream in =new DataInputStream(server.getInputStream());
      DataOutputStream out =new DataOutputStream(server.getOutputStream());
      for(i=0;i<10;i++){
        num[i]=in.readInt();
      }
      int c =num[0]+num[1];
      int d= num[0]*num[1];
      out.writeInt(c);
      out.writeInt(d);
      server.close();
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }
} 

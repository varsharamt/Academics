package com.example.Proc1;

import java.io.*;
import java.util.*;
import java.lang.*;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


import com.google.appengine.api.datastore.DatastoreServiceFactory;
import com.google.appengine.api.datastore.DatastoreService;
import com.google.appengine.api.datastore.Query.Filter;
import com.google.appengine.api.datastore.Query.FilterPredicate;
import com.google.appengine.api.datastore.Query.FilterOperator;
import com.google.appengine.api.datastore.Query.CompositeFilter;
import com.google.appengine.api.datastore.Query.CompositeFilterOperator;
import com.google.appengine.api.datastore.Query;
import com.google.appengine.api.datastore.PreparedQuery;
import com.google.appengine.api.datastore.Entity;


/**
 * Servlet implementation class Proc1
 */
//@WebServlet("/Project1")
public class Proc1Servlet extends HttpServlet {
private static final long serialVersionUID = 1L;

  protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
  
    
    response.setContentType("text/html");
	PrintWriter out = response.getWriter();
	
	
	String name=request.getParameter("name");
	String roll_number=request.getParameter("roll_number");
	String DOB=request.getParameter("DOB");
	DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();
	
	Entity Student = new Entity("Student");
	Student.setProperty("name", name);
	Student.setProperty("roll_number", roll_number);
	Student.setProperty("DOB", DOB);
	datastore.put(Student);
	
}


/**
* @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
*/
protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
// TODO Auto-generated method stub
	doGet(request,response);
	response.setContentType("text/html");
	PrintWriter out = response.getWriter();
	
    out.println("<!DOCTYPE html>");
    out.println("<html>");
    out.println("<head>");
    out.println("<title>Student Details</title>");            
    out.println("</head>");
    out.println("<body>");
    out.println("<CENTER>");
    out.println("<table BORDER=1 CELLPADDING=0 CELLSPACING=0 WIDTH=50% >");
    out.println("<th>Student Name</th>");
    out.println("<th>Roll Number</th>");
    out.println("<th>Date of Birth</th>");
    DatastoreService datastore = DatastoreServiceFactory.getDatastoreService();
    Query s = new Query("Student");
    PreparedQuery stud = datastore.prepare(s);
   
    for (Entity result : stud.asIterable()) {
  	
	String Name = (String) result.getProperty("name");
  	String roll_number = (String) result.getProperty("roll_number");
	String DOB = (String) result.getProperty("DOB");
  	
	out.println("<tr>");
        out.print("<td>"+Name+ "</td>");
        out.print("<td>"+roll_number+ "</td>");
        out.print("<td>"+DOB+ "</td>");         
        out.println("</tr>");	
    }    
    
    out.println("</table>");
    out.println("</CENTER>");
    out.println("</body></html>");

  }
}


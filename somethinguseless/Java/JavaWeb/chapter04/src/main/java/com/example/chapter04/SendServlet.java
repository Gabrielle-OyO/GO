//SendRedirect

package com.example.chapter04;

import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet(name = "SendServlet", value = "/send-servlet")
public class SendServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    private String message;

    public void init() {
        message = "SendServlet";
    }
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=utf-8");
        response.sendRedirect("index.jsp");         //重定向
//		response.sendRedirect("/test2/login.html");


        // Hello
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("<h1>" + message + "</h1>");
        out.println("</body></html>");
    }
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        // TODO Auto-generated method stub
        doGet(request, response);
    }







}


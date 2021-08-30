package com.example.ServleDemo;

import java.io.*;
import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet(name = "helloServlet", value = "/hello-servlet")
public class HelloServlet extends HttpServlet {
    private String message;

    public void init() {
        message = "Hello World!";
    }

    public void init(ServletConfig config)throws ServletException {
        System.out.println("init method is called");
    }


    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");

        // Hello   输出流Printer Writer对象，Servlet使用输出流来产生响应
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        //使用输出流对象向客户端发送字符串数据
        out.println("<h1>" + message + "</h1>");
        out.println("</body></html>");
    }

    public void destroy() {
        System.out.println("destroy method is called");
    }
}
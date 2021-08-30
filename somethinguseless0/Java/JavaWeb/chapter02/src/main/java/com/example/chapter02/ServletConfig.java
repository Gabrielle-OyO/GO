package com.example.chapter02;

import java.io.*;
import java.util.Enumeration;
import javax.servlet.Servlet;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet(name = "ServletConfig", value = "/ServletConfig")
public class ServletConfig extends HttpServlet {
    private String message;

    public void init() {
        message = "ServletConfig";
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html;charset=utf-8");
        // Hello
        PrintWriter out = response.getWriter();
        // 得到ServletContext对象
        ServletContext context = this.getServletContext();
        // 得到包含所有初始化参数名的Enumeration对象
        Enumeration<String> paramNames = context.getInitParameterNames();
        // 遍历所有的初始化参数名，得到相应的参数值并打印
        while (paramNames.hasMoreElements()) {
            String name = paramNames.nextElement();
            String value = context.getInitParameter(name);
            out.println(name + ":" + value);
            out.println("<br/>");
        }


        javax.servlet.ServletConfig config = this.getServletConfig();
        String param = config.getInitParameter("encoding");
        out.println("encoding=" + param);

        out.println("<html><body>");
        out.println("<h1>" + message + "</h1>");
        out.println("</body></html>");
    }



    protected void doPost(HttpServletRequest request,HttpServletResponse response)throws ServletException,IOException{
        this.doGet(request,response);
    }




    public void destroy() {
    }
}
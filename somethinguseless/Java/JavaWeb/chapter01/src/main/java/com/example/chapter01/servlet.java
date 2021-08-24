package com.example.chapter01;

import java.io.*;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet(name = "servlet", value = "/servlet")
public class servlet extends HttpServlet {
    private String message;

    public void init() {
        message = "Hello World!";
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        ServletContext context=this.getServletContext();


        //通过setAttribute()方法设置属性值
        context.setAttribute("data","this servlet save data");

        // Hello
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("<h1>" + message + "</h1>");
        out.println("</body></html>");
    }

    public void doPost(HttpServletRequest request,HttpServletResponse response)throws ServletException, IOException {
        this.doGet(request, response);
    }

    public void destroy() {
    }
}
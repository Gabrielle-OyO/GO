package com.example.chapter;

import java.io.*;
import javax.servlet.ServletContext;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet(name = "servlet02", value = "/servlet02")
public class servlet02 extends HttpServlet {
    private String message;

    public void init() {
        message = "servlet02";
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        ServletContext context=this.getServletContext();
//通过getAttribute()方法获取属性值
        String data=(String)context.getAttribute("data");
        out.println(data);

        // Hello

        out.println("<html><body>");
        out.println("<h1>" + message + "</h1>");
        out.println("</body></html>");
    }

    public void destroy() {
    }
}
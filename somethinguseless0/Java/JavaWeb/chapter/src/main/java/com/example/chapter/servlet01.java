package com.example.chapter;

import java.io.*;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet(name = "servlet01", value = "/servlet01")
public class servlet01 extends HttpServlet {
    private String message;

    public void init() {
        message = "servlet01";
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");
        ServletContext context=this.getServletContext();
        //通过setAttribute()方法设置属性值
        context.setAttribute("data","this servlet save data");

        // Hello
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("<h1>" + message + "</h1>");
        out.println("</body></html>");
    }
    public void doPost(HttpServletRequest request,HttpServletResponse response)throws ServletException, IOException{
        this.doGet(request,response);
    }
    public void destroy() {
    }
}
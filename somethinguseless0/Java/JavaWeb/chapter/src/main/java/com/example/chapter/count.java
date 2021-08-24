package com.example.chapter;


import java.io.*;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet(name = "count", value = "/count")
public class count extends HttpServlet {
    private String message;

    public void init() {
        message = "count";
    }



    private static final long serialVersionUID = 1L;
    protected void doGet(HttpServletRequest request,
                         HttpServletResponse response) throws ServletException, IOException {
        ServletContext context = getServletContext();
        Integer times = (Integer) context.getAttribute("times");
        if (times == null) {
            times = new Integer(1);
        } else {
            times = new Integer(times.intValue() + 1);
        }
        response.setContentType("text/html;charset=utf-8");
        PrintWriter out= response.getWriter();
        out.println("<html><head><title>");
        out.println("页面访问统计");
        out.println("</title></head><body>");
        out.println("当前页面被访问了");
        out.println("<font color=red size=20>"+times+"</font>次");
        context.setAttribute("times",times);


        out.println("<html><body>");
        out.println("<h1>" + message + "</h1>");
        out.println("</body></html>");
    }
    protected void doPost(HttpServletRequest request,
                          HttpServletResponse response) throws ServletException, IOException {
        this.doGet(request, response);
    }
}
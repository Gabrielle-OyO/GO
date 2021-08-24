package com.example.chapter04;

import java.io.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet(name = "refreshServlet", value = "/refresh-servlet")//添加姓名和值
public class RefreshServlet extends HttpServlet {
    private String message;

    public void init() {
        message = "refresh";
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");
        response.setHeader("Refresh","2;URL=http://baidu.com");//跳转链接

        // Hello
        PrintWriter out = response.getWriter();
        out.println("<html><body>");
        out.println("<h1>" + message + "</h1>");
        out.println("</body></html>");
    }

    public void destroy() {
    }
}


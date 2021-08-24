package com.example.chapter05;


import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "DownManagerServlet", value = "/DownManagerServlet")
public class DownManagerServlet extends HttpServlet {
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("/Down.jsp;charset=utf-8");
        PrintWriter out = response.getWriter();
        //获取referer头的值
        String referer = request.getHeader("referer");
        //获取访问地址
        String sitePart = "http://"+request.getServerName();
        //判断referer头是否为空，这个头的首地址是否以sitePart开始的
        if(referer !=null && referer.startsWith(sitePart))
        {
            //处理正在下载的请求
            out.println("dealing download~");
        }else
        {
            //非法下载请求跳转到down.html页面
            RequestDispatcher rd = request.getRequestDispatcher("/Down.jsp");
            rd.forward(request, response);
        }
    }
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
}

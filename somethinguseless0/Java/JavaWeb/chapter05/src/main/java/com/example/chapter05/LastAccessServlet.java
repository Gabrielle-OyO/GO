package com.example.chapter05;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Date;

@WebServlet(name = "LastAccessServlet", value = "/LastAccessServlet")
public class LastAccessServlet  extends HttpServlet {
    private static final long serialVersionUID=1L;
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=utf-8");
        /*
        设定一个 cookie 的name : lastAccessTime读取客户端发送cookie获得用户上次的访问时间显示
         */
        String lastAccessTime=null;
        Cookie[] cookies =request.getCookies();//获取所有的cookie，并将这些cookie存放在数组中
        for(int i=0;cookies != null && i < cookies.length;i++){
            if("lastAccess".equals(cookies[i].getName())){
                lastAccessTime=cookies[i].getValue();//如果cookie的名称为LastAccess，则获取该cookie的值
                break;
            }
        }
        //判断是否存在名称为lastAccess的cookie
        if (lastAccessTime == null) {
            response.getWriter().print("您是首次访问本站！");
        }else{
            response.getWriter().print("您上次的访问时间"+lastAccessTime);
        }
        //创建cookie，将当前时间作为cookie的值发送给客户端
        Cookie cookie = new Cookie("lastAccess", new Date().toString());   //new Date().toLocaleString()) 【用法过时】
        cookie.setMaxAge(60*30);//保存30min
        cookie.setPath("/");//访问chapter05下资源是会送cookie
        response.addCookie(cookie);//发送cookie
    }
}

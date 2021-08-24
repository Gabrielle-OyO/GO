package com.example.chapter05;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "PurchaseServlet", value = "/PurchaseServlet")
public class PurchaseServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;
    public void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        String id = req.getParameter("id");// 获得用户购买的商品
        if (id == null) {
            String url = "/chapter05/ListBookServlet";// 如果id为null，重定向到ListBookServlet页面
            resp.sendRedirect(url);
            return;
        }
        Book book = BookDB.getBook(id);
        HttpSession session = req.getSession();// 创建或者获得用户的Session对象
        List<Book> cart = (List) session.getAttribute("cart");// 从Session对象中获得用户的购物车
        if (cart == null) {
            cart = new ArrayList<Book>();// 首次购买，为用户创建一个购物车(List集合模拟购物车)
            //cart= new List<Book>();// 将购物城存入Session对象
            session.setAttribute("cart", cart);
        }
        cart.add(book);// 将商品放入购物车
        // 创建Cookie存放Session的标识号
        Cookie cookie = new Cookie("JSESSIONID", session.getId());
        cookie.setMaxAge(60 * 30);
        cookie.setPath("/");    //全目录访问
        resp.addCookie(cookie);
        // 重定向到购物车页面
        String url = "/chapter05/CartServlet";
        resp.sendRedirect(url);
    }
}


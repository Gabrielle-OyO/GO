package com.example.chapter05;

import javax.servlet.annotation.WebServlet;
import java.util.Collection;
import java.util.LinkedHashMap;
import java.util.Map;

@WebServlet(name = "BookDB", value = "/BookDB")
public class BookDB {
    private static Map<String,Book>books=new LinkedHashMap<String,Book>();
    static{
        books.put("1",new Book("1","javaWeb开发"));
        books.put("2",new Book("2","jdbc开发"));
        books.put("3",new Book("3","java基础"));
        books.put("4",new Book("4","struts开发"));
        books.put("5",new Book("5","spring开发"));
    }
    //获得所有的图书
    public static Collection<Book> getAll(){
        return books.values();
    }
    //根据指定的id获得图书
    public static Book getBook(String id){
        return books.get(id);
    }
}

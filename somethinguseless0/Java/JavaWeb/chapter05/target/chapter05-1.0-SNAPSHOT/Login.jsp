<%--
  Created by IntelliJ IDEA.
  User: 18377
  Date: 2021/4/27
  Time: 20:33
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>

<form action="/chapter05/LoginFormServlet" method="post">
    用户名：<input type="text" name="name"/><br/>
    密     码:<input type="password" name="pass"><br/>
    验证码：<input type="text" name="check_code"/>
    <img src="/chapter05/CodeServlet"/><br/>
    <input type="submit" name="登录"/>
</form>


</body>
</html>

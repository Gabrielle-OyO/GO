function stockinfo = queryprice(stocktype, stockid)
    %stocktype 股票类型：sh和sz
    %stockid 股票编码：
    url = sprintf('http://hq.sinajs.cn/list=%s%d', stocktype, stockid);
    [sourcefile, status] = welread(url);
    if (~status)
        disp('无法获取数据');
    else
        %取出字符串
        str = javaObject('java.lang.String', sourcefile);
        str = str.replaceAll('var ', '');
        strs = str.split('=');
        str = strs(2);
        str = str.replaceFirst('"', '{''');
        str = str.replaceFirst('"', '''};');
        str = str.replaceAll(',', ''', ''');
        str = strcat('stock=', char(str));
        eval(str);
        
        stockinfo = {};
        stockinfo.name = stock(1);
        stockinfo.today_start_price = str2double(stock(2));
        stockinfo.yestoday_end_price = str2double(stock(3));
        stockinfo.current_price = str2double(stock(4));
        
        stockinfo.today_highest_price = str2double(stock(5));
        stockinfo.today_lowest_price = str2double(stock(6));
        stockinfo.today_first_buy_price = str2double(stock(7));
        stockinfo.today_first_sale_price = str2double(stock(8));
        stockinfo.today_success_stock_mount = str2double(stock(9))/100;       %单位：手
        stockinfo.today_success_money = str2double(stock(10));                %单位：万
        stockinfo.today_first_buy_price = str2double(stock(11));
        stockinfo.today_first_sale_price = str2double(stock(12));
        
        stockinfo.buy_stock_mount1 = str2double(stock(13)) / 100;       %单位：手
        stockinfo.buy_stock_price1 = str2double(stock(14));             %单位：万
        stockinfo.buy_stock_mount2 = str2double(stock(15));
        stockinfo.buy_stock_price2 = str2double(stock(16));
        stockinfo.buy_stock_mount3 = str2double(stock(17));
        stockinfo.buy_stock_price3 = str2double(stock(18));
        stockinfo.buy_stock_mount4 = str2double(stock(19));
        stockinfo.buy_stock_price4 = str2double(stock(20));
        stockinfo.buy_stock_mount5 = str2double(stock(21));
        stockinfo.buy_stock_price5 = str2double(stock(22));
        
        stockinfo.sale_stock_mount1 = str2double(stock(23));
        stockinfo.sale_stock_price1 = str2double(stock(24));
        stockinfo.sale_stock_mount2 = str2double(stock(25));
        stockinfo.sale_stock_price2 = str2double(stock(26));
        stockinfo.sale_stock_mount3 = str2double(stock(27));
        stockinfo.sale_stock_price3 = str2double(stock(28));
        stockinfo.sale_stock_mount4 = str2double(stock(29));
        stockinfo.sale_stock_price4 = str2double(stock(30));
        
        stockinfo.date = stock(31);
        stockinfo.time = stock(32);
    end
 end
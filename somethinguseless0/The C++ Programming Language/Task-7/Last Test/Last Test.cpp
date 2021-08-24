#include<iostream>
using namespace std;

class Suggestions
{
private:
	char New_development_stage[200];
	char New_development_pattern[200];
	char New_development_contcept[200];
public:
	Suggestions(char stage[], char pattern[], char contcept[])
	{
		strcpy_s(New_development_stage, stage);
		strcpy_s(New_development_pattern, pattern);
		strcpy_s(New_development_contcept, contcept);
	}
	void Show()
	{
		cout << New_development_stage << endl;
		cout << New_development_pattern << endl;
		cout << New_development_contcept << endl;
	}

};

int main()
{
	char New_development_stage[200] = "全面建设社会主义现代化国家向第二个百年奋斗目标进军";
	char New_development_pattern[200] = "以国内大循环为主体、国内国际双循环相互促进";
	char New_development_contcept[200] = "创新、协调、绿色、开放、共享";

	Suggestions S( New_development_stage,  New_development_pattern,  New_development_contcept);
	S.Show();
	return 0;
}
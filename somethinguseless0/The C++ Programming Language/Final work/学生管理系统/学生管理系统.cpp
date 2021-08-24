#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<fstream>
int MAX = 0;
using namespace std;
//ѧ���ɼ�����ϵͳ
struct student
{
	string name;
	string ID;
	float math;
	float english;
	float physics;
	float sum;
};
class student_system
{
private:
	float average=0;
	float standard=0;
	float physics_average;
	float math_average;
	float english_average;
	float physics_standard = 0;
	float math_standard = 0;
	float english_standard = 0;
	float math_num;
	float physics_num;
	float english_num;
	float num;
	student h;
	vector <student>a = {50,h};
	int j = 0;
public:
	int g=0;
	void display();//�ļ����빦��
	void inputfile();//��Ϣ¼��
	void showfile();//��ʾ����
	void amendfile();//�޸Ĺ���
	void findfile();//Ѱ�ҹ���
	void dfindfile();//����Ѱ�ҹ���
	void deletefile();//ɾ������
	void Mfindfile();//ģ��Ѱ��
	void Ffindfile();//�ɼ���ΧѰ��
	void rankfile();//������
	void storefile();//�ļ�����洢
	void statistics();//ͳ�Ʒ�������
};
void student_system::statistics() {
	int n;
	do
	{
		cout << "��������Ҫͳ�ƵĿ�Ŀ��1����ѧ����2��Ӣ���3��������4���ܷ֣�";
		cin >> n;
		switch (n) {
		case 1:
			math_num = 0; math_standard = 0; math_average = 0;
			for (int i = 0; i < MAX + g; i++)
				math_average += a[i].math;
			math_average /= (MAX + g);
			for (int i = 0; i < MAX + g; i++)
				math_standard += (a[i].math - math_average)*(a[i].math - math_average);
			math_standard = sqrt(math_standard / (MAX + g));
			for (int i = 0; i < MAX + g; i++)
			{
				if (a[i].math >= 60)
					math_num++;
				else
					continue;
			}
			cout << "��ѧƽ����Ϊ��" << math_average << endl;
			cout<< "��ѧ��׼��Ϊ��" << math_standard << endl;
			cout << "��ѧ��������Ϊ��" << math_num << endl;
			 break;
		case 2:
			english_num = 0; english_standard = 0; english_average = 0;
			for (int i = 0; i < MAX + g; i++)
				english_average += a[i].english;
			english_average /= (MAX + g);
			for (int i = 0; i < MAX + g; i++)
				english_standard += (a[i].english - english_average) * (a[i].english - english_average);
			english_standard = sqrt(english_standard / (MAX + g));
			for (int i = 0; i < MAX + g; i++)
			{
				if (a[i].english >= 60)
					english_num++;
				else
					continue;
			}
			cout << "Ӣ��ƽ����Ϊ��" << english_average << endl;
			cout << "Ӣ���׼��Ϊ��" << english_standard << endl;
			cout << "Ӣ�Ｐ������Ϊ��" << english_num << endl;
		break;
		case 3:
			physics_num = 0; physics_standard = 0; physics_average = 0;
			for (int i = 0; i < MAX + g; i++)
				physics_average += a[i].physics;
			physics_average /= (MAX + g);
			for (int i = 0; i < MAX + g; i++)
				physics_standard += (a[i].physics - physics_average) * (a[i].physics - physics_average);
			physics_standard = sqrt(physics_standard / (MAX + g));
			for (int i = 0; i < MAX + g; i++)
			{
				if (a[i].physics >= 60)
					physics_num++;
				else
					continue;
			}
			cout << "����ƽ����Ϊ��" << physics_average << endl;
			cout << "�����׼��Ϊ��" << physics_standard << endl;
			cout << "����������Ϊ��" << physics_num << endl;
			break;
		case 4:
			num = 0; standard = 0; average = 0;
			for (int i = 0; i < MAX + g; i++)
				average += a[i].sum;
			average /= (MAX + g);
			for (int i = 0; i < MAX + g; i++)
				standard += (a[i].sum - average) * (a[i].sum - average);
			standard = sqrt(standard / (MAX + g));
			for (int i = 0; i < MAX + g; i++)
			{
				if (a[i].sum >= 180)
					num++;
				else
					continue;
			}
			cout << "��ƽ����Ϊ��" << average << endl;
			cout << "�ܱ�׼��Ϊ��" << standard << endl;
			cout << "��������Ϊ��" << num << endl;
		 break;
		default:
			break;
		}
		cout << "�ǣ�1����0������ͳ�ƣ�";
		cin >> n;
	} while (n);
}
//¼��ѧ����Ϣ
void student_system::inputfile()
{
	int o=1;
	j = MAX+g;
	while (o!=0)
	{
		cout << "������ѧ����ѧ�ţ�";
		cin >> a[j].ID;
		cout << "������ѧ��������";
		cin >> a[j].name;
		cout << "������ѧ������ѧ�ɼ���";
		cin >> a[j].math;
		cout << "������ѧ����Ӣ��ɼ���";
		cin >> a[j].english;
		cout << "������ѧ��������ɼ���";
		cin >> a[j].physics;
		a[j].sum = a[j].math + a[j].english + a[j].physics;
		cout << "�ǣ�1����0������¼�룺";
		cin >> o;
		j++; g++;
	}
}
//�ļ����
void student_system::storefile() {
	string filename;
	cout << "������洢ѧ����Ϣ���ļ�����";
	cin >> filename;
	ofstream outfile(filename.c_str(), ios::out);
	if (!outfile) {
		cerr << "open error!" << endl;
		exit(1);
	}
	else
		cout << "Store Success!"<<endl;
	    outfile<< "ѧ��" << "\t" << "\t" << "����" << "\t"  << "��ѧ" << "\t"  << "Ӣ��" << "\t" << "����" << "\t"<< "�ܷ�" << endl;
		for (int j = 0; j < MAX + g; j++) {
			outfile << a[j].ID << "\t" << a[j].name << "\t" << a[j].math << "\t" << a[j].english << "\t" << a[j].physics << "\t" << a[j].sum << endl;
		}
	outfile << "��Ŀ" << "\t"<< "ƽ����" << "\t" << "��׼��" << "\t" << "��������" << endl;
	outfile << "����" << "\t" << physics_average<<"\t" << physics_standard << "\t" <<physics_num<< endl;
	outfile << "Ӣ��" << "\t" << english_average << "\t" << english_standard << "\t" << english_num << endl;
	outfile << "��ѧ" << "\t" << math_average << "\t" << math_standard << "\t" << math_num << endl;
	outfile << "�ܷ�" << "\t" << average << "\t" << standard << "\t" << num << endl;
	outfile.close();
}
//�ļ�����
void student_system::display() {
	string b[50][5];
	string filename;
	cout << "��������Ҫ�򿪵�txt�ļ�:����ʽΪ:�ļ���+.txt��";
	cin >> filename;
	ifstream infile(filename.c_str(), ios::in);//�����ļ���Ϣ��ע���ļ������ǡ�f1�������Ҹ��ļ�Ҫ�浽�������ڵ��ļ�����
	if (!infile) {
		cerr << "Open Error!" << endl;//ֻ���ж��Ƿ����ɹ�
		return;
	}
	else
		cout << "Open Success!" << endl;
	/*for (int j = 0; j < MAX; j++) {
		infile >> a[j].ID >> a[j].name >> a[j].math >> a[j].english >> a[j].physics;
		a[j].sum = a[j].math + a[j].english + a[j].physics;
	}*/
	while (infile >> a[j].ID >> a[j].name >> a[j].math >> a[j].english >> a[j].physics)
	{
		a[j].sum = a[j].math + a[j].english + a[j].physics;
		MAX++;
		j++;
	}
}
//��ʾѧ����Ϣ
void student_system::showfile()
{
	cout << "���" << "\t" << "ѧ��" << "\t" << "\t" << "\t" << "����" << "\t" << "\t" << "��ѧ" << "\t" << "\t" << "Ӣ��" << "\t" "\t" << "����" << "\t""\t" << "�ܷ�" << endl;
	for (j = 0; j<MAX+g; j++)
	{
		a[j].sum = a[j].math + a[j].english + a[j].physics;
		cout << j + 1 << "\t" << a[j].ID << "\t" << "\t" << a[j].name << "\t" "\t" << a[j].math << "\t" << "\t" << a[j].english << "\t" << "\t" << a[j].physics << "\t" << "\t" << a[j].sum << endl;
	}
}
//�޸�ѧ����Ϣ
void student_system::amendfile()
{
	int n, k;
	cout << "��������Ҫ�Ķ�����Ϣ��Ӧ��ѧ����ţ�";
	cin >> j;
	j--;
	cout << j + 1 << "\t" << a[j].ID << "\t" << a[j].name << "\t" "\t" << a[j].math << "\t" << "\t" << a[j].english << "\t" << "\t" << a[j].physics << "\t" << "\t" << a[j].sum << endl;
	do
	{
		cout << "������Ķ�����(ѧ�š�0����������1������ѧ��2����Ӣ�3��������4��)��";
		cin >> k;
		switch (k)
		{
		case 0:
			cin >> a[j].ID; break;
		case 1:
			cin >> a[j].name; break;
		case 2:
			cin >> a[j].math; break;
		case 3:
			cin >> a[j].english; break;
		case 4:
			cin >> a[j].physics; break;
		}
		cout << j + 1 << "\t" << a[j].ID << "\t" << a[j].name << "\t" "\t" << a[j].math << "\t" << "\t" << a[j].english << "\t" << "\t" << a[j].physics << "\t" << "\t" << a[j].sum << endl;
		cout << "�޸ĳɹ����ǡ�1����0�������Ը�ѧ����Ϣ���иĶ���";
		cin >> n;
	} while (n != 0);
}
void student_system::findfile(){
	int n;
	cout << "��������ҷ�ʽ����1���������ң���2����Χ���ң���3��ģ�����ң�";
	cin >> n;
	switch (n) {
	case 1:
		dfindfile(); break;
	case 2:
		Ffindfile(); break;
	case 3:
		Mfindfile(); break;
	default:
		break;
	}
}
//ģ������ѧ����Ϣ
void student_system::Mfindfile() {
	char m[20];
	int n;
	int s[50];
	do {
		int z = 0;
		cout << "������ؼ��֣�";
		cin >> m;
		char* str = m;
		char h[7],H[20];
		for (int j = 0; j < MAX + g; j++)
		{
			string str2= a[j].name;
			string str3 = a[j].ID;
			str2.copy(h, 7, 0);
			*(h + strlen(h)) = '\0';
			str3.copy(H, 20, 0);
			*(H + strlen(H)) = '\0';
			char* str1 = h;
			char* str4 = H;
			if (strstr(str1, str) != NULL|| strstr(str4, str) != NULL) {
				s[z] = j; z++;
				cout << a[j].ID << "\t" << a[j].name << "\t" "\t" << a[j].math << "\t" << "\t" << a[j].english << "\t" << "\t" << a[j].physics << "\t" << "\t" << a[j].sum << endl;
			}
			else
				continue;
		}
			cout << "�˳�������0���������β����밴1";
			cin >> n;
			if (n == 1)
			{
				cout << "������ؼ��֣�";
				cin >> m;
				for (int i = 0; i < z; i++)
				{
					j = s[i];
					string str2 = a[j].name;
					string str3 = a[j].ID;
					str2.copy(h, 7, 0);
					*(h + strlen(h)) = '\0';
					str3.copy(H, 20, 0);
					*(H + strlen(H)) = '\0';
					char* str1 = h;
					char* str4 = H;
					if (strstr(str1, str) != NULL || strstr(str4, str) != NULL) {
						cout << a[j].ID << "\t" << a[j].name << "\t" "\t" << a[j].math << "\t" << "\t" << a[j].english << "\t" << "\t" << a[j].physics << "\t" << "\t" << a[j].sum << endl;
					}
					else
						continue;
				}
			}
			cout << "�˳�������0������ʹ�ò��ҹ����밴1";
			cin >> n;
	} while (n);
}
//��Χ����ѧ����Ϣ
void student_system::Ffindfile() {
	int n;
	cout << "��������ҵ���Ϣ:��1���ܷ֣���2����ѧ����3��Ӣ���4������";
	cin >> n;
	int max, min;
	cout << "�����������Сֵ�����ֵ��";
	cin >> min >> max;
	switch (n)
	{
	case 1:
		cout << "ѧ��" << "\t" << "\t" << "����" << "\t" << "\t" << "��ѧ" << "\t" << "\t" << "Ӣ��" << "\t" "\t" << "����" << "\t" "\t" << "�ܷ�" << endl;
		for (int j = 0; j < MAX + g; j++)
			if (a[j].sum >= min && a[j].sum <= max)
			{
				cout << a[j].ID << "\t" << a[j].name << "\t" "\t" << a[j].math << "\t" << "\t" << a[j].english << "\t" << "\t" << a[j].physics << "\t" << "\t" << a[j].sum << endl;
			}break;
	case 2:
		cout << "ѧ��" << "\t" << "\t" << "����" << "\t" << "\t" << "��ѧ" << "\t" << "\t" << "Ӣ��" << "\t" "\t" << "����" << "\t" "\t" << "�ܷ�" << endl;
		for (int j = 0; j < MAX + g; j++)
			if (a[j].math >= min && a[j].math <= max)
			{
				cout << a[j].ID << "\t" << a[j].name << "\t" "\t" << a[j].math << "\t" << "\t" << a[j].english << "\t" << "\t" << a[j].physics << "\t" << "\t" << a[j].sum << endl;
			}break;
	case 3:
		cout << "ѧ��" << "\t" << "\t" << "����" << "\t" << "\t" << "��ѧ" << "\t" << "\t" << "Ӣ��" << "\t" "\t" << "����" << "\t" "\t" << "�ܷ�" << endl;
		for (int j = 0; j < MAX + g; j++)
			if (a[j].english >= min && a[j].english <= max)
			{
				cout << a[j].ID << "\t" << a[j].name << "\t" "\t" << a[j].math << "\t" << "\t" << a[j].english << "\t" << "\t" << a[j].physics << "\t" << "\t" << a[j].sum << endl;
			}break;
	case 4:
		cout << "ѧ��" << "\t" << "\t" << "����" << "\t" << "\t" << "��ѧ" << "\t" << "\t" << "Ӣ��" << "\t" "\t" << "����" << "\t" "\t" << "�ܷ�" << endl;
		for (int j = 0; j < MAX + g; j++)
			if (a[j].physics >= min && a[j].physics <= max)
			{
				cout << a[j].ID << "\t" << a[j].name << "\t" "\t" << a[j].math << "\t" << "\t" << a[j].english << "\t" << "\t" << a[j].physics << "\t" << "\t" << a[j].sum << endl;
			}break;
	default:
		break;
	}
}
//��������ѧ����Ϣ
void student_system::dfindfile()
{
	int n=1;
	string name,ID1;
	int find;
	cout << "ѧ����š�1����ѧ�š�2������������3����";
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "������ѧ����ţ�";
		cin >> find;
		j = find - 1;
		break;
	case 2:
		cout << "������ѧ��ѧ�ţ�";
		cin >> ID1;
		for (int i = 0; i < MAX + g; i++)
		{
			if (a[i].ID == ID1)
			{
				j = i;
				break;
			}
			else if (a[i].ID != ID1 && i < MAX + g - 1)
				continue;
			else
			{
				cout << "�޴�ѧ�ţ����������룺";
				cin >> ID1;
				i = -1;
			}
		}break;
	case 3:
		cout << "������ѧ��������";
		cin >> name;
		for (int i = 0; i < MAX + g; i++)
		{
			if (a[i].name == name)
			{
				j = i;
				break;
			}
			else if (a[i].name != name && i < MAX + g - 1)
				continue;
			else
			{
				cout << "�޴��ˣ����������룺";
				cin >> name;
				i = -1;
			}
		}
		break;
	default:
		break;
	}
	cout << "���" << "\t" << "ѧ��" << "\t" << "\t" << "����" << "\t" << "\t" << "��ѧ" << "\t" << "\t" << "Ӣ��" << "\t" "\t" << "����" << "\t" "\t" << "�ܷ�" << endl;
	cout << j + 1 << "\t" << a[j].ID << "\t" << a[j].name << "\t" "\t" << a[j].math << "\t" << "\t" << a[j].english << "\t" << "\t" << a[j].physics << "\t" << "\t" << a[j].sum << endl;
}
//ɾ��ѧ����Ϣ
void student_system::deletefile()
{
	int find;
	do {
		cout << "��������Ҫɾ����ѧ����Ϣ��Ӧ����ţ�";
		cin >> find;
		j = find - 1;
		cout << j + 1 << "\t" << a[j].ID << "\t" << a[j].name << "\t" "\t" << a[j].math << "\t" << "\t" << a[j].english << "\t" << "\t" << a[j].physics << "\t" << "\t" << a[j].sum << endl;
		cout << "�Ƿ�ȷ��ɾ����ѧ����Ϣ��1���ǣ���0����";
		cin >> find;
		for (int i = j; i < MAX + g - 1; i++)
			a[i] = a[i + 1];
		g = g - 1;
		cout << "�Ƿ����ɾ��ѧ����Ϣ����1���ǣ���0����";
		cin >> find;
	} while (find != 0);
}
//�ɼ�������
void change(student&a1,student&a2) {
	student b;
	b = a1;
	a1= a2;
	a2 = b;
}
void student_system::rankfile()
{
	int num;
	int N = 1;
	cout << "��ѡ������ʽ����0���ܳɼ�����1����ѧ�ɼ�����2��Ӣ��ɼ�����3������ɼ���" << endl;
	cin >> num;
	student b;
	switch (num)
	{
	case 0:
		for (int i = 0; i < MAX + g; i++)
			for (int j = MAX + g - 1; j > i; j--)
				if (a[i].sum < a[j].sum)
					change(a[i], a[j]);
				else if (a[i].sum == a[j].sum)
					if (a[i].math < a[j].math)
						change(a[i], a[j]);
					else if (a[i].math == a[j].math)
						if (a[i].physics < a[j].physics)
							change(a[i], a[j]);
		break;
	case 1:
		for (int i = 0; i < MAX + g; i++)
			for (int j = MAX + g - 1; j > i; j--)
				if (a[i].math < a[j].math)
					change(a[i], a[j]);
		break;
	case 2:
		for (int i = 0; i < MAX + g; i++)
			for (int j = MAX + g - 1; j > i; j--)
				if (a[i].english < a[j].english)
					change(a[i], a[j]);
		break;
	case 3:
		for (int i = 1; i < MAX + g; i++)
			for (int j = MAX + g - 1; j > i; j--)
				if (a[i].physics < a[j].physics)
					change(a[i], a[j]); break;
	default:
		break;
	}
	cout << "����ɹ���" << endl;
}
int main()
{
	int n,i=1;
	student_system s;
	do
	{
		cout << "��1��¼��ѧ����Ϣ" << endl;
		cout << "��2����ʾѧ����Ϣ" << endl;
		cout << "��3���޸�ѧ����Ϣ" << endl;
		cout << "��4������ѧ����Ϣ" << endl;
		cout << "��5��ɾ��ѧ����Ϣ" << endl;
		cout << "��6��ѧ����Ϣ�ļ�" << endl;
		cout << "��7���ɼ�������" << endl;
		cout << "��8���������ļ�" << endl;
		cout << "��9��ͳ�Ʒ����ɼ�" << endl;
		cout << "��ѡ���ܣ�";
		cin >> n;
		switch (n)
		{
		case 1:
			s.inputfile(); break;
		case 2:
			s.showfile(); break;
		case 3:
			s.amendfile(); break;
		case 4:
			s.findfile(); break;
		case 5:
			s.deletefile(); break;
		case 6:
			s.display(); break;
		case 7:
			s.rankfile(); break;
		case 8:
			s.storefile(); break;
		case 9:
			s.statistics(); break;
		}
		cout << "����ʹ�ø�ϵͳ������1���˳�������0:";
		cin >> i;
		system ("cls");
	} while (i != 0);
	return 0;
}


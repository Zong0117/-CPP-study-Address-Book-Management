#include <iostream>
using namespace std;
void showMenu()//主菜单
{
    cout << "***********************************" << endl;
    cout << "***********************************" << endl;
    cout << "*****  输入（1）：添加联系人  *****" << endl;
    cout << "*****  输入（2）：显示联系人  *****" << endl;
    cout << "*****  输入（3）：删除联系人  *****" << endl;
    cout << "*****  输入（4）：查找联系人  *****" << endl;
    cout << "*****  输入（5）：修改联系人  *****" << endl;
    cout << "*****  输入（6）：清除联系人  *****" << endl;
    cout << "*****  输入（0）：退出通讯录  *****" << endl;
    cout << "***********************************" << endl;
    cout << "***********************************" << endl;
};

struct People {//人结构体
    string m_name;
    int m_sex;
    int m_age;
    string m_numb;
    string m_address;
};

    
#define max 1000
struct Addressbook//通讯录结构体
{
    People peopleArray[max];//通讯录数组
    int m_size;//通讯录长度
};

void addPeople(Addressbook * abs) //添加联系人函数
{
    if (abs->m_size == max)//判断通讯录是否已满
    {
        cout << "人数已满" << endl;
        return;//满了不能添加 返回
    }
    else
    {
        //储存姓名
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->peopleArray[abs->m_size].m_name = name;

        //储存性别
        cout << "性别 1男 2女" << endl;
        int sex = 0;
        while (true) {//死循环
            cin >> sex;
            if (sex == 1 || sex == 2)//输入正确跳出死循环
            {
                abs->peopleArray[abs->m_size].m_sex = sex;
                break;
            }
            else 
            {
                cout << "输入有误 请重新输入" << endl;
            }
        }

        //储存年龄
        cout << "请输入年龄" << endl;
        int age;
        cin >> age;
        abs->peopleArray[abs->m_size].m_age = age;

        //储存电话
        cout << "请输入电话" << endl;
        string numb;
        cin >> numb;
        abs->peopleArray[abs->m_size].m_numb = numb;

        //储存地址
        cout << "请输入地址" << endl;
        string address;
        cin >> address;
        abs->peopleArray[abs->m_size].m_address = address;

        abs->m_size++;
        
    }
    system("pause");//任意键继续
    system("cls");//清屏

}

void showPeople(Addressbook * abs) //显示联系人函数
{
    if (abs->m_size == 0) 
    {
        cout << "没有联系人" << endl;
        
    }
    else //有联系人就输出
    {
        for (int i = 0; i < abs->m_size; i++) 
        {
            cout << "姓名:" << abs->peopleArray[i].m_name << "    "
                 << "性别:" << (abs->peopleArray[i].m_sex == 1 ? "男":"女") << "    "
                 << "年龄:" << abs->peopleArray[i].m_age << "    "
                 << "电话:" << abs->peopleArray[i].m_numb << "    "
                 << "地址:" << abs->peopleArray[i].m_address << "    "
                 << endl;
        }
    }
    system("pause");//按任意键继续
        system("cls");//清屏
}
int check(Addressbook* abs, string name) //检测联系人是否存在
{
    
    for (int i = 0; i < abs->m_size; i++) //遍历通讯录
    {
        if (name == abs->peopleArray[i].m_name) //如果找到返回下标
        {
            return i;
        }     
    }
    return -1;//没找到返回-1
}
void delPeople(Addressbook * abs) //删除联系人函数
{
    cout << "请输入要删除的联系人姓名" << endl;
    string delfindname;
    cin >> delfindname;
    int ret = check(abs, delfindname);//调用check函数 接收返回值
    if (ret != -1) //找到了进行删除
    {
        for (int i = 0; i < abs->m_size; i++) //遍历联系人 后一个覆盖当前一个
        {
            abs->peopleArray[i] = abs->peopleArray[i + 1];
        }
        abs->m_size--;//删除完成 减去一个长度
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "没有此联系人" << endl;
    }
    system("pause");
    system("cls");
}

void findPeople(Addressbook * abs) //查找联系人函数
{
    cout << "请输入需要查找的联系人" << endl;
    string findname;
    cin >> findname;
    int ret = check(abs, findname);//同删除联系人一样
        if (ret != -1) //找到输出
        {
            cout << "姓名:" << abs->peopleArray[ret].m_name << "    "
                << "性别:" << (abs->peopleArray[ret].m_sex == 1 ? "男" : "女") << "    "
                << "年龄:" << abs->peopleArray[ret].m_age << "    "
                << "电话:" << abs->peopleArray[ret].m_numb << "    "
                << "地址:" << abs->peopleArray[ret].m_address << "    "
                << endl;
        }
        else 
        {
            cout << "查无此人" << endl;
        }
        system("pause");
        system("cls");
}
void changePeople(Addressbook * abs) //更换联系人函数
{
    while (true)//死循环
    {   
        cout << "取消修改输入‘y’，不取消输入’x‘" << endl;//取消修改
        char exitchange;
        cin >> exitchange;
        if (exitchange != 'x')//不取消进入程序
        {   
            cout << "请输入要修改的联系人" << endl;
            string changename;
            cin >> changename;
            int ret = check(abs, changename);
            if (ret != -1) //找到输出
            {
                cout << "姓名:" << abs->peopleArray[ret].m_name << "    "
                    << "性别:" << (abs->peopleArray[ret].m_sex == 1 ? "男" : "女") << "    "
                    << "年龄:" << abs->peopleArray[ret].m_age << "    "
                    << "电话:" << abs->peopleArray[ret].m_numb << "    "
                    << "地址:" << abs->peopleArray[ret].m_address << "    "
                    << endl;
                cout << "确定要修改此联系人吗？ y/n" << endl;//询问是否修改
                char select;
                cin >> select;
                if (select == 'y')
                {
                    string newname;
                    int newsex;
                    int newage;
                    string newnumb;
                    string newaddress;
                    //修改名字
                    cout << "请输入修改的名字" << endl;
                    cin >> newname;
                    abs->peopleArray[ret].m_name = newname;
                    //修改性别
                    cout << "请输入修改的性别" << endl;
                    cin >> newsex;
                    abs->peopleArray[ret].m_sex = newsex;
                    //修改年龄
                    cout << "请输入修改的年龄" << endl;
                    cin >> newage;
                    abs->peopleArray[ret].m_age = newage;
                    //修改电话
                    cout << "请输入修改的电话" << endl;
                    cin >> newnumb;
                    abs->peopleArray[ret].m_numb = newnumb;
                    //修改地址
                    cout << "请输入修改的地址" << endl;
                    cin >> newaddress;
                    abs->peopleArray[ret].m_address = newaddress;
                    cout << "修改后为：" << endl;
                    cout << "姓名:" << abs->peopleArray[ret].m_name << "    "
                        << "性别:" << (abs->peopleArray[ret].m_sex == 1 ? "男" : "女") << "    "
                        << "年龄:" << abs->peopleArray[ret].m_age << "    "
                        << "电话:" << abs->peopleArray[ret].m_numb << "    "
                        << "地址:" << abs->peopleArray[ret].m_address << "    "
                        << endl;
                    break;//跳出当前循环
                }
                else
                {
                    continue;//跳过下面进入下一循环
                }
            }
            else
            {
                cout << "查无此人" << endl;
            } 
        } break;
    }
    system("pause");//按任意键继续
    system("cls");//清屏
}
void emptyPeople(Addressbook * abs) 
{
    char select;
    cout << "您确定要删库吗？ y/n " << endl;
    cin >> select;
    if (select == 'y')
    {
        abs->m_size = 0;
        cout << "删库成功" << endl;
        
    }
    else 
    {
        cout << "已取消" << endl;
        
    }
    system("pause");//按任意键继续
    system("cls");//清屏
}

int main()
{
    Addressbook abs;//创建结构体对象
    abs.m_size = 0;//初始化通讯录为0
    int celect = 0;
    while (true) 
    {
        showMenu();
        cout << "程序开始 请按提示输入" << endl;
        cin >> celect;
        switch (celect)
        {
        case 1://添加
            addPeople(&abs);
            break;
        case 2://显示
            showPeople(&abs);
            break;
        case 3://删除
            delPeople(&abs);
            break;
        case 4://查找
            findPeople(&abs);
            break;
        case 5://修改
            changePeople(&abs);
            break;
        case 6://删库跑路
            emptyPeople(&abs);
            break;
        case 0://退出
            cout << "程序结束" << endl;
            system("pause");
            return 0;
            
        }
    
    }
    
}

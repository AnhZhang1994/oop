#include "info.h"


vector<Info> per;
int Info::count = 0;


int Info::GetId()
{
    return id;
}


void Info::SetName()
{
    cout << "name：";
    cin >> name;
}
string Info::GetName() const
{
    string tmp = name;
    return tmp;
}


void Info::SetTel()
{
    cout << "tel：";
    cin >> tel;
}
string Info::GetTel() const
{
    string tmp = tel;
    return tmp;
}


void Info::SetAddr()
{
    cout << "address：";
    cin >> addr;
}
string Info::GetAddr() const
{
    string tmp = addr;
    return tmp;
}


Info::Info()
{


}


Info::~Info()
{


}


void Info::insert()
{
    Info tmp;
    vector<Info>::iterator it;
loop:
    count++;
    cout << "ID: " << count << endl;
    tmp.SetName();
    for (it = per.begin(); it != per.end(); ++it)
    {
        if (!((it->GetName()).compare(tmp.GetName())))
        {
            cout << "an existing name,input again" << endl;
            count--;
            goto loop;
        }
    }
    tmp.SetTel();
    tmp.SetAddr();
    tmp.id = count;

    per.push_back(tmp);


    cout << "continue to add contact? y/n ：";
    char ch;
    cin >> ch;
    if ('y' == ch || 'Y' == ch)
    {
        goto loop;
    }

}


void Info::show()
{
    vector<Info>::iterator it;
    if (per.empty())
    {
        cout << "invalid name" << endl;
    }
    else
    {
        for (it = per.begin(); it != per.end(); ++it)
        {
            cout << "ID: " << it->GetId() << endl;
            cout << "name：" << it->GetName() << endl;
            cout << "TEL：" << it->GetTel() << endl;
            cout << "address：" << it->GetAddr() << endl;
        }
        cout << "press any key to exit" << endl;
        char ch;
        cin >> ch;
    }
}


void Info::search()
{
    vector<Info>::iterator it;
    if (per.empty())
    {
        cout << "invalid name" << endl;
    }
    else
    {
    search_loop:
        int tp = 0; //ways to serach
        int num = 0; //serach id
        string tn; //search name
        int flag = 0; //search successfully or not
        cout << "search method：1.ID 2.name" << endl;
        cin >> tp;
        if (1 == tp)
        {
            cout << "please input the ID you want to search：";
            cin >> num;
            for (it = per.begin(); it != per.end(); ++it)
            {
                if (it->GetId() == num)
                {
                    flag = 1;
                    cout << "the person you want to search is：" << endl;
                    cout << "ID: " << it->GetId() << endl;
                    cout << "name：" << it->GetName() << endl;
                    cout << "TEL：" << it->GetTel() << endl;
                    cout << "address：" << it->GetAddr() << endl;
                }
            }
        }
        else if (2 == tp)
        {
            cout << "please input the name you want to search：";
            cin >> tn;
            for (it = per.begin(); it != per.end(); ++it)
            {
                if (!((it->GetName()).compare(tn)))
                {
                    flag = 1;
                    cout << "the person you want to search is：" << endl;
                    cout << "ID: " << it->GetId() << endl;
                    cout << "name：" << it->GetName() << endl;
                    cout << "TEL：" << it->GetTel() << endl;
                    cout << "address：" << it->GetAddr() << endl;
                }
            }
        }
        else
        {
            cout << "invalid way,please choose again" << endl;
            goto search_loop;
        }


        if (0 == flag)
        {
            cout << "invalid person" << endl;
        }
        else
        {
            cout << "search successfully" << endl;
        }
        cout << "press any key to exit" << endl;
        char ch;
        cin >> ch;
    }

}


void Info::delete_info()
{
    vector<Info>::iterator it;
    if (per.empty())
    {
        cout << "invalid person" << endl;
    }
    else
    {
    delete_loop:
        int tp = 0; //way to delete
        int num = 0; //id which is deleted
        string tn; //name which is deleted
        int flag = 0; //delete successfully or not
        cout << "delete method：1.ID 2.name" << endl;
        cin >> tp;
        if (1 == tp)
        {
            cout << "please input the ID you want to delete：";
            cin >> num;
            for (it = per.begin(); it != per.end();)
            {
                if (it->GetId() == num)
                {
                    flag = 1;
                    cout << "the person you want to delete is：" << endl;
                    cout << "ID: " << it->GetId() << endl;
                    cout << "name：" << it->GetName() << endl;
                    cout << "TEL：" << it->GetTel() << endl;
                    cout << "address：" << it->GetAddr() << endl;

                    cout << "are you sure？y/n : ";
                    char ch1;
                    cin >> ch1;
                    if (ch1 == 'y' || ch1 == 'Y')
                    {
                        it = per.erase(it);
                    }
                }
                else
                {
                    ++it;
                }
            }
        }
        else if (2 == tp)
        {
            cout << "please input the name you want to delete：";
            cin >> tn;
            for (it = per.begin(); it != per.end(); )
            {
                if (!((it->GetName()).compare(tn)))
                {
                    flag = 1;
                    cout << "the person you want to delete is：" << endl;
                    cout << "ID: " << it->GetId() << endl;
                    cout << "name：" << it->GetName() << endl;
                    cout << "TEL：" << it->GetTel() << endl;
                    cout << "address：" << it->GetAddr() << endl;

                    cout << "are you sure？y/n : ";
                    char ch1;
                    cin >> ch1;
                    if (ch1 == 'y' || ch1 == 'Y')
                    {
                        it = per.erase(it);
                    }
                }
                else
                {
                    ++it;
                }
            }
        }
        else
        {
            cout << "invalid way,please choose again." << endl;
            goto delete_loop;
        }


        if (0 == flag)
        {
            cout << "invalid person" << endl;
        }
        else
        {
            cout << "delete successfully" << endl;
        }
        cout << "press any key to exit" << endl;
        char ch;
        cin >> ch;
    }

}
void Info::modify()
{
    vector<Info>::iterator it;
    if (per.empty())
    {
        cout << "invalid person！" << endl;
    }
    else
    {
    modify_loop:
        string tn;
        int flag2 = 0;
        int flag = 0; //修改对象查找成功与否标志位
        cout << "please input the name you want to modify：";
        cin >> tn;
        for (it = per.begin(); it != per.end(); )
        {
            if (!((it->GetName()).compare(tn)))
            {
                flag = 1;
                cout << "the person you want to modify is：" << endl;
                cout << "ID: " << it->GetId() << endl;
                cout << "name：" << it->GetName() << endl;
                cout << "TEL：" << it->GetTel() << endl;
                cout << "address：" << it->GetAddr() << endl;

                cout << "are you sure？y/n : ";
                char ch1;
                cin >> ch1;
                char ch2;
                if (ch1 == 'y' || ch1 == 'Y')
                {
                    cout << "which part do you want to modify?：1.name 2.TEL 3.address：";
                    cin >> ch2;
                    switch (ch2)
                    {
                    case '1':
                    {
                        it->SetName();
                        cout << "modify successfully！now the information is：" << endl;
                        cout << "ID: " << it->GetId() << endl;
                        cout << "name：" << it->GetName() << endl;
                        cout << "TEL：" << it->GetTel() << endl;
                        cout << "address：" << it->GetAddr() << endl;
                        flag2 = 1;
                        break;
                    }
                    case '2':
                    {
                        it->SetTel();
                        cout << "modify successfully！now the information is：" << endl;
                        cout << "ID: " << it->GetId() << endl;
                        cout << "name：" << it->GetName() << endl;
                        cout << "TEL：" << it->GetTel() << endl;
                        cout << "address：" << it->GetAddr() << endl;
                        flag2 = 1;
                        break;
                    }
                    case '3':
                    {
                        it->SetAddr();
                        cout << "modify successfully！now the information is：" << endl;
                        cout << "ID: " << it->GetId() << endl;
                        cout << "name：" << it->GetName() << endl;
                        cout << "TEL：" << it->GetTel() << endl;
                        cout << "address：" << it->GetAddr() << endl;
                        flag2 = 1;
                        break;
                    }
                    default:
                    {
                        cout << "error！" << endl;
                        break;
                    }
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                ++it;
            }
        }
        if (0 == flag)
        {
            cout << "invalid person" << endl;
        }
        if (1 == flag2)
        {
            cout << "modify successfully!" << endl;
        }
        cout << "press any key to exit" << endl;
        char ch3;
        cin >> ch3;
    }
}




void Info::exit_info()
{
    cout << "are you sure？y/n: ";
    char ch1;
    cin >> ch1;
    if (ch1 == 'y' || ch1 == 'Y')
    {
        exit(1);
    }


}


void Info::choose()
{
    char action;
    Info tmp;
    cout << "please input the function you want to use：";
    cin >> action;


    switch (action)
    {
    case '1':
    {
        tmp.insert();
        tmp.interface();
        choose();
        break;
    }
    case '2':
    {
        tmp.show();
        tmp.interface();
        choose();
        break;
    }
    case '3':
    {
        tmp.delete_info();
        tmp.interface();
        choose();
    }
    case '4':
    {
        tmp.search();
        tmp.interface();
        choose();
        break;
    }
    case '5':
    {
        tmp.modify();
        tmp.interface();
        choose();
        break;
    }
    case '6':
    {
        tmp.exit_info();
        break;
    }
    default:
    {
        cout << "invalid command, please input again" << endl;
        choose();
        break;
    }
    }
}




void Info::interface()
{
   


    
        cout << "1.add contact" << endl;
        cout << "2.show contacts" << endl;
        cout << "3.delete contact" << endl;
        cout << "4.serch contact" << endl;
        cout << "5.modify contact" << endl;
        cout << "6.exit" << endl;
    



}
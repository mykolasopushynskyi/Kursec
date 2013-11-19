#include "accountmanager.h"

AccountManager::AccountManager(QObject *parent) :
    QObject(parent)
{
    accounts.append(* new UserAccount(new User("000001","1111"),"000001",1000));
    accounts.append(* new UserAccount(new User("000002","1111"),"000002",0));
    accounts.append(* new UserAccount(new User("000003","1111"),"000003",1000));
    accounts.append(* new UserAccount(new User("000004","1111"),"000004",0));
    accounts.append(* new UserAccount(new User("000005","1111"),"000005",1000));
    accounts.append(* new UserAccount(new User("000006","1111"),"000006",0));
    accounts.append(* new UserAccount(new User("000007","1111"),"000007",1000));
    accounts.append(* new UserAccount(new User("000008","1111"),"000008",0));
}

QString AccountManager::checkMoney(QString id, QString pin)
{
    UserAccount* ac = findAccount(id);

    if(ac)
    {
        if(ac->checkPin(pin))
        {
            return "Сума на рахунку " + QString::number(ac->obtainSum());
        }
        else
        {
            return "Неправильний пін-код";
        }
    }
    else
    {
        return "Немає акаунту" + id;
    }
}

QString AccountManager::getMoney(QString id, QString pin, QString val)
{
    UserAccount* ac = findAccount(id);

    if(ac)
    {
        if(ac->checkPin(pin))
        {
            if(ac->canGet(val.toLong()))
            {
                ac->get(val.toLong());
                return "Зняття суми на " + val + "грн. успішне";
            }
            else
            {
                return "недостатньо коштів для зняття суми";
            }

        }
        else
        {
            return "Неправильний пін-код";
        }
    }
    else
    {
        return "Немає акаунту" + id;
    }
}

QString AccountManager::putMoney(QString id, QString pin, QString val)
{
    UserAccount* ac = findAccount(id);

    if(ac)
    {
        if(ac->checkPin(pin))
        {
            ac->add(val.toLong());
            return "Пововнення суми на " + val + "грн. успішне";
        }
        else
        {
            return "Неправильний пін-код";
        }
    }
    else
    {
        return "Немає акаунту" + id;
    }
}

QString AccountManager::payMoney(QString id, QString pin, QString val, QString id2)
{
    UserAccount* ac = findAccount(id);
    UserAccount* pa = findAccount(id2);

    if(ac != 0 && pa != 0)
    {
        if(ac->checkPin(pin))
        {
            if(ac->canGet(val.toLong()))
            {
                pa->add(ac->get(val.toLong()));
                return "Переведенн суми " + val + "грн. на рахунок" + id2 + " успішне";
            }
            else
            {
                return "недостатньо коштів для оплати";
            }
        }
        else
        {
            return "Неправильний пін-код";
        }
    }
    else
    {
        return "Немає акаунту " + id + " або " + id2;
    }
}

UserAccount* AccountManager::findAccount(QString id)
{
    UserAccount* result = 0;
    for(int i = 0; i < accounts.size(); i++)
    {
        if(accounts[i].getId() == id)
        {
            result = &accounts[i];
            break;
        }
    }

    return result;
}

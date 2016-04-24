#include "computer.h"

Computer::Computer(QObject *parent) : QObject(parent)
{

}

QString Computer::toJson()
{
    //TODO

    QJsonArray arr;
    for (int i = 0; i < hardware.size(); i++){
        QJsonObject cObj;
        cObj["itemId"] = hardware.at(i)->getId();
        arr.append(cObj);
    }
    QJsonDocument doc(arr);
    return doc.toJson(QJsonDocument::Compact);
}

void Computer::addHardware(Item *itm)
{
    hardware.append(itm);
}

void Computer::delHardware(Item *itm)
{
    hardware.removeOne(itm);
}

void Computer::delHardware(int id)
{
    for (int i = 0; i < hardware.size(); i++){
        if(hardware.at(i)->getId() == id){
            hardware.removeOne(hardware.at(i));
            break;
        }
    }
}

/*void Computer::checkCompability(Item *itm)
{
    //TODO
}*/

double Computer::recountPrice()
{
    double ret = 0.0;
    for(int i = 0; i < hardware.size(); i++){
        ret += hardware.at(i)->getPrice();
    }
    return ret;
}

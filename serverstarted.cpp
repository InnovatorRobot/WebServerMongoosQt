#include "serverstarted.h"
#include <QDebug>

ServerStarted::ServerStarted()
{

}

void ServerStarted::DateTime(Request &request, JsonResponse &response)
{
    reader.parse(request.getData(), root );
    DateTimeValue = root["DateTime"];
    if (!DateTimeValue.isNull()) {
        QProcess *myprocess = new QProcess;
        myprocess->start("date",QStringList()<<"-s"<<QString::fromStdString(DateTimeValue.asString()));
        myprocess->waitForFinished();
        delete myprocess;
        response[ResultHeader] = Successful;
    }
    else
    {
        response.setCode(400);
        response[ResultHeader] = SetDateTimeError;
    }
}


void ServerStarted::Data_Collection_AcoordingTime(Request &request, JsonResponse &response)
{
    reader.parse(request.getData(), root );
    StartDateTime = root[StartDateTimeHeader];
    EndDateTime = root[EndDateTimeHeader];

    for (int index=0;index < 5;index++)
        {
            response[DataHeader][index][EmpNoHeader] = "9092";
            response[DataHeader][index][SubmittedDateHeader] = "2019-10-10";
            response[DataHeader][index][DeviceNumHeader] = "100";
            response[DataHeader][index][StatusHeader] = "OK";
            response[DataHeader][index][DirectionHeader] = "1";
        }
}




void ServerStarted::SendDeviceInfo(Request &request, JsonResponse &response)
{
    response["OrgCode"] = "OrgCode";
    response["OrgName"] = "OrgName";
    response["LogoIsVisible"] = "LogoIsVisible";
    response["CamerIsVisible"] = "CamerIsVisible";
    response["SoundonCardIsVisible"] = "SoundonCardIsVisible";
    response["Lighting"] = "Lighting" ;
    response["WIFI"] = "WIFI";
    response["Logo"] = "Logo";
}

void ServerStarted::GiveDeviceInfo(Request &request, JsonResponse &response)
{
    reader.parse(request.getData(), root );
    Info = root[SettingsHeader];
    qDebug() << QString::fromStdString(Info[0]["OrgCode"].asString());
    qDebug() << QString::fromStdString(Info[0]["OrgName"].asString());
    qDebug() << QString::fromStdString(Info[0]["CamerIsVisible"].asString());
    qDebug() << QString::fromStdString(Info[0]["LogoIsVisible"].asString());
    qDebug() << QString::fromStdString(Info[0]["Lighting"].asString());
    qDebug() << QString::fromStdString(Info[0]["WIFI"].asString());
    qDebug() << QString::fromStdString(Info[0]["TATolerance"].asString());
    qDebug() << QString::fromStdString(Info[0]["DeviceId"].asString());
    qDebug() << QString::fromStdString(Info[0]["RestCode"].asString());
    qDebug() << QString::fromStdString(Info[0]["MoreMealsSelect"].asString());
    qDebug() << QString::fromStdString(Info[0]["DesertSelect"].asString());
    qDebug() << QString::fromStdString(Info[0]["MaxMehman"].asString());
    qDebug() << QString::fromStdString(Info[0]["MaxServeMeals"].asString());
    qDebug() << QString::fromStdString(Info[0]["HolidayOpen"].asString());
    qDebug() << QString::fromStdString(Info[0]["PrevTolerance"].asString());
    qDebug() << QString::fromStdString(Info[0]["AfterTolerance"].asString());
    qDebug() << QString::fromStdString(Info[0]["ServerIP"].asString());
    qDebug() << QString::fromStdString(Info[0]["Port"].asString());
    qDebug() << QString::fromStdString(Info[0]["M_Mode"].asString());
    qDebug() << QString::fromStdString(Info[0]["PlayType"].asString());
    qDebug() << QString::fromStdString(Info[0]["Language"].asString());
    qDebug() << QString::fromStdString(Info[0]["DateType"].asString());
    qDebug() << QString::fromStdString(Info[0]["ListValidationMode"].asString());
}

void ServerStarted::SetUserFingerTemplate(Request &request, JsonResponse &response)
{
    reader.parse(request.getData(), root );
    Template = root[TemplateHeader];
    Emp_no = root[EmpNoHeader];
    QString *imgstring = new QString;
    QByteArray *base64Data = new QByteArray;
    QByteArray *base64Data2 = new QByteArray;
    *imgstring = QString::fromStdString(Template.asString());
    *base64Data = imgstring->toLatin1();
    *base64Data2 = QByteArray::fromBase64(*base64Data) + "\n";
    qDebug() << *base64Data2;
    delete imgstring;
    delete base64Data;
    delete base64Data2;
}


void ServerStarted::SetAlarmTimes(Request &request, JsonResponse &response)
{
    reader.parse(request.getData(), root);
    Emp_no = root[alaramHeader];

}

void ServerStarted::SetActiveTimes(Request &request, JsonResponse &response)
{
    reader.parse(request.getData(), root);
    Emp_no = root[activeHeader];
}

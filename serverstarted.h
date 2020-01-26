#ifndef SERVERSTARTED_H
#define SERVERSTARTED_H

#include <QObject>

#include <WebServer/server.h>
#include <WebServer/jsoncontroller.h>
#include <QDebug>
#include <QtSql>
#include <QSqlQuery>
#include <QJsonValue>
#include <QDateTime>
#include <QThread>

#define TemplateHeader "Template"
#define ResultHeader "Result"
#define ImageHeader "Image"
#define usersHeader "users"
#define StartDateTimeHeader "StartDateTime"
#define EndDateTimeHeader "EndDateTime"
#define DataHeader "Data"
#define InfoHeader "Info"
#define NumberOfDeviceHeader "NumberOfDevice"
#define CountHeader "Count"
#define SettingsHeader "Settings"
#define ResponseHeader "Response"
#define MessageHeader "Message"
#define ErrorCodeHeader "ErrorCode"

#define EmpNoHeader "EmpNo"
#define NameHeader "Name"
#define RoleIdHeader "RoleId"
#define IdentificationMethodHeader "IdentificationMethod"
#define IsActiveHeader "IsActive"
#define NumberOfDatafileHeader "NumberOfDatafile"
#define SubmittedDateHeader "SubmittedDate"
#define DeviceNumHeader "DeviceNum"
#define StatusHeader "Status"
#define DirectionHeader "Direction"

#define alaramHeader "alarms"
#define activeHeader "actives"

enum ErrorCodesFromDevice {
    Successful,
    DataBaseError,
    JsonPolicyError,
    UserIsNotActive,
    UserInfoIsNotDefined,
    WrongImageFormat,
    SetDateTimeError,
    Retry,
    FingerPrintError,
    UnkonownError
};

using namespace std;
using namespace Mongoose;

class ServerStarted : public JsonController
{
public:
     ServerStarted();

     void DateTime(Request &request, JsonResponse &response); // set date time  **
     void SendDeviceInfo(Request &request, JsonResponse &response); // send Device Parmfiles to service  **
     void GiveDeviceInfo(Request &request, JsonResponse &response); // Give Device Parmfiles and Save in Database  **
     void SetUserFingerTemplate(Request &request, JsonResponse &response); // Enroll FingerPrint by Template  **
     void SetAlarmTimes(Request &request, JsonResponse &response);
     void SetActiveTimes(Request &request, JsonResponse &response);
     void Data_Collection_AcoordingTime(Request &request, JsonResponse &response);

     void setup (){
         setPrefix("/Connection");
         addRouteResponse("GET", "/GetDeviceInfo", ServerStarted, SendDeviceInfo, JsonResponse);
         addRouteResponse("POST", "/DateTime", ServerStarted, DateTime, JsonResponse);
         addRouteResponse("POST", "/SetUserFingerTemplate", ServerStarted, SetUserFingerTemplate, JsonResponse);
         addRouteResponse("POST", "/Collection/AccordingTime", ServerStarted, Data_Collection_AcoordingTime, JsonResponse);
         addRouteResponse("POST", "/SetDeviceInfo", ServerStarted, GiveDeviceInfo, JsonResponse);
         addRouteResponse("POST", "/SetAlarmTimes", ServerStarted, SetAlarmTimes, JsonResponse);
         addRouteResponse("POST", "/SetActiveTimes", ServerStarted, SetActiveTimes, JsonResponse);

        }
private:
     QDateTime datetime;
     Json::Value root;
     Json::Reader reader;
     Json::Value Image;
     Json::Value Emp_no;
     Json::Value DateTimeValue;
     Json::Value StartDateTime;
     Json::Value EndDateTime;
     Json::Value Info;
     Json::Value Template;
};

#endif // SERVERSTARTED_H

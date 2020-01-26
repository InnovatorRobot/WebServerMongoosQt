#include <sstream>
#include <json/json.h>
#include "jsonresponse.h"
using namespace std;

namespace Mongoose
{
    JsonResponse::JsonResponse()
        : humanReadable(false)
    {
    }

    string JsonResponse::getBody()
    {
        if (humanReadable) {
            Json::StyledWriter writer;
            string test = writer.write(*this);

            return writer.write(*this);
        } else {
            Json::FastWriter writer;
            string test = writer.write(*this);

            return writer.write(*this);
        }
    }

    void JsonResponse::setHuman(bool human)
    {
        humanReadable = human;
    }
}

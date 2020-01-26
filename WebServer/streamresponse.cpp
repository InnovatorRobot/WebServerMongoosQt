#include <sstream>
#include "streamresponse.h"

using namespace std;

namespace Mongoose
{
    string StreamResponse::getBody()
    {
        return this->str();
    }
}

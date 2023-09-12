#ifndef _CAM_H_
#define _CAM_H_

#include "map.h"

namespace CAM{
    void openCam();
    void closeCam();
    void capture_n_identity();
}
using namespace CAM;

#endif
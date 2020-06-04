/********************************************************************************
Copyright (c) 2016, TRACLabs, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
       this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.

    3. Neither the name of the copyright holder nor the names of its
       contributors may be used to endorse or promote products derived from
       this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
********************************************************************************/

#ifndef UTIL_HPP
#define UTIL_HPP

#include <ros/package.h>
#include <ros/ros.h>

#include <assert.h>
#include <iostream>
#include <kdl/frames.hpp>
#include <sstream>

#include <geometry_msgs/Pose.h>

namespace util {

std::vector<std::string> &split(const std::string &s, char delim,
                                std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

std::vector<float> quaternionToRPY(float x, float y, float z, float w);
std::vector<float> RPYToQuaternion(float rr, float rp, float ry);

std::vector<float> poseMsgToVector(geometry_msgs::Pose msg);
geometry_msgs::Pose vectorToPoseMsg(std::vector<float> pose);

std::string resolvePackagePath(const std::string &str);
}

#endif // UTIL_HPP

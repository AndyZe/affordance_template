#!/usr/bin/env python

import rospy
import ihmc_msgs
from ihmc_msgs.msg import * # import all in the ihmc_msgs.msg
import time
import sys

if __name__ == '__main__':
    robot_side = 0
    if len(sys.argv) == 1:
        print "One argument for which side, optional 7 additional arguments for joint control"
        sys.exit()
    elif len(sys.argv) == 2:
        print "Sending arms to all 0 positions"
    elif len(sys.argv) != 9:
        print "Please start with either 0 or 7 arguments"
        sys.exit()
    robot_side = int(sys.argv[1])
    pub = rospy.Publisher("/ihmc_ros/valkyrie/control/arm_trajectory", ArmTrajectoryRosMessage, queue_size = 1)
    rospy.init_node ("DemoArmMover")
    msg = ArmTrajectoryRosMessage( joint_trajectory_messages = [
        OneDoFJointTrajectoryRosMessage(trajectory_points = [ TrajectoryPoint1DRosMessage(time= 1.9, position = 0.0, velocity = 0.0)]), 
        OneDoFJointTrajectoryRosMessage(trajectory_points = [ TrajectoryPoint1DRosMessage(time= 1.9, position = 0.0, velocity = 0.0)]), 
        OneDoFJointTrajectoryRosMessage(trajectory_points = [ TrajectoryPoint1DRosMessage(time= 1.9, position = 0.0, velocity = 0.0)]), 
        OneDoFJointTrajectoryRosMessage(trajectory_points = [ TrajectoryPoint1DRosMessage(time= 1.9, position = 0.0, velocity = 0.0)]), 
        OneDoFJointTrajectoryRosMessage(trajectory_points = [ TrajectoryPoint1DRosMessage(time= 1.9, position = 0.0, velocity = 0.0)]), 
        OneDoFJointTrajectoryRosMessage(trajectory_points = [ TrajectoryPoint1DRosMessage(time= 1.9, position = 0.0, velocity = 0.0)]), 
        OneDoFJointTrajectoryRosMessage(trajectory_points = [ TrajectoryPoint1DRosMessage(time= 1.9, position = 0.0, velocity = 0.0)]) 
        ], execution_mode = 0, unique_id = 1) #rospy.Time.now().secs)
    msg.robot_side = robot_side    
    if len(sys.argv) == 9:
        for i in range(2,9):
            msg.joint_trajectory_messages[i-2].trajectory_points[0].position = float(sys.argv[i])
    print msg
    pub.publish(msg)
    time.sleep(1)  
